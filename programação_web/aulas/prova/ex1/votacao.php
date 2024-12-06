<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Votação</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Tela de Votação</h1>
        <form id="votacaoForm">
            <label for="numero">Digite o número do candidato:</label>
            <input type="text" id="numero" name="numero" required>

            <!-- Adicione a tag <img> para exibir a foto do candidato -->
            <img id="imgCandidato" src="" alt="Foto do Candidato">

            <label for="votoBranco">Voto em Branco:</label>
            <input type="checkbox" id="votoBranco" name="votoBranco">

            <button type="button" onclick="enviarVoto()">Votar</button>
        </form>
    </div>

    <script>
        function enviarVoto() {
            var numeroCandidato = document.getElementById('numero').value;

            // Lógica para verificar se o candidato existe no banco de dados e obter o caminho da foto
            // (Você precisa implementar essa lógica no lado do servidor usando AJAX ou Fetch API)

            // Exemplo de como obter a foto do candidato e exibi-la
            var caminhoFoto = "caminho/para/foto" + numeroCandidato + ".jpg";

            // Exibir a foto (substitua "imgCandidato" pelo ID da sua tag de imagem)
            document.getElementById('imgCandidato').src = caminhoFoto;

            // Restante da lógica para enviar o voto
            // ...
        }
    </script>
</body>
</html>
