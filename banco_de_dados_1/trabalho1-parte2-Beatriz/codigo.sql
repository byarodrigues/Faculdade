-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`cadastro_fabricante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_fabricante` (
  `nome_fabricante` VARCHAR(50) NULL,
  `codigo_fabricante` INT NOT NULL,
  `equipamento` VARCHAR(50) NULL,
  `cadastro_funcionario_nome_funcionario` VARCHAR(50) NOT NULL,
  `cadastro_fornecedor_nome_fornecedor` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`codigo_fabricante`, `cadastro_fornecedor_nome_fornecedor`),
  INDEX `fk_cadastro_fabricante_cadastro_funcionario1_idx` (`cadastro_funcionario_nome_funcionario` ASC) VISIBLE,
  INDEX `fk_cadastro_fabricante_cadastro_fornecedor1_idx` (`cadastro_fornecedor_nome_fornecedor` ASC) VISIBLE,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_funcionario1`
    FOREIGN KEY (`cadastro_funcionario_nome_funcionario`)
    REFERENCES `mydb`.`cadastro_funcionario` (`nome_funcionario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_fornecedor1`
    FOREIGN KEY (`cadastro_fornecedor_nome_fornecedor`)
    REFERENCES `mydb`.`cadastro_fornecedor` (`nome_fornecedor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_fabricante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_fabricante` (
  `nome_fabricante` VARCHAR(50) NULL,
  `codigo_fabricante` INT NOT NULL,
  `equipamento` VARCHAR(50) NULL,
  `cadastro_funcionario_nome_funcionario` VARCHAR(50) NOT NULL,
  `cadastro_fornecedor_nome_fornecedor` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`codigo_fabricante`, `cadastro_fornecedor_nome_fornecedor`),
  INDEX `fk_cadastro_fabricante_cadastro_funcionario1_idx` (`cadastro_funcionario_nome_funcionario` ASC) VISIBLE,
  INDEX `fk_cadastro_fabricante_cadastro_fornecedor1_idx` (`cadastro_fornecedor_nome_fornecedor` ASC) VISIBLE,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_funcionario1`
    FOREIGN KEY (`cadastro_funcionario_nome_funcionario`)
    REFERENCES `mydb`.`cadastro_funcionario` (`nome_funcionario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_fornecedor1`
    FOREIGN KEY (`cadastro_fornecedor_nome_fornecedor`)
    REFERENCES `mydb`.`cadastro_fornecedor` (`nome_fornecedor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`user` (
  `username` VARCHAR(16) NOT NULL,
  `email` VARCHAR(255) NULL,
  `password` VARCHAR(32) NOT NULL,
  `create_time` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`compra_epi`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`compra_epi` (
  `nome_epi` VARCHAR(50) NOT NULL,
  `preco_epi` INT NULL,
  `codigo_epi` INT NULL,
  PRIMARY KEY (`nome_epi`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`consulta_epi`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`consulta_epi` (
  `codigo_epi` INT NOT NULL,
  `nome_epi` VARCHAR(50) NULL,
  PRIMARY KEY (`codigo_epi`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_epi`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_epi` (
  `codigo_epi` INT NOT NULL,
  `nome_epi` VARCHAR(45) NULL,
  `compra_epi_nome_epi` VARCHAR(50) NOT NULL,
  `consulta_epi_codigo_epi` INT NOT NULL,
  PRIMARY KEY (`codigo_epi`),
  INDEX `fk_cadastro_epi_compra_epi1_idx` (`compra_epi_nome_epi` ASC) VISIBLE,
  INDEX `fk_cadastro_epi_consulta_epi1_idx` (`consulta_epi_codigo_epi` ASC) VISIBLE,
  CONSTRAINT `fk_cadastro_epi_compra_epi1`
    FOREIGN KEY (`compra_epi_nome_epi`)
    REFERENCES `mydb`.`compra_epi` (`nome_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_epi_consulta_epi1`
    FOREIGN KEY (`consulta_epi_codigo_epi`)
    REFERENCES `mydb`.`consulta_epi` (`codigo_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_fornecedor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_fornecedor` (
  `nome_fornecedor` VARCHAR(50) NOT NULL,
  `codigo_fornecedor` INT NULL,
  `equipamento` VARCHAR(50) NULL,
  `endereco` VARCHAR(50) NULL,
  PRIMARY KEY (`nome_fornecedor`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`entrega_epi`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`entrega_epi` (
  `nome_epi` VARCHAR(50) NOT NULL,
  `codigo_epi` INT NULL,
  `dia` DATE NULL,
  `cadastro_fornecedor_nome_fornecedor` VARCHAR(50) NOT NULL,
  `consulta_epi_codigo_epi` INT NOT NULL,
  PRIMARY KEY (`nome_epi`),
  INDEX `fk_entrega_epi_cadastro_fornecedor1_idx` (`cadastro_fornecedor_nome_fornecedor` ASC) VISIBLE,
  INDEX `fk_entrega_epi_consulta_epi1_idx` (`consulta_epi_codigo_epi` ASC) VISIBLE,
  CONSTRAINT `fk_entrega_epi_cadastro_fornecedor1`
    FOREIGN KEY (`cadastro_fornecedor_nome_fornecedor`)
    REFERENCES `mydb`.`cadastro_fornecedor` (`nome_fornecedor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_entrega_epi_consulta_epi1`
    FOREIGN KEY (`consulta_epi_codigo_epi`)
    REFERENCES `mydb`.`consulta_epi` (`codigo_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_funcionario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_funcionario` (
  `nome_funcionario` VARCHAR(50) NOT NULL,
  `codigo_funcionario` INT NULL,
  `endereco` VARCHAR(50) NULL,
  `cpf` INT NULL,
  `funcao` VARCHAR(50) NULL,
  `compra_epi_nome_epi` VARCHAR(50) NOT NULL,
  `cadastro_epi_codigo_epi` INT NOT NULL,
  `consulta_epi_codigo_epi` INT NOT NULL,
  `entrega_epi_nome_epi` VARCHAR(50) NOT NULL,
  `cadastro_fornecedor_nome_fornecedor` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`nome_funcionario`),
  INDEX `fk_cadastro_funcionario_compra_epi_idx` (`compra_epi_nome_epi` ASC) VISIBLE,
  INDEX `fk_cadastro_funcionario_cadastro_epi1_idx` (`cadastro_epi_codigo_epi` ASC) VISIBLE,
  INDEX `fk_cadastro_funcionario_consulta_epi1_idx` (`consulta_epi_codigo_epi` ASC) VISIBLE,
  INDEX `fk_cadastro_funcionario_entrega_epi1_idx` (`entrega_epi_nome_epi` ASC) VISIBLE,
  INDEX `fk_cadastro_funcionario_cadastro_fornecedor1_idx` (`cadastro_fornecedor_nome_fornecedor` ASC) VISIBLE,
  CONSTRAINT `fk_cadastro_funcionario_compra_epi`
    FOREIGN KEY (`compra_epi_nome_epi`)
    REFERENCES `mydb`.`compra_epi` (`nome_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_funcionario_cadastro_epi1`
    FOREIGN KEY (`cadastro_epi_codigo_epi`)
    REFERENCES `mydb`.`cadastro_epi` (`codigo_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_funcionario_consulta_epi1`
    FOREIGN KEY (`consulta_epi_codigo_epi`)
    REFERENCES `mydb`.`consulta_epi` (`codigo_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_funcionario_entrega_epi1`
    FOREIGN KEY (`entrega_epi_nome_epi`)
    REFERENCES `mydb`.`entrega_epi` (`nome_epi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_funcionario_cadastro_fornecedor1`
    FOREIGN KEY (`cadastro_fornecedor_nome_fornecedor`)
    REFERENCES `mydb`.`cadastro_fornecedor` (`nome_fornecedor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_fabricante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_fabricante` (
  `nome_fabricante` VARCHAR(50) NULL,
  `codigo_fabricante` INT NOT NULL,
  `equipamento` VARCHAR(50) NULL,
  `cadastro_funcionario_nome_funcionario` VARCHAR(50) NOT NULL,
  `cadastro_fornecedor_nome_fornecedor` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`codigo_fabricante`, `cadastro_fornecedor_nome_fornecedor`),
  INDEX `fk_cadastro_fabricante_cadastro_funcionario1_idx` (`cadastro_funcionario_nome_funcionario` ASC) VISIBLE,
  INDEX `fk_cadastro_fabricante_cadastro_fornecedor1_idx` (`cadastro_fornecedor_nome_fornecedor` ASC) VISIBLE,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_funcionario1`
    FOREIGN KEY (`cadastro_funcionario_nome_funcionario`)
    REFERENCES `mydb`.`cadastro_funcionario` (`nome_funcionario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_cadastro_fabricante_cadastro_fornecedor1`
    FOREIGN KEY (`cadastro_fornecedor_nome_fornecedor`)
    REFERENCES `mydb`.`cadastro_fornecedor` (`nome_fornecedor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`compra_epi_copy1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`compra_epi_copy1` (
  `nome_epi` VARCHAR(50) NOT NULL,
  `preco_epi` INT NULL,
  `codigo_epi` INT NULL,
  PRIMARY KEY (`nome_epi`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cadastro_epi_copy1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cadastro_epi_copy1` (
  `nome_epi` VARCHAR(50) NOT NULL,
  `preco_epi` INT NULL,
  `codigo_epi` INT NULL,
  PRIMARY KEY (`nome_epi`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
