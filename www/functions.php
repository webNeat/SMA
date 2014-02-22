<?php
function ValuesToDouble($obj, $ignore = array()){
	$new = $obj;
	foreach ($obj as $key => $value) {
		if(!is_array($value) && !is_object($value) && !in_array($key, $ignore)){
			$new[$key] = $value + 0;
		}
	}
	return $new;
}