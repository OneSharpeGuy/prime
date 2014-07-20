<?php
/**
 * @file
 * singout_feature_export.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function singout_feature_export_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-performance-registration_register:register
  $menu_links['menu-performance-registration_register:register'] = array(
    'menu_name' => 'menu-performance-registration',
    'link_path' => 'register',
    'router_path' => 'register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-performance-registration_register:register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-quickies_pending-members:pending-members
  $menu_links['menu-quickies_pending-members:pending-members'] = array(
    'menu_name' => 'menu-quickies',
    'link_path' => 'pending-members',
    'router_path' => 'pending-members',
    'link_title' => 'Pending Members',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-quickies_pending-members:pending-members',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-singout_all-registrations:osg/singout/listall
  $menu_links['menu-singout_all-registrations:osg/singout/listall'] = array(
    'menu_name' => 'menu-singout',
    'link_path' => 'osg/singout/listall',
    'router_path' => 'osg/singout/listall',
    'link_title' => 'All Registrations',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-singout_all-registrations:osg/singout/listall',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-singout_google-calendar-sync:osg/singout/sync
  $menu_links['menu-singout_google-calendar-sync:osg/singout/sync'] = array(
    'menu_name' => 'menu-singout',
    'link_path' => 'osg/singout/sync',
    'router_path' => 'osg/singout/sync',
    'link_title' => 'Google Calendar Sync',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-singout_google-calendar-sync:osg/singout/sync',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-singout_pending-members:pending-members
  $menu_links['menu-singout_pending-members:pending-members'] = array(
    'menu_name' => 'menu-singout',
    'link_path' => 'pending-members',
    'router_path' => 'pending-members',
    'link_title' => 'Pending Members',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-singout_pending-members:pending-members',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-singout_register:register
  $menu_links['menu-singout_register:register'] = array(
    'menu_name' => 'menu-singout',
    'link_path' => 'register',
    'router_path' => 'register',
    'link_title' => 'Register',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-singout_register:register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Registrations');
  t('Google Calendar Sync');
  t('Pending Members');
  t('Register');


  return $menu_links;
}
