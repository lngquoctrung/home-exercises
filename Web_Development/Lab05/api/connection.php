<?php

    header('Access-Control-Allow-Origin: *');
    header('Content-Type: application/json');
    
    $host = 'localhost';
    $port = '3307';
    $dbName = 'students';
    $username = 'root';
    $password = '';

    try{
        // $dbCon = new PDO("mysql:host=".$host.";port=3307;dbname=".$dbName, $username, $password, array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
        $dbCon = new PDO("mysql:host={$host};port={$port};dbname={$dbName}", $username, $password, array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
    }
    catch(PDOException $ex){
        die(json_encode(array('status' => false, 'data' => 'Unable to connect: ' . $ex->getMessage())));
    }

?>