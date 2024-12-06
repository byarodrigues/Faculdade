<html>
<head>
    <title>Página de Acesso 2</title>
</head>
<body>
    <form action="confirma.php" 
        method="post"
        name="frmParte3" 
        enctype="multipart/form-data">
    Parte 3<br>
    Telefone:
    <input type="number" 
            name="txtTelefone" 
            size="11"/>
    <input type="hidden" 
            value="
                <?php
                    echo ($_POST('txtNome'))
                ?>"
            name="txtNome"/>
    <input type="hidden" 
            value="
                <?php
                    echo ($_POST('txtIdade'))
                ?>"
            name="txtIdade"/>
    <br>
    <input type="submit" 
            value="Próximo" 
            name="btnProximo">
    </form>
</body>
</html>