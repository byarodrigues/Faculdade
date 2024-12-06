<?php
	//verifica a existencia do usuario
	session_start();
	if (!isset($_SESSION['login']))
	{
		header('location:index.php');
	}

	//-------------------------------------------------------------------
		
	//captura o codigo do usuario
	$codigo = $_GET['codigo'];
	$login = $_GET['login'];

	//abre a conexao com o banco de dados
	require('conexao.php');

	//averigua o perfil do usuario que esta sendo excluido
	//constroi a string sql com base no login ja verificado na pagina de login
	$sql = "SELECT * FROM tb_usuario WHERE id_usuario='" . $codigo . "';";
	
	$tabela = mysqli_query($conexao, $sql) 
	  or die(mysqli_error($conexao));

	$id_perfil = '';

	while ($linha = mysqli_fetch_row($tabela))
	{
		$id_perfil = $linha[4];
	}
	
	//averiguando a existencia de outros administradores para
	//impedir que todos os administradores do sistema sejam excluidos
	
	//verificar a existencia previa deste login
	$sql = "SELECT * FROM tb_usuario WHERE id_perfil=1;";
	
	//comando php que executa uma string SQL no banco de dados
	//sem isso, sem chance de funcionar. Muita atenção GABRIEL!
	$tabela = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));
		  
	//averigua dentro da matrix quantas linhas existem
	$num_linhas = mysqli_num_rows($tabela);
	
	//se exister apenas um admin no banco entao nao permite a exclusao dele
	//pois o sistema tem que ter pelo menos um administrador
	if ($id_perfil==1 && $num_linhas<=1)
	{	
		echo 'Voc&ecirc; n&atilde;o pode ficar sem administradores no sistema!';
		echo '<a href="menu.php"> VOLTAR </a>';
	}
	else
	{
		//criar a string sql que exclui o usuario do banco de dados
		$sql = "DELETE FROM tb_usuario WHERE id_usuario=".$codigo.";";

		//executa o comando DELETE no banco de dados para o usuario que tem
		//aquele codigo especifico
		$resultado = mysqli_query($conexao, $sql);
		
		unlink('imagens/'.$login.'.jpg');
		
		//avaliando o resultado
		if ($resultado == true)
		{
			header('location:lista_usuario.php');
		}
		else
		{
			echo 'Problema ao apagar o registro no banco de dados <br>';
			echo 'O erro que aconteceu foi este: ' . mysqli_error($conexao);
			echo '<a href="menu.php"> VOLTAR </a>';
		}
	}
?>