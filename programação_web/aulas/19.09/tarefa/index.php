<html>
    <head>
        <title>
            Login
        </title>
        <link rel="icon" href="imagens/favicon.png".type="image/x-icon">
    </head>
    <body>
        <?php
            session_start();
            if (isset($_SESSION['login']))
            {
                echo 'Voc&ecirc; j&aacute; est&aacute; logado no sistema.';
                echo '<br>
                        <a href="menu.php"> IR PARA O MENU </a>
                        <br>
                        <a href="logout.php"> SAIR DO SISTEMA </a><br><br>';
            }
            else {
                echo '
                    <form action="login.php" method="post">
                        <table style="width:100%;">
                            <tr>
                                <td colspan="2">
                                    Ol&aacute;! Seja bem vindo! Fa&ccedil;a seu login
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Login:
                                </td>
                                <td>
                                    <input type="text" size="100" name="txtLogin"></input>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                    Senha:
                                </td>
                                <td>
                                    <input type="password" size="100" name="txtSenha"></input>
                                </td>
                            </tr>
                            <tr>
                                <td>
                                </td>
                                <td>
                                    <button type="submit" name="btnEnviar">Enviar</button>
                                </td>
                            </tr>
                            <tr>
                                <td colspan="2">
                                    <a href="esqueci.php"> ESQUECI A SENHA </a>
                                </td>
                            </tr>
                        </table>
                    </form>';
            }
        ?>        
    </body>
</html>
