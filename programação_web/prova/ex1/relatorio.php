<?php
// Conectar ao banco de dados (substitua com suas credenciais)
$servername = "seu_servidor";
$username = "seu_usuario";
$password = "sua_senha";
$dbname = "seu_banco_de_dados";

$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar a conexão
if ($conn->connect_error) {
    die("Falha na conexão com o banco de dados: " . $conn->connect_error);
}

// Consulta SQL para obter o relatório de votação
$sqlTotalVotos = "SELECT COUNT(*) as total_votos FROM votos";
$resultTotalVotos = $conn->query($sqlTotalVotos);

$sqlVotosValidos = "SELECT COUNT(*) as votos_validos FROM votos WHERE voto_branco = 0";
$resultVotosValidos = $conn->query($sqlVotosValidos);

$sqlVotosBranco = "SELECT COUNT(*) as votos_branco FROM votos WHERE voto_branco = 1";
$resultVotosBranco = $conn->query($sqlVotosBranco);

// Verificar se há algum resultado
if ($resultTotalVotos->num_rows > 0 && $resultVotosValidos->num_rows > 0 && $resultVotosBranco->num_rows > 0) {
    $rowTotalVotos = $resultTotalVotos->fetch_assoc();
    $rowVotosValidos = $resultVotosValidos->fetch_assoc();
    $rowVotosBranco = $resultVotosBranco->fetch_assoc();

    // Exibir o relatório
    echo "<h1>Relatório de Votação</h1>";
    echo "<p>Número total de votos: " . $rowTotalVotos['total_votos'] . "</p>";
    echo "<p>Votos válidos: " . $rowVotosValidos['votos_validos'] . "</p>";
    echo "<p>Votos em branco: " . $rowVotosBranco['votos_branco'] . "</p>";
} else {
    echo "Erro ao obter dados do relatório.";
}

$conn->close();
?>
