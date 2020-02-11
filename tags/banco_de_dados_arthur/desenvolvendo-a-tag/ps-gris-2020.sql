-- Universidade Federal do Rio de Janeiro
-- Processo Seletivo GRIS 2020
-- Avaliador: Arthur Castro
-- TAG: Criar banco de dados do Processo seletivo do GRIS 2020
------------------------------------------------------------------

-- criando banco de dados
CREATE DATABASE psGRIS2020;

-- ativando banco de dados
USE psGRIS2020;

-- criando tabelas do banco dados do psGRIS2020
CREATE TABLE candidato (
	nome_completo varchar(255),
	dre varchar(9),
	email varchar(255).
	data_de_nascimento date,
	nome_de_usuario_telegram varchar(32),
);

CREATE TABLE tags (
	nome_da_tag varchar(100),
	assunto varchar(1000),
	objetivo varchar(500),
	dicas varchar(500),
	data_de_entrega date,
);

CREATE TABLE avaliacao (
	nome_do_candidato varchar(255),
	tags_feitas,
	nota int(2),
);
