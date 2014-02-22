<?php
class File {
	private static $directory;

	public static function init($path){
		static::$directory = $path;
	}

	public static function getContent($fileName){
		// TODO : Need to check for errors and Exceptions !
		return fgets(fopen(static::$directory . $fileName . '.json', "r"));
	}

	public static function getAsArray($fileName){
		// TODO : Need to check for errors and Exceptions !
		return json_decode(fgets(fopen(static::$directory . $fileName . '.json', "r")), TRUE);
	}

	public static function setFromArray($fileName, $data){
		// TODO : Need to check for errors and Exceptions !
		fwrite(fopen(static::$directory . $fileName . '.json', "w"), json_encode($data));
	}
	
	public static function setFromJSON($fileName, $data){
		// TODO : Need to check for errors and Exceptions !
		fwrite(fopen(static::$directory . $fileName . '.json', "w"), $data);
	}
	
}