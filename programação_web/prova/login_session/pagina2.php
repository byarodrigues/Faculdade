<?php
session_start();
if (isset($_SESSION['login']))
{
	$mensagem = 'Seja bem vindo ' . $_SESSION['login'] . '! </br> Neste momento voc&ecirc; est&aacute; logado em nosso sistema e na p&aacute;gina 2 </br> <a href="logout.php">SAIR DO SISTEMA</a></br>';
}
else
{
	$mensagem = 'Essa p&aacute;gina &eacute; de acesso restrito! </br> <a href="index.php">VOLTAR</a></br>';
}
?>

<html>
<head>
</head>
<body>
<center>
	<h2>
	<?php
		echo $mensagem;
	?>
	</h2>
	</br></br>
	<a href="pagina1.php">P&aacutegina 1</a>
	<a href="pagina2.php">P&aacutegina 2</a>
	<a href="pagina3.php">P&aacutegina 3</a>
</center>
</body>
</html>