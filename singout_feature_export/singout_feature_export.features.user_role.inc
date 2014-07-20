<?php
/**
 * @file
 * singout_feature_export.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function singout_feature_export_user_default_roles() {
  $roles = array();

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 7,
  );

  // Exported role: pending member.
  $roles['pending member'] = array(
    'name' => 'pending member',
    'weight' => 5,
  );

  // Exported role: registrar.
  $roles['registrar'] = array(
    'name' => 'registrar',
    'weight' => 4,
  );

  return $roles;
}
