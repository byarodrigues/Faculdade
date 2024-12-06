<?php
    $bd = mysqli_connect('localhost','root','','bd_conexao');

    $sql = 'select * from tb_pessoa;';

    $tabela = mysqli_query($bd, $sql) or die(mysqli_error());

    while ($linha = mysqli_fetch_row($tabela))
    {
        echo 'id: ' . $linha[0] . '<br>';
        echo 'Nome: ' . $linha[1] . '<br>';
        echo 'Idade: ' . $linha[2] . '<br>';
        echo '<br><br>';
    }

?>