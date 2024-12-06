<?php
// Conectar ao banco de dados (substitua com suas credenciais)
$servername = "localhost";
$username = "seu_usuario";
$password = "sua_senha";
$dbname = "sistema_votacao";

$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar a conexão
if ($conn->connect_error) {
    die("Falha na conexão com o banco de dados: " . $conn->connect_error);
}

// Obter dados do formulário
$usernameInput = $_POST['username'];
$passwordInput = $_POST['password'];

// Consulta SQL para verificar as credenciais do usuário usando instruções preparadas para segurança
$sql = "SELECT * FROM usuarios WHERE username = ? AND password = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("ss", $usernameInput, $passwordInput);
$stmt->execute();
$result = $stmt->get_result();

// Verificar se há algum resultado
if ($result->num_rows > 0) {
    // Credenciais válidas, redirecionar para a tela de votação
    header("Location: votacao.php");
    exit();
} else {
    // Credenciais inválidas, redirecionar de volta para a tela de login
    header("Location: login.html");
    exit();
}

$stmt->close();
$conn->close();
?>
