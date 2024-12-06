<?php
session_start();

//captura os dados que o usuario inseriu na pagina de login
$login = $_POST['txtLogin'];
$senha = $_POST['txtSenha'];

//executando a consulta
$sql = "SELECT * FROM tb_usuario WHERE login_usuario='" . $login . "';";

//busca no banco de dados o usuario que esta tentando fazer login
//executando a conexao
require('conexao.php');

$tabela = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));

//exibindo os dados
//enquanto existirem linhas na matriz busque linha por linha e adicione a variavel $linha
$login_bd = '';
$senha_bd = '';

while ($linha = mysqli_fetch_row($tabela))
{
    $login_bd = $linha[2];
    $senha_bd = $linha[3];
}

if ($login==$login_bd && $senha==$senha_bd)
{
	$_SESSION['login'] = $login;
	header('location:menu.php');
}
else
{
	echo 'Login ou Senha incorretos!';
	echo '<br><br>';
	echo '<a href="index.php">Voltar para a principal</a>';
}

?>