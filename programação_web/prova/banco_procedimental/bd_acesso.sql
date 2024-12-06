-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: 13-Jun-2017 às 15:45
-- Versão do servidor: 10.1.21-MariaDB
-- PHP Version: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bd_acesso`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_perfil`
--

CREATE TABLE `tb_perfil` (
  `id_perfil` int(11) NOT NULL,
  `nome_perfil` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tb_perfil`
--

INSERT INTO `tb_perfil` (`id_perfil`, `nome_perfil`) VALUES
(1, 'Administrador'),
(2, 'Usuario Comum');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_usuario`
--

CREATE TABLE `tb_usuario` (
  `id_usuario` int(11) NOT NULL,
  `nome_usuario` varchar(200) NOT NULL,
  `login_usuario` varchar(10) NOT NULL,
  `senha_usuario` varchar(10) NOT NULL,
  `id_perfil` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tb_usuario`
--

INSERT INTO `tb_usuario` (`id_usuario`, `nome_usuario`, `login_usuario`, `senha_usuario`, `id_perfil`) VALUES
(1, 'Janaina', 'admin', 'admin', 1),
(8, 'Thallys Youtuber', 'youtube1', 'youtube1', 1),
(9, 'Sarah Carolina', 'saca', 'saca', 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tb_perfil`
--
ALTER TABLE `tb_perfil`
  ADD PRIMARY KEY (`id_perfil`);

--
-- Indexes for table `tb_usuario`
--
ALTER TABLE `tb_usuario`
  ADD PRIMARY KEY (`id_usuario`),
  ADD KEY `perfil_FKusuario` (`id_perfil`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tb_perfil`
--
ALTER TABLE `tb_perfil`
  MODIFY `id_perfil` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `tb_usuario`
--
ALTER TABLE `tb_usuario`
  MODIFY `id_usuario` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- Constraints for dumped tables
--

--
-- Limitadores para a tabela `tb_usuario`
--
ALTER TABLE `tb_usuario`
  ADD CONSTRAINT `perfil_FKusuario` FOREIGN KEY (`id_perfil`) REFERENCES `tb_perfil` (`id_perfil`) ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
