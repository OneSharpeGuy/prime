<?php
/**
 * @file
 * singout_feature_export.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function singout_feature_export_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function singout_feature_export_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function singout_feature_export_node_info() {
  $items = array(
    'singout' => array(
      'name' => t('Singout'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_registration_state().
 */
function singout_feature_export_default_registration_state() {
  $items = array();
  $items['cancelled'] = entity_import('registration_state', '{
    "name" : "cancelled",
    "label" : "cancelled",
    "description" : "Registration was cancelled",
    "default_state" : "0",
    "active" : "1",
    "show_on_form" : "0",
    "weight" : "-11",
    "rdf_mapping" : [  ]
  }');
  $items['maybe'] = entity_import('registration_state', '{
    "name" : "maybe",
    "label" : "Maybe",
    "description" : "I would like to attend, but I can\\u0027t commit yet",
    "default_state" : "0",
    "active" : "1",
    "show_on_form" : "1",
    "weight" : "-13",
    "rdf_mapping" : [  ]
  }');
  $items['no'] = entity_import('registration_state', '{
    "name" : "no",
    "label" : "No",
    "description" : "I Will NOT attend",
    "default_state" : "1",
    "active" : "1",
    "show_on_form" : "1",
    "weight" : "-14",
    "rdf_mapping" : [  ]
  }');
  $items['probably_not'] = entity_import('registration_state', '{
    "name" : "probably_not",
    "label" : "Unlikely",
    "description" : "Most likely will not attend",
    "default_state" : "0",
    "active" : "1",
    "show_on_form" : "1",
    "weight" : "-12",
    "rdf_mapping" : [  ]
  }');
  $items['yes'] = entity_import('registration_state', '{
    "name" : "yes",
    "label" : "Yes",
    "description" : "I will attend",
    "default_state" : "0",
    "active" : "1",
    "show_on_form" : "1",
    "weight" : "-15",
    "rdf_mapping" : [  ]
  }');
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function singout_feature_export_default_registration_type() {
  $items = array();
  $items['singout'] = entity_import('registration_type', '{
    "name" : "singout",
    "label" : "singout",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : [  ]
  }');
  return $items;
}
