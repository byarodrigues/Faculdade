<?php
	$conexao = mysqli_connect('localhost', 'root', '');
	mysqli_select_db($conexao, 'bd_agenda');
	
	$sql = 'select * from tb_contato';
	
	$tabela = mysqli_query($conexao, $sql);
	
	echo 
	'<table border="1px">
	<tr>
	  <th>Nome</th>
	  <th>Telefone</th>
	  <th>APAGAR</th>
	  <th>ALTERAR</th>
	</tr>';
	
	while ($linha = mysqli_fetch_row($tabela))
	{
		echo 
		'<tr>
		  <td>'.$linha[1].'</td>
		  <td>'.$linha[2].'</td>
		  <td><a href="apaga.php?cod='.$linha[0].'">Apagar</a></td>
		  <td><a href="altera.php?cod='.$linha[0].'">Alterar</a></td>
		</tr>';
	}
	
	echo '</table>';
?>
<br><br>
<a href="novo.php">CADASTRAR NOVO</a>