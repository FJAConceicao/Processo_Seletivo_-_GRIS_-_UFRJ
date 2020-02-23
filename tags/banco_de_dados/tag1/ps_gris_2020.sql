-- Universidade Federal do Rio de Janeiro
-- Processo Seletivo GRIS 2020
-- Avaliador: Arthur Castro
-- TAG: Criar banco de dados do Processo seletivo do GRIS 2020
-- Candidato: Felipe de Jesus
------------------------------------------------------------------

-- criando banco de dados
CREATE DATABASE PSGRIS2020;

-- ativando banco de dados
USE PSGRIS2020;

-- criando tabelas do banco dados do psGRIS2020
CREATE TABLE Candidato (
	candidatoID int NOT NULL,
	nome_completo varchar(255),
	dre varchar(9),
	email varchar(255).
	nome_de_usuario_telegram varchar(32),
	PRIMARY KEY (CandidatoID)
);

CREATE TABLE Tags (
	tagID int NOT NULL,
	nome_da_tag varchar(100),
	assunto varchar(1000),
	objetivo varchar(500),
	dicas varchar(500),
	data_de_entrega date,
	PRIMARY KEY (tagID)
);

CREATE TABLE Avaliacao (
	avaliacaoID NOT NULL,
	candidatoID int NOT NULL,
	tagID int NOT NULL,
	nota int(2) NOT NULL,
	PRIMARY KEY (avaliacaoID),
	FOREIGN KEY (candidatoID) REFERENCES Candidato(candidatoID),
	FOREIGN KEY (tagID) REFERENCES Tags(tagID)
);
