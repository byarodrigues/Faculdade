<html>
    <head>
        <title>
            Formulario
        </title>
        <script>

        </script>
        <style>

        </style>
    </head>
    <body>
        <form name="frmCadastro" action="processa.php" method="post" enctype="multipart/form-data">
            <input type="hidden" name="hddCodigo" value="345678" />
            <table border="1px" width="300px" cellspacing="4px" cellpadding="5px"> 
                <tr>
                    <td colspan="2"> Cadastro de Clientes </td>
                </tr>
                <tr>
                    <td width="15%"> C&oacute;digo:</td>
                    <td>
                        <input 
                            type="text" 
                            name="txtCodigo" 
                            value="123456" 
                            readonly="true" 
                        />
                    </td>
                </tr>
                <tr>
                    <td width="15%"> Nome:</td>
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
                    <td width="15%"> Senha:</td>
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
                    <td width="15%"> Email:</td>
                    <td>
                        <input 
                            type="text" 
                            name="txtEmail" 
                            value=""
                            placeholder="Insira aqui seu email"
                            size="100"
                            maxlength="80" 
                        />
                    </td>
                </tr>
                <tr>
                    <td width="15%"> Data de nascimento:</td>
                    <td>
                        <input 
                            type="date" 
                            name="txtDataNasc"
                        />
                    </td>
                </tr>
                <tr>
                    <td width="15%"> Carregue sua foto:</td>
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
                        <input type="radio" name="rdbRenda" id="rdbMenosQue800" value="1" checked="true" />
                        <label for="rdbMenosQue800">Menos que R$800,00 </label><br>
                        <input type="radio" name="rdbRenda" id="rdbMaisQue800" value="2" />
                        <label for="rdbMaisQue800">Mais que R$800,00 </label><br>
                    </td>
                </tr>
                <tr>
                    <td width="15%">Quais modelos de carro voc&ecirc; deseja:</td>
                    <td>
                        <input type="checkbox" name="chkCarros" id="chkFusca" value="fusca" />
                        <label for="chxFusca">Fusca</label>
                        <br>
                        <input type="checkbox" name="chkCarros" id="chkUno" value="uno" />
                        <label for="chxUno">Uno</label>
                        <br>
                        <input type="checkbox" name="chkCarros" id="chkDelrey" value="delrey" />
                        <label for="chxDelrey">Delrey</label>
                        <br>
                        <input type="checkbox" name="chkCarros" id="chkOutro" value="outro" />
                        <label for="chxOutro">Outro</label>
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
                    <td width="15%">Voc&ecirc; gosta quanto de refrigerante?</td>
                    <td>
                        <select name="slcRefrigerante" size="1">
                            <option value="muito" selected="true">Muito</option>
                            <option value="medio">Mais ou menos</option>
                            <option value="pouco">Pouco</option>
                    </td>
                </tr>
                <tr>
                    <td width="15%">Qual sua faixa et&aacute;ria?</td>
                    <td>
                        <select name="slcRefrigerante" size="4">
                            <option value="1">Menos que 18</option>
                            <option value="2">Entre 18 e 50</option>
                            <option value="3">Mais que 50</option>
                            <option value="4"selected="true">N&atilde;o desejo informar</option>
                        </td>
                </tr>
                <tr>
                    <td width="15%">Selecione os itens para a sua lista de compras:</td>
                    <td>
                        <select name="slcListaDeCompra[]" size="9" multiple="true">
                            <optgroup label="Alimentos">
                                <option value="1.1">Biscoito recheado</option>
                                <option value="1.2">Farinha de tapioca</option>
                            </optgroup>
                            <optgroup label="Higiene">
                                <option value="2.1">Esponja de Bob Esponja</option>
                                <option value="2.2">Leite de Rosas</option>
                            </optgroup>
                            <optgroup label="A&ccedil;ougue">
                                <option value="3.1">Pelota</option>
                                <option value="3.2">Carne</option>
                            </optgroup>
                        </td>
                </tr>
            </table>
            <input 
                type="submit" 
                value="Enviar" 
                name="btnEnviar">
        </form>
    </body>
</html>