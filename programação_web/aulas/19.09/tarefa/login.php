<?php
session_start();

$login = $_POST['txtLogin'];
$senha = $_POST['txtSenha'];

if ($login=='bya' && $senha=='123')
{
	$_SESSION['login'] = $login;
	header('location:menu.php');
}
else
{
	$_SESSION['erro'] = 'Login ou senha incorretos';
	header('location:index.php');
}
?>