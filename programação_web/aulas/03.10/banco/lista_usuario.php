<?php
	session_start();
	//averigua se o usuario fez login corretamente no sistema
	//caso nao tenha feito esse bloco de codigo a seguir impede o usuario
	//de acessar a pagina e redireciona o mesmo para a pagina inicial.
	//Caso o usuario tenha feito login corretamente, entao os dados deste
	//usuario serao capturados.
	if (!isset($_SESSION['login']))
	{
		header('location:index.php');
	}
	else
	{
		//faz a conexao com o banco de dados
		require('conexao.php');
		
		//constroi a string sql com base no login ja verificado na pagina de login
		$sql = "SELECT * FROM tb_usuario WHERE login_usuario='" . $_SESSION['login'] . "';";
		
		//vai no banco de dados e executa a consulta sql para buscar os dados do usuario
		//que acabou de fazer login
		$tabela = mysqli_query($conexao, $sql) 
          or die(mysqli_error($conexao));

		//prepara um vetor para receber os dados do usuario que esta no banco
		$dados_usuario = '';

		while ($linha = mysqli_fetch_row($tabela))
		{
			//busca o vetor com as informacoes do usuario e coloca no vetor dados_usuario
			$dados_usuario = $linha;
		}
		
		$cod_usuario = $dados_usuario[0];
	}
?>

<html>
	<head>
		<title>Menu do Sistema</title>
		<style>
			table {
				width:100%;
			}
			table, th, td {
				border: 1px solid black;
				border-collapse: collapse;
			}
			th, td {
				padding: 5px;
				text-align: left;
			}
			table#t01 tr:nth-child(even) {
				background-color: #eee;
			}
			table#t01 tr:nth-child(odd) {
			    background-color:#fff;
			}
			table#t01 th {
				background-color: black;
				color: white;
			}
		</style>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
	</head>
	<body>
		<table>
			<tr style="height:50px">
				<td colspan="2">
					<h1>MENU DO SISTEMA</h1>
				</td>
			</tr>
			<tr style="height:50px">
				<td>
					<img style="height:100px" src="imagens/<?php echo $dados_usuario[2] . '.jpg'; ?>"></img> <br>
					Seja bem vindo(a) <?php echo $dados_usuario[1]; ?>!
				</td>
				<td>
					<a href="logout.php"><img src="imagens/logout.jpg"></img></a>
				</td>
			</tr>
			<tr style="height:400px">
				<td colspan="2">
					<!-- TABELA QUE MOSTRA O MENU DO USUARIO -->
					<table style="height:400px;">
						<tr>
							<td style="width:150px; vertical-align:top;">
								<?php
									if ($dados_usuario[4]==1)
									{
										echo '
											<b>>> USU&Aacute;RIO</b></br>
											<a href="novo_usuario.php">Novo usu&aacute;rio</a><br>
											<a href="lista_usuario.php">Gerenciar Usu&aacute;rios</a><br>											
										';
									}
									else
									{
										echo '
											Voc&ecirc; n&atilde;o tem acesso a nenhum cadastro no momento.										
										';
									}								
								?>
							</td>
							<td style="vertical-align:top; text-align:left;">
								<!-- TABELA QUE LISTA OS USUARIOS CADASTRADOS NO BANCO DE DADOS -->
								<div class="w3-container">
								  <h2>LISTA DE USU&Aacute;RIOS</h2>
									<?php
										//executando a conexao
										require('conexao.php');
										
										//verificar a existencia previa deste login
										$sql = "SELECT * FROM tb_usuario WHERE id_usuario!=".$cod_usuario.";";
										
										//comando php que executa uma string SQL no banco de dados
										//sem isso, sem chance de funcionar.
										$tabela = mysqli_query($conexao, $sql) 
											  or die(mysqli_error($conexao));
									
										echo '<table class="w3-table-all">
												<thead>
													<tr class="w3-red">
														<th>FOTO</th>
														<th>NOME</th>
														<th>LOGIN</th>
														<th>PERFIL</th>
														<th><center>ALTERAR</center></th>
														<th><center>EXCLUIR</center></th>														
													</tr>
												</thead>';
										
										while ($linha = mysqli_fetch_row($tabela))
										{
											
											$sql = "SELECT nome_perfil FROM tb_perfil WHERE id_perfil='".$linha[4]."';";
											$tabela_perfil = mysqli_query($conexao, $sql) 
											  or die(mysqli_error($conexao));
											  
											$nome_perfil = '';
											while ($linha_perfil = mysqli_fetch_row($tabela_perfil))
											{
												$nome_perfil = $linha_perfil[0];
											}
											
											echo '<tr>
													<td><img style="height:150px" src="imagens/'.$linha[2].'.jpg"></img></td>
													<td>'.$linha[1].'</td>
													<td>'.$linha[2].'</td>
													<td>'.$nome_perfil.'</td>
													<td><center><a href="altera_usuario.php?codigo='.$linha[0].'"><img src="imagens/alterar.png"></a></center></td>
													<td><center><a href="exclui_usuario.php?codigo='.$linha[0].'&login='.$linha[2].'"><img src="imagens/excluir.png"></a></center></td>													
												 </tr>';
										}
										
										echo '</table>';
									?>
								</div>								
							</td>
						</tr>
					</table>					
				</td>
			</tr>
		</table>
	</body>
</html>