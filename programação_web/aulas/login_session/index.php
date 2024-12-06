<?php
session_start();
$mensagem = 'Fa&ccedil;a seu login no sistema';
$mensagem .= '</br>
	<form action="login.php" method="post">
		Login:<input type="text" name="txtLogin"></input><br>
		Senha:<input type="text" name="txtSenha"></input><br>
		<input type="submit" name="btnEnviar"></input>
	</form>';
	
if (isset($_SESSION['erro']))
{
	$mensagem = 'Seu login ou senha est&aacute; incorreto.';
	$mensagem .= '</br>
	<form action="login.php" method="post">
		Login:<input type="text" name="txtLogin"></input><br>
		Senha:<input type="text" name="txtSenha"></input><br>
		<input type="submit" name="btnEnviar"></input>
	</form>';
}

if (isset($_SESSION['login']))
{
	$mensagem = 'Voc&ecirc; j&aacute; est&aacute logado no sistema.';
	$mensagem .= '</br></br>
	<a href="pagina1.php">P&aacutegina 1</a>
	<a href="pagina2.php">P&aacutegina 2</a>
	<a href="pagina3.php">P&aacutegina 3</a><br><br>
	<a href="logout.php">SAIR DO SISTEMA</a><br><br>';
}

?>

<html>
	<head>
	</head>
	<body>
		<?php echo $mensagem; ?>
	</body>
</html>