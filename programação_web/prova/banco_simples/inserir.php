<?php
	//executando a conexao
	$bd = mysqli_connect('localhost','root','','bd_conexao');
	
	//executando a consulta
	$sql = 'insert into tb_pessoas(nome_pessoa, idade_pessoa) 
	        values ("Joana Maria", 23);';
	
	$resultado = mysqli_query($bd, $sql) or die(mysqli_error());
	
	//avaliando o resultado
	if ($resultado == true)
	{
		echo 'Registro inserido com sucesso';
	}
	else
	{
		echo 'Problema ao inserir o registro no banco de dados';
	}
?>