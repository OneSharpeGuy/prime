<?php
/**
 * @file
 * singout_feature_export.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function singout_feature_export_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML (No WYSIWYG).
  $formats['full_html_no_wysiwyg_'] = array(
    'format' => 'full_html_no_wysiwyg_',
    'name' => 'Full HTML (No WYSIWYG)',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'php_code' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
