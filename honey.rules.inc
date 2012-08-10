<?php

/**
 * Implements hook_rules_data_info().
 */
function honey_rules_data_info() {
  return array(
    'ip' => array(
      'label' => t('IPv4 address'),
      'group' => t('Networking'),
    ),
  );
}

/**
 * Implements hook_rules_event_info().
 */
function honey_rules_event_info() {
  return array(
    'honey_page_visit' => array(
      'label' => t('A non-cached page load'),
      'group' => t('Networking'),
      'variables' => array(
        'ip' => array(
          'label' => t('IPv4 address'),
          'type' => 'ip',
        ),
        'browser' => array(
          'label' => t('HTTP user agent'),
          'type' => 'text',
        ),
        'path' => array(
          'label' => t('Visited path'),
          'type' => 'text',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function honey_rules_action_info() {
  return array(
    'honey_portscan' => array(
      'label' => t('Performs a portscan'),
      'named parameter' => TRUE,
      'group' => t('Networking'),
      'parameter' => array(
        'ip' => array(
          'type' => 'ip',
          'label' => t('IPv4 address'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function honey_rules_condition_info() {
  return array(
    'honey_regexp_match' => array(
      'label' => t('Regular expression match'),
      'group' => t('Networking'),
      'parameter' => array(
        'pattern' => array(
          'label' => t('Regular expression'),
          'type' => 'text',
        ),
        'subject' => array(
          'label' => t('Freeform text to evaluate'),
          'type' => 'text',
        ),
      ),
    ),
  );
}
