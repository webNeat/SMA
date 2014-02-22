<?php

ini_set('display_errors',1);
ini_set('display_startup_errors',1);
error_reporting(-1);
require __DIR__ . '/functions.php';
require __DIR__ . '/classes/file.php';
require __DIR__ . '/classes/socket.php';

File::init('/home/webneat/isima/tps/simulation/SMA/files/');

$config = File::getAsArray('config');
Socket::setPort($config['portNumber']);