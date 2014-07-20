<?php
/**
 * @file
 * singout_feature_export.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function singout_feature_export_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access singout agglomerate'.
  $permissions['access singout agglomerate'] = array(
    'name' => 'access singout agglomerate',
    'roles' => array(),
    'module' => 'osg_singout_summary',
  );

  // Exported permission: 'send singout notifications'.
  $permissions['send singout notifications'] = array(
    'name' => 'send singout notifications',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'osg_singout_notifier',
  );

  // Exported permission: 'view nonrespondents'.
  $permissions['view nonrespondents'] = array(
    'name' => 'view nonrespondents',
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
    ),
    'module' => 'osg_singout_summary',
  );

  // Exported permission: 'view singout detail'.
  $permissions['view singout detail'] = array(
    'name' => 'view singout detail',
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
    ),
    'module' => 'osg_singout_summary',
  );

  // Exported permission: 'view singout summary'.
  $permissions['view singout summary'] = array(
    'name' => 'view singout summary',
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
    ),
    'module' => 'osg_singout_summary',
  );

  return $permissions;
}
