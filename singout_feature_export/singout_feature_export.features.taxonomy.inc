<?php
/**
 * @file
 * singout_feature_export.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function singout_feature_export_taxonomy_default_vocabularies() {
  return array(
    'voice_part' => array(
      'name' => 'Voice Part',
      'machine_name' => 'voice_part',
      'description' => 'Primary Voice Parts',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
