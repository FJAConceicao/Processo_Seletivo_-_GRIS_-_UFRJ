-- Universidade Federal do Rio de Janeiro
-- Processo Seletivo GRIS 2020
-- Avaliador: Arthur Castro
-- TAG: Criar banco de dados do Processo seletivo do GRIS 2020
-- Candidato: Felipe de Jesus
------------------------------------------------------------------

CREATE DATABASE PSGRIS2020;

USE PSGRIS2020;

CREATE TABLE Candidato (
	candidatoID int NOT NULL AUTO_INCREMENT,
	nome_completo varchar(255) NOT NULL,
	dre varchar(9) NOT NULL,
	email varchar(255) NOT NULL.
	nome_de_usuario_telegram varchar(32),
	PRIMARY KEY (CandidatoID)
) ENGINE=INNODB;

CREATE TABLE Tags (
	tagID int NOT NULL AUTO_INCREMENT,
	nome_da_tag varchar(100) NOT NULL,
	assunto varchar(1000) NOT NULL,
	objetivo varchar(500),
	dicas varchar(500),
	data_de_entrega date NOT NULL,
	PRIMARY KEY (tagID)
) ENGINE=INNODB;

CREATE TABLE Avaliacao (
	avaliacaoID NOT NULL AUTO_INCREMENT,
	candidatoID int NOT NULL,
	tagID int NOT NULL,
	nota int(2) NOT NULL,

	PRIMARY KEY (avaliacaoID),

	FOREIGN KEY (candidatoID) REFERENCES Candidato(candidatoID),
	FOREIGN KEY (tagID) REFERENCES Tags(tagID)
) ENGINE=INNODB;
