-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema controle_epis
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema controle_epis
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `controle_epis` DEFAULT CHARACTER SET utf8 ;
USE `controle_epis` ;

-- -----------------------------------------------------
-- Table `controle_epis`.`programa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `controle_epis`.`programa` (
  `senha` INT NOT NULL,
  PRIMARY KEY (`senha`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `controle_epis`.`funcionario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `controle_epis`.`funcionario` (
  `funcao` VARCHAR(50) NULL,
  `nome` VARCHAR(45) NULL,
  `cpf` VARCHAR(45) NULL,
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `endereco` VARCHAR(45) NULL,
  `programa_senha` INT NOT NULL,
  PRIMARY KEY (`codigo`),
  INDEX `fk_funcionario_programa1_idx` (`programa_senha` ASC),
  CONSTRAINT `fk_funcionario_programa1`
    FOREIGN KEY (`programa_senha`)
    REFERENCES `controle_epis`.`programa` (`senha`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `controle_epis`.`enfermeiro`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `controle_epis`.`enfermeiro` (
  `cre` INT NOT NULL,
  `funcionario_codigo` INT NOT NULL,
  PRIMARY KEY (`cre`),
  INDEX `fk_enfermeiro_funcionario1_idx` (`funcionario_codigo` ASC),
  CONSTRAINT `fk_enfermeiro_funcionario1`
    FOREIGN KEY (`funcionario_codigo`)
    REFERENCES `controle_epis`.`funcionario` (`codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `controle_epis`.`medico`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `controle_epis`.`medico` (
  `crm` INT NOT NULL,
  `funcionario_codigo` INT NOT NULL,
  INDEX `fk_medico_funcionario1_idx` (`funcionario_codigo` ASC),
  CONSTRAINT `fk_medico_funcionario1`
    FOREIGN KEY (`funcionario_codigo`)
    REFERENCES `controle_epis`.`funcionario` (`codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `controle_epis`.`epi`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `controle_epis`.`epi` (
  `nome` VARCHAR(50) NOT NULL,
  `codigo` INT NOT NULL,
  `preco` INT NOT NULL,
  `programa_senha` INT NOT NULL,
  PRIMARY KEY (`codigo`),
  INDEX `fk_epi_programa1_idx` (`programa_senha` ASC),
  CONSTRAINT `fk_epi_programa1`
    FOREIGN KEY (`programa_senha`)
    REFERENCES `controle_epis`.`programa` (`senha`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
