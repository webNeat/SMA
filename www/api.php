<?php
require 'bootstrap.php';
$response = 'error';
if(isset($_GET['request'])){
	$request = json_decode($_GET['request'], TRUE);
	if(isset($request['action'])){
		switch($request['action']){
			case 'add_company':

			break;
			case 'add_school':

			break;
			case 'get_world':
				$response = File::getContent('world');
			break;
			case 'act':
				Socket::connect();
				Socket::send('act');
				$response = Socket::receive();
				Socket::close();
			break;
			case 'update_params':
				$data = ValuesToDouble($request['data']);
				File::setFromArray('params',$data);
				Socket::connect();
				Socket::send('update_params');
				$response = Socket::receive();
				Socket::close();
			break;
			case 'get_params':
				$response = File::getContent('params');
			break;
		}
	}
}
echo $response;