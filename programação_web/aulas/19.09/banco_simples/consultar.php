<?php
	//executando a conexao e selecionando o banco
	$bd = mysqli_connect('localhost','root','','bd_conexao');

	//executando a consulta
	$sql = 'select * from tb_pessoas;';
		
	$tabela = mysqli_query($bd, $sql) or die(mysqli_error());

	//exibindo os dados
	while ($linha = mysqli_fetch_row($tabela))
	{
		echo 'Id: ' . $linha[0] . '<br>';
		echo 'Nome: ' . $linha[1] . '<br>';
		echo 'Idade: ' . $linha[2] . '<br>';
		echo '<br><br>';
	}
?>