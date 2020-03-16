#!/bin/bash

#Vericar se não foi informado uma pasta para compactar
#Caso positivo, mostra mensagem de como usar e sai do programa
if [ ! $# -gt 0 ];
then
	echo "Forma de usar --> $0 endereco/do/diretorio/para/fazer/backup"; exit 0
fi

#Verificar se diretório informado existe
if [ ! -d $1 ];
then
	echo "$1 não existe"; exit 0
fi

#Criar pasta BACKUP existe na home, caso não exista
if [ ! -d ~/BACKUP ];
then
	echo "Criando pasta BACKUP para armazenar backups do programa ..."
	mkdir ~/BACKUP
fi

echo "Removendo backups com mais de 3 dias"
data-atual=`date +%Y-%m-%d`
#for backup in `ls ~/BACKUP/`;

tar -czvf $1`date +%Y/%m/%d`.tar.gz ~/BACKUP
