<?php
$branchName = "nabil-dev";
switch($argv[1]){
	case 'save':
		shell_exec("git add .");
		shell_exec('git commit -m "'.$argv[2].'"');
	break;
	case 'send':
		shell_exec("git push origin ".$branchName);
	break;
	case 'sync':
	shell_exec("git checkout master");
	shell_exec("git pull");
	shell_exec("git branch -d ".$branchName);
	shell_exec("git checkout -b ".$branchName);
	break;
}