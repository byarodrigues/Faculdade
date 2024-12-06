<?php
session_start();

$login = $_POST['txtLogin'];
$senha = $_POST['txtSenha'];

if ($login=='Ciniro' && $senha=='1234')
{
	$_SESSION['login'] = $login;
	header('location:pagina1.php');
}
else
{
	$_SESSION['erro'] = 'Login ou senha incorretos';
	header('location:index.php');
}
?>