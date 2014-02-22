<?php
class Socket {
	private static $port;
	private static $socket;

	public static function setPort($portNumber){
		static::$port = $portNumber;
	}

	public static function connect(){
		static::$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
		socket_connect(static::$socket, "localhost", static::$port);
	}

	public static function send($text){
		socket_write(static::$socket, $text, strlen($text));
	}

	public static function receive(){
		$data = socket_read(static::$socket, 1024000);		
		return $data; 
	}

	public static function close(){
		socket_close(static::$socket);
	}
}