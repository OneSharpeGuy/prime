<?php
/**
 * @file
 * singout_feature_export.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function singout_feature_export_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Alto',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '01f8e28e-758a-4876-b74b-bc6268bb1da0',
    'vocabulary_machine_name' => 'voice_part',
  );
  $terms[] = array(
    'name' => 'N/A',
    'description' => 'Non Member',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '376ded68-cc7a-4ffc-8a9b-ff057898ae6c',
    'vocabulary_machine_name' => 'voice_part',
  );
  $terms[] = array(
    'name' => 'Bass',
    'description' => '',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => '61b2b4d5-17aa-42da-9c01-cdf4d7dec4c4',
    'vocabulary_machine_name' => 'voice_part',
  );
  $terms[] = array(
    'name' => 'Soprano',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '65018eb5-41bb-4c0e-add4-5012ed059470',
    'vocabulary_machine_name' => 'voice_part',
  );
  $terms[] = array(
    'name' => 'Tenor',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => 'c366a545-b596-40ac-ae2c-c0ab08e12c84',
    'vocabulary_machine_name' => 'voice_part',
  );
  return $terms;
}
