<?php
	//verifica a existencia do usuario
	session_start();
	if (!isset($_SESSION['login']))
	{
		header('location:index.php');
	}
	
	//-------------------------------------------------------------------
	//captura os dados que o usuario inseriu na pagina de login
	$codigo = $_POST['hddCodigo'];
	$nome = $_POST['txtNome'];
	$login = $_POST['txtLogin'];
	$senha = $_POST['txtSenha'];
	$perfil = $_POST['slcPerfil'];
	$foto = $_FILES['txtArquivo'];
	
	//executando a conexao
    require('conexao.php');
	
	//executando insercao de usuario no banco
	$sql = "UPDATE tb_usuario SET nome_usuario='".$nome."',
								  senha_usuario='".$senha."',
								  id_perfil=".$perfil."
								  WHERE id_usuario=".$codigo.";";
								  
	move_uploaded_file($foto["tmp_name"], 'imagens/'.$login.'.jpg');
	
	$resultado = mysqli_query($conexao, $sql);

	//avaliando o resultado
	if ($resultado == true)
	{
		header('location:lista_usuario.php');
	}
	else
	{
		echo 'Problema ao alterar o registro no banco de dados <br>';
		echo 'O erro que aconteceu foi este: ' . mysqli_error($conexao);
		echo '<a href="menu.php"> VOLTAR </a>';
	}
?>