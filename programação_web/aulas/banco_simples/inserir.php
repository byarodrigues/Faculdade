<?php
    $bd = mysqli_connect('localhost','root','','bd_conexao');

    $sql = 'insert into tb_pessoas(nome_pessoa, idade_pessoa) 
            values ("Joana maria", 23);';

    $resultado = mysqli_query($bd, $sql) or die(mysqli_error());

    if ($resultado == true)
    {
        echo 'registro inserido com sucesso';
    }
    else
    {
        echo 'Problema ao inseerir o resistro no banco de dados';
    }
?>