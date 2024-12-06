<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    echo('Codigo: ' . $_POST['txtCodigo'] . '<br>');
    echo('Nome: ' . $_POST['txtNome'] . '<br>'); 
    echo('Senha: ' . $_POST['txtSenha'] . '<br>');
    echo('Email: ' . $_POST['txtEmail'] . '<br>');
    echo('Data de nascimento: ' . $_POST['txtDataNasc'] . '<br>');

    if (isset($_POST['txtArquivo'])) {
        $file = $_POST['txtArquivo'];
        $filename = $file['name'];
        echo('Arquivo enviado: ' . $filename . '<br>');
    }

    if (isset($_POST['rdbRenda'])) {
        $renda = $_POST['rdbRenda'];
        if ($renda === '1') {
            echo('Renda: Menos que R$800,00 <br>');
        } elseif ($renda === '2') {
            echo('Renda: Mais que R$800,00 <br>');
        } else {
            echo('Escolha de renda não especificada.<br>');
        }
    }

    echo('Carros selecionados: <br>');
    $carros = '';
    if (isset($_POST['chkFusca'])) {
        $carros .= 'Fusca <br>';
    }

    if (isset($_POST['chkUno'])) {
        $carros .= 'Uno <br>';
    }

    if (isset($_POST['chkDelrey'])) {
        $carros .= 'Delrey <br>';
    }

    if (isset($_POST['chkOutro'])) {
        $carros .= 'Outro <br>';
    }

    if ($carros != '') {
        echo $carros;
    } else {
        echo 'Nenhum carro selecionado';
    }
    $texto = htmlentities($_POST['txaMensagem']);
    echo($texto);
}
?>
