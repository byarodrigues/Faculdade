-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 31-Ago-2023 às 20:52
-- Versão do servidor: 10.4.28-MariaDB
-- versão do PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `bd_filmes`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_categoria`
--

CREATE TABLE `tb_categoria` (
  `id_categoria` int(11) NOT NULL,
  `nome_categoria` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_categoria`
--

INSERT INTO `tb_categoria` (`id_categoria`, `nome_categoria`) VALUES
(1, 'Romance'),
(2, 'Aventura'),
(3, 'Infantil'),
(4, 'Terror'),
(5, 'Drama'),
(6, 'Suspense');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_filme`
--

CREATE TABLE `tb_filme` (
  `id_filme` int(11) NOT NULL,
  `nome_filme` varchar(500) NOT NULL,
  `duracao_filme` int(11) NOT NULL,
  `preco_filme` float NOT NULL,
  `nota_filme` int(11) NOT NULL,
  `id_produtora` int(11) NOT NULL,
  `id_categoria` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_filme`
--

INSERT INTO `tb_filme` (`id_filme`, `nome_filme`, `duracao_filme`, `preco_filme`, `nota_filme`, `id_produtora`, `id_categoria`) VALUES
(1, 'MadMax: Estrada da Fúria', 130, 14.9, 5, 1, 2),
(2, 'Os Banshees', 150, 12.9, 5, 2, 5),
(3, 'Dangal', 210, 0.9, 4, 7, 5),
(4, 'Shreek', 120, 30, 4, 5, 3),
(5, 'A viagem de Chihiro', 110, 5, 5, 6, 3),
(6, 'Shark Boy e Lava Girl', 80, 1.99, 1, 3, 3),
(7, 'Titanic', 160, 50, 2, 3, 1),
(8, 'O Senhor dos Anéis: A Sociedade do Anel', 135, 22.9, 4, 2, 2),
(9, 'O Exorcista', 90, 5.5, 3, 1, 4),
(10, 'A Orfã', 120, 10.5, 3, 2, 6),
(11, 'Sinais', 100, 10.9, 5, 4, 6);

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_produtora`
--

CREATE TABLE `tb_produtora` (
  `id_produtora` int(11) NOT NULL,
  `nome_produtora` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_produtora`
--

INSERT INTO `tb_produtora` (`id_produtora`, `nome_produtora`) VALUES
(1, 'TGM'),
(2, 'New Line '),
(3, 'Universal Studios'),
(4, 'Paramount'),
(5, 'Pixar'),
(6, 'Guibli'),
(7, 'Bollywood');

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `tb_categoria`
--
ALTER TABLE `tb_categoria`
  ADD PRIMARY KEY (`id_categoria`);

--
-- Índices para tabela `tb_filme`
--
ALTER TABLE `tb_filme`
  ADD PRIMARY KEY (`id_filme`),
  ADD KEY `id_produtora` (`id_produtora`),
  ADD KEY `id_categoria` (`id_categoria`);

--
-- Índices para tabela `tb_produtora`
--
ALTER TABLE `tb_produtora`
  ADD PRIMARY KEY (`id_produtora`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `tb_categoria`
--
ALTER TABLE `tb_categoria`
  MODIFY `id_categoria` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de tabela `tb_filme`
--
ALTER TABLE `tb_filme`
  MODIFY `id_filme` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT de tabela `tb_produtora`
--
ALTER TABLE `tb_produtora`
  MODIFY `id_produtora` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Restrições para despejos de tabelas
--

--
-- Limitadores para a tabela `tb_filme`
--
ALTER TABLE `tb_filme`
  ADD CONSTRAINT `tb_filme_ibfk_1` FOREIGN KEY (`id_produtora`) REFERENCES `tb_produtora` (`id_produtora`),
  ADD CONSTRAINT `tb_filme_ibfk_2` FOREIGN KEY (`id_categoria`) REFERENCES `tb_categoria` (`id_categoria`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
