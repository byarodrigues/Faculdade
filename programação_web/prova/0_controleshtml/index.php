<html>
	<head>
		<title>
			Formulario
		</title>
		<script>
			function Alerta()
			{
				alert("Deu certo!");
			}	

			function Muda()
			{
				
				alert(document.getElementsById("frmCadastro.btnMostrar").value);
			}
			
			function Retorna()
			{
				//frmCadastro.btnMostrar.class = "button button1";
			}
		</script>
		<style>
			.button {
			  background-color: #4CAF50; /* Green */
			  border: none;
			  color: white;
			  padding: 15px 32px;
			  text-align: center;
			  text-decoration: none;
			  display: inline-block;
			  font-size: 16px;
			  margin: 4px 2px;
			  cursor: pointer;
			}

			.button2 {background-color: #008CBA;} /* Blue */
			.button3 {background-color: #f44336;} /* Red */ 
			.button4 {background-color: #e7e7e7; color: black;} /* Gray */ 
			.button5 {background-color: #555555;} /* Black */
		</style>
	</head>
	<body>
		<!-- Abaixo um formulario de cliente -->
		<form name="frmCadastro" action="processa.php" 
		      method="post" enctype="multipart/form-data">
			<input type="hidden" name="hddCodigo" value="345678" />
			<table border="1px" width="300px" cellspacing="4px" cellpadding="5px">
				<tr>
					<td colspan="2"> Cadastro de Cliente </td>
				</tr>
				<tr>
					<td width="15%">C&oacute;digo:</td>
					<td>
						<input 
							type="text" 
							name="txtCodigo" 
							value="12346" 
							readonly="true"
						/>
					</td>
				</tr>
				<tr>
					<td width="15%">Nome:</td>
					<td>
						<input 
							type="text" 
							name="txtNome" 
							value=""
							placeholder="Insira aqui o nome"
							size="100" 
							maxlength="80"
						/>
					</td>
				</tr>
				<tr>
					<td width="15%">Senha:</td>
					<td>
						<input 
							type="password" 
							name="txtSenha" 
							value="123456"
							disabled="true"
						/>
					</td>
				</tr>
				<tr>
					<td width="15%">Email:</td>
					<td><input 
							type="text" 
							name="txtEmail" 
							value="Insira aqui o nome" 
							size="100" 
							maxlength="80"
						/></td>
				</tr>
				<tr>
					<td width="15%">Data de Nascimento:</td>
					<td>
						<input 
							type="date" 
							name="txtDataNasc"
						/>
					</td>
				</tr>
				<tr>
					<td width="15%">Carregue sua foto:</td>
					<td>
						<input 
							type="file" 
							name="txtArquivo"
						/>
					</td>
				</tr>
				<tr>
					<td width="15%">Renda:</td>
					<td>
						<input type="radio" name="rdbRenda" id="rdbMenosQue800" value="1" checked="true"/>
						<label for="rdbMenosQue800">Menos que R$ 800,00</label><br>
						<input type="radio" name="rdbRenda" id="rdbMaisQue800" value="2"/>
						<label for="rdbMaisQue800">Mais que R$ 800,00</label><br>
					</td>
				</tr>
				<tr>
					<td width="15%">Quais modelos de carro voc&ecirc; deseja:</td>
					<td>
						<input type="checkbox" name="chkFusca" value="fusca" /> Fusca
						<br>
						<input type="checkbox" name="chkUno" value="uno" /> Uno
						<br>
						<input type="checkbox" name="chkDelRey" value="delrey" /> Delrey
						<br>
						<input type="checkbox" name="chkOutro" value="outro" checked="true"/> Outro carro
						<br>
					</td>
				</tr>
				<tr>
					<td width="15%">Digite a sua mensagem</td>
					<td>
						<textarea name="txaMensagem" rows="5" cols="60"></textarea>
						<br>
					</td>
				</tr>
				<tr>
					<!-- usando controle select como dropbox -->
					<td width="15%">Voc&ecirc; gosta quanto de refrigerante?</td>
					<td>
						<select name="slcRefrigerante" size="1">
							<option value="muito" selected="true">Muito</option>
							<option value="medio">Mais ou menos</option>
							<option value="pouco">Pouco</option>
						</select>
					</td>
				</tr>
				<tr>
					<!-- usando controle select como listbox simples -->
					<td width="15%">Qual sua faixa et&aacute;ria?</td>
					<td>
						<select name="slcFaixaEtaria" size="4">
							<option value="1">Menos que 18</option>
							<option value="2">Entre 18 e 50</option>
							<option value="3">Mais que 50</option>
							<option value="4" selected="true">N&atilde;o desejo informar</option>
						</select>
					</td>
				</tr>
				<tr>
					<!-- usando controle select como groupbox -->
					<td width="15%">Selecione os itens para sua lista de compras:</td>
					<td>
						<select name="slcListaDeCompras[]" size="9" multiple="true">
							<optgroup label="Alimentos">
								<option value="1.1">Bolacha Recheada</option>
								<option value="1.2">Farinha de Tapioca</option>
							</optgroup>
							<optgroup label="Higiene">
								<option value="2.1">Esponja de Bob Esponja</option>
								<option value="2.2">Leite de Rosas</option>
							</optgroup>
							<optgroup label="A&ccedil;ougue">
								<option value="3.1">Pelota</option>
								<option value="3.2">Carne mo&iacute;da</option>
							</optgroup>
						</select>
					</td>
				</tr>
				<tr>
					<!-- usando controle select como groupbox -->
					<td width="15%">Nos dois grupos, selecione a sua disciplina predileta.</td>
					<td>
						<fieldset>
							<legend>Ensino m&eacute;dio</legend>
							<input type="radio" name="rdbMedio" id="rdbMatematica" value="matematica"/>
							<label for="rdbMatematica">Matem&aacute;tica</label><br>
							<input type="radio" name="rdbMedio" id="rdbHistoria" value="historia"/>
							<label for="rdbHistoria">Hist&oacute;ria</label><br>
						</fieldset>
						<fieldset>
							<legend>Ensino T&eacute;cnico</legend>
							<input type="radio" name="rdbTecnico" id="rdbAlgoritmos" value="algoritmos"/>
							<label for="rdbAlgoritmos">Algoritmos</label><br>
							<input type="radio" name="rdbTecnico" id="rdbWEB2" value="web2"/>
							<label for="rdbWEB2">Programa&ccedil;&atilde;o para Internet II</label><br>
						</fieldset>
					</td>
				</tr>
				<tr>
					<td> Aqui um controle de imagem:</td>
					<td>
						<input type="image" name="imgImagem" src="imagens/foto.bmp" 
						alt="Um cabrita de óculos" value="fotocabrita" />
						<br>
						<label for="imgImagem">Minha cabrita Rebeca dando um rolezinho na roça!</label>
					</td>
				</tr>
				<tr>
					<td colspan="2">
						<table border="1px" width="100%" cellspacing="4px" cellpadding="5px">
							<tr>
								<td align="center">
									<input type="button" 
										   name="btnMostrar"
										   id="btnMostrar"
										   value="Mostrar" 
										   class="button"
										   onclick="Alerta()" 
										   onmouseover="Muda()" 
										   onmouseout="Retorna()"
									/>
								</td>
								<td align="center">
									<input type="reset" name="btnLimpar" value="Limpar"	/>
								</td>
								<td align="center">
									<input type="submit" name="btnSalvar" value="Salvar" />
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</html>