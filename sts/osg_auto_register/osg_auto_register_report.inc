<?php

/**
* Auto Register Report
*/
function osg_auto_register_report($flags = array())
{

    if (!is_array($flags)) {
        $hold = $flags;
        $flags= array();
        $flags[] = $hold;
    }
    if (!isset($flags['force'])) {
        $flags['force'] = TRUE;
    }
    if (osg_auto_register_report_needed()) {

        $query = db_select('osg_auto_registration_request', 'q');
        $query->join('osg_users', 'u', 'q.uid=u.uid');
        $query->join('osg_ical_imported', 'i', 'q.nid = i.nid');
        $query->fields('q', array(
                'label',
                'nid',
                'uid'));
        $query->fields('u', array('user_name','voice_part'));
        $query->fields('i', array('title','start_time_unix'));
        $query->addField('q', 'inserted', 'notification_time');
        $query->addField('q', 'updated', 'response_time');
        $query->addExpression('q.updated-q.inserted', 'lag_time');
        $query->addExpression("CONCAT(u.first_name,' ',u.last_name)", 'display_name');
        $query->isNotNull('q.updated');
        $cutoff = array(':cutoff'=> variable_get('osg_auto_register_report_cutoff', 7));
        $query->where('(FLOOR(UNIX_TIMESTAMP()/86400)- FLOOR(updated/86400))<=:cutoff',
            $cutoff);

        $query->orderBy('q.updated','DESC');
        $query->orderBy('i.start_time_unix','DESC');

        drupal_set_message((string )$query);

        $result = $query->execute();

        $fmt    = "D M jS g:i a";
        /*
        foreach ($result as $row) {
        $columns = array();
        $columns['Response Time'] = date("F j, Y, g:i a",$row['updated']);
        );
        }
        */
        if ($result->rowCount()) {


            $column = array();

            while ($record = $result->fetchAssoc()) {

                $column = array();
                //$column['Notification Time'] = date($fmt, $record['notification_time']);
                $column['Response Time'] = date($fmt,$record['response_time']);
                $hrs      = floor($record['lag_time'] / 3600);
                $mins     = ($record['lag_time'] - $hrs * 3600) / 60;
                $secs     = floor($mins - floor($mins));
                $lag_time = '';
                if ($hrs > 0) {
                    $lag_time = $hrs . _plurality(' hr' ,$hrs);
                }
                if ($mins > 0) {
                    $lag_time = $lag_time . ' ' . floor($mins)._plurality(' min' ,$mins);

                }
                if ($hrs < 1) {
                    if ($secs > 0) {
                        $secs = $secs ._plurality( ' secs',$secs);
                        if ($lag_time > '') {
                            $lag_time = $lag_time . ' ' . $secs;
                        }else {
                            $lag_time = $secs;
                        }
                        $lag_time;
                    }
                }
                $column['Response Delay'] = array(
                    'data' => $lag_time,
                    'align'=> 'right',
                );
                $column["Member's Name"] = $record['display_name'];
                $column['Event Title'] = $record['title'];
                $column['Event Date'] = date($fmt, $record['start_time_unix']);
                $column['Response'] = $record['label'];

                $rows[] = array('data' => $column,'class' => array('table-row'));

            }
            /*
            debug($column);
            debug($rows);
            debug($column);
            debug($rows);
            */
            $data = array(
                'header'    => array_keys($column),
                'rows'      => $rows,
                'attributes' => array(
                    'border'     => 1,
                    'cellspacing'=> 1,
                    'cellpadding'=> 5,
                ),
            );
            $table = theme('table',$data);
        }
        //debug($table);
        osg_auto_register_prep_message($table);
        //drupal_goto(' < front > ');

    }

}


function osg_auto_register_prep_message($info)
{
    global $base_url;
    //debug($data,'$data');
    $key     = 'osg_auto_register';
    $message = array();
    //$separator = md5(time());
    // carriage return type (we use a PHP end of line constant)
    //$eol = PHP_EOL;
    //debug($info);return;
    ////$params['to'] = $record['email'];
    $send_mail = true;

    $recipient = variable_get('osg_auto_register_recipeint',
        'onesharpeguy@gmail.com');

    drupal_set_message("Mail sent to " . $recipient);
    $sender    = variable_get('site_mail', 'admin@example.com');

    $message['subject'] = variable_get('osg_auto_register_email_subject',
        'Auto Register Email');
    $body = variable_get('osg_auto_register_email_message', $info);

    $body = token_replace($body);

    $message['body'][] = $body;
    //$message['headers']['Content - Type'] = 'text / html; charset = UTF - 8; format = flowed; delsp = yes';
    //drupal_mail($module,$key,$to,$language,$params = array(),$from = NULL,$send = TRUE)

    drupal_mail('osg_auto_register', 'osg_auto_register', $recipient,
        language_default(), $message, $sender, $send_mail);
    //debug(array($recipient,$sender,$send_mail));
}


function osg_auto_register_mail($key, & $message, $params)
{
    global $user;
    $options = array('langcode'=> $message['language']->language,                                                                                                                                                                 );


    // Each message is associated with a language, which may or may not be the
    // current user's selected language, depending on the type of e - mail being
    // sent. This $options array is used later in the t() calls for subject
    // and body to ensure the proper translation takes effect.
    if ($key == 'osg_auto_register') {

        $options = array('langcode'=> $message['language']->language,                                                                                                                                                                 );
        $message['body'] = $params['body'];
        $message['subject'] = check_plain($params['subject']);
        //$message['headers']['Content - Type'] = $params['headers']['Content - Type'] ;
        $bcc = variable_get('osg_auto_register_bcc');
        if (is_array($bcc)) {
            if (count($bcc) > 0) {
                $message['headers']['Bcc'] = implode(',', $bcc);
            }
        }
    }
}


function osg_auto_register_config_form($form, & $form_state)
{


    $form['markup'] = array('#markup'=> t('Define parameters for auto registration email report'),                                                                                                                                                 );
    $form['osg_auto_register_blast_unregistered_subject'] = array(
        '#type'         => 'textfield',
        '#title'        => t('Subject'),
        '#required'     => true,
        '#size'         => 128,
        '#desciption'   => t('Subject of non-respondant email blast unregistered'),
        '#default_value'=> variable_get('osg_auto_register_blast_unregistered_subject',
            'Auto-registration Report'),
    );
    $default = 'The following is a list of ShowTime Performances for which the specified uses have auto-registered. ';
    $form['osg_auto_register_blast_unregistered_message_before'] = array(
        '#type'         => 'textarea',
        '#title'        => t('Message (before listing)'),
        '#description'  => t('Text of email (before list of unregistered performances).'),
        '#default_value'=> variable_get('osg_auto_register_blast_unregistered_message_before',
            $default),
        '#required'     => true,
    );
    $form['osg_auto_register_blast_unregistered_message_after'] = array(
        '#type'         => 'textarea',
        '#title'        => t('Addtional Message'),
        '#description'  => t('Text of email (after the list of unregistered performances).'),
        '#default_value'=> variable_get('osg_auto_register_blast_unregistered_message_after'),
    );
    $form['configuration']['osg_auto_register_report_now'] = array(
        '#type'  => 'button',
        '#value' => t('Report Now'),
        '#weight'=> 50,
        //'#executes_submit_callback'=>false,
        '#submit' => array('osg_auto_register_report'),
    );
    return system_settings_form($form);
}
function _plurality($term,$value)
{
    if (floor($value) <> 1) {
        $term = $term.'s';
    }
    return $term;
}


/**
* The form to provide a link to cron.php.
*/
function osg_auto_register_cron_form($form, & $form_state)
{
    $form['status'] = array(
        '#type' => 'fieldset',
        '#title'=> t('Cron status information'),
    );
    $form['status']['intro'] = array(
        '#markup'=> '<div>' . t('The cron example demonstrates hook_cron() and hook_cron_queue_info() processing. If you have administrative privileges you can run cron from this page and see the results.') . '</div>',
    );
    $form['status']['last'] = array(
        '#markup'=> '<div>' . t('osg_auto_register_cron() will next execute the first time cron runs after %time (%seconds seconds from now)' . '</div>',
            array(
                '%time' => date_iso8601(variable_get('osg_auto_register_next_execution', time())),
                '%seconds' => variable_get('osg_auto_register_next_execution', time()) - time(),
            )
        ),
    );

    if (user_access('administer site configuration')) {
        $form['cron_run'] = array(
            '#type' => 'fieldset',
            '#title'=> t('Run cron manually'),
        );
        $form['cron_run']['cron_reset'] = array(
            '#type'         => 'checkbox',
            '#title'        => t("Run osg_auto_register's cron regardless of whether interval has expired."),
            '#default_value'=> FALSE,
        );
        $form['cron_run']['cron_trigger'] = array(
            '#type'  => 'submit',
            '#value' => t('Run cron now'),
            '#submit' => array('osg_auto_register_cron'),
        );
    }

    $form['configuration'] = array(
        '#type' => 'fieldset',
        '#title'=> t('Configuration of osg_auto_register_cron()'),
    );
    $options = array (
        'control'  => 'hours|1|24|6;days;weeks|1|1;',
        'cron_safe'=> true,
        'base'     => 'hours'
    );
    $form['configuration']['osg_auto_register_interval'] = array(
        '#type'         => 'select',
        '#title'        => t('Cron interval'),
        '#description'  => t('Time after which osg_auto_register_cron will respond to a processing request.'),
        '#default_value'=> variable_get('osg_auto_register_interval', 60 * 60),
        '#options'      => osg_api_time_dropdown($options),
    );

    return system_settings_form($form);
}

function osg_auto_register_cron()
{
    $interval = variable_get('osg_auto_register_interval', 300);
    if ((!is_null($interval)) && is_numeric($interval) && ($interval > 0)) {
        drupal_set_message('osg_auto_register_cron');
        // We usually don't want to act every time cron runs (which could be every
        // minute) so keep a time for the next run in a variable.
        //variable_del('osg_auto_register_next_execution');
        $next_exec = (int)variable_get('osg_auto_register_next_execution', 0);
        if (time() >= $next_exec) {

            osg_auto_register_report();
            variable_set('osg_auto_register_next_execution', time() + $interval);
        }
        else {
            $message = 'Next execution ' . $next_exec . ' Time Now ' . time() .
            ' ' . (string )($next_exec - time());
            debug($message);

        }
    }
}
function osg_auto_register_report_needed()
{
    osg_auto_register_housekeeping();
    $needed = FALSE;
    $query     = db_select('osg_auto_registration_request','q');
    $query->addField('q','updated');
    $query->orderBy('updated','DESC');
    $query->range(0,1);

    $mark_time = $query->execute()->fetchField();
    if (is_null($mark_time)) {
        $mark_time = time();
    }
    if ($mark_time > variable_get('osg_auto_register_last_report_time',0)) {
        variable_set('osg_auto_register_last_report_time',$mark_time);
        $needed = TRUE;
    }
    return $needed;
}