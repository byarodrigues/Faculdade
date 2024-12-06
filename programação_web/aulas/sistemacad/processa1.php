<html>
<head>
    <title>Página de Acesso 1</title>
</head>
<body>
    <form action="processa2.php" 
        method="post"
        name="frmParte2" 
        enctype="multipart/form-data">
    Parte 2<br>
    Idade:
    <input type="date" name="txtIdade"/>
    <input type="hidden" 
            value="
                            <?php
                                echo ($_POST('txtNome'))
                            ?>"
            name="txtNome"/>
    <br>
    <input type="submit" 
            value="Próximo" 
            name="btnProximo">
    </form>
</body>
</html>