<?php
$login = $_POST['txtLogin'];
$senha = $_POST['txtSenha'];

if ($login=='Ciniro' && $senha=='1234')
{
	session_start();
	$_SESSION['login'] = $login;
	header('location:pagina1.php');
}
else
{
	session_start();
	$_SESSION['erro'] = 'Login ou senha incorretos';
	header('location:index.php');
}
?>