<?php
    session_start();

    $mensagem = 'Voc&ecirc; j&aacute est&aacute logado no sistema.
                <br>
                <a href="menu.php">Ir para o menu</a>
                <br>
                <a href="logout.php"Sair do sistema</a> <br><br>';
    
    if(!isset($_SESSION['login']))
    {
        $mensagem = '
        <form action="">
            <table>
                <tr>
                    <td colspan="2" align="center">
                        Olá! Sejam bem vindo! Faça seu login
                    </td>
                </tr>
                <tr>
                    <td>
                        Nome:
                    </td>
                    <td>
                        <input type="text" name="txtLogin"/>
                    </td>
                </tr><tr>
                    <td>
                        Senha:
                    </td>
                    <td>
                        <input type="password" name="txtSenha"/>
                    </td>
                </tr>
                <tr>
                    <td>
                        
                    </td>
                    <td>
                        <input type="submit" value="ENVIAR" name="btnEnviar"/>   
                    </td>    
                </tr><tr>
                    <td colspan="2">
                        <a href="esqueci.php">Esqueci minha senha</a>
                    </td>
                </tr>
            </table>
        </form>        
        ';
    }
?>

<html>
    <head>
        <title>Sistema de Cadastro</title>
        <link rel="icon" href="imagens/favicon.png" type="image/x-icon">
    </head>
    <body>
         <?php
            echo $mensagem
         ?>
    </body>
</html>