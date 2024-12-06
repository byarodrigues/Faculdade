<?php
$nome = $_POST['txtLogin'];

echo ('
<html>
    <head>
        <title> Página de Acesso </title>
    </head>
    <body>
        <h1> Seja bem-vindo ' . $nome . ' </h1>
    </body>
</html>');
?>
