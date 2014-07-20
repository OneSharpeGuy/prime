<?php
/**
 * @file
 * singout_feature_export.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function singout_feature_export_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-performance-registration.
  $menus['menu-performance-registration'] = array(
    'menu_name' => 'menu-performance-registration',
    'title' => 'Performance Registration',
    'description' => '',
  );
  // Exported menu: menu-quickies.
  $menus['menu-quickies'] = array(
    'menu_name' => 'menu-quickies',
    'title' => 'Quickies',
    'description' => 'Quick Menu for Site Admin',
  );
  // Exported menu: menu-singout.
  $menus['menu-singout'] = array(
    'menu_name' => 'menu-singout',
    'title' => 'Singout',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Performance Registration');
  t('Quick Menu for Site Admin');
  t('Quickies');
  t('Singout');


  return $menus;
}
