<html>
    <head>
        <title>
            Login
        </title>
        <link rel="icon" href="imagens/favicon.png".type="image/x-icon">
    </head> 
    <body>
        <center>
            <h2>
            <?php
                session_start();
                    if (isset($_SESSION['login']))
                    {
                        $mensagem = 'Seja bem vindo(a) ' . $_SESSION['login'] . '! </br> <a href="logout.php">SAIR DO SISTEMA</a></br>';
                    }
                    else
                    {
                        $mensagem = 'Essa p&aacute;gina &eacute; de acesso restrito! </br> <a href="index.php">VOLTAR</a></br>';
                    }
            ?>
        </center>
    </body>
</html>