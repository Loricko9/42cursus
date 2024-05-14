#!/bin/bash

#MYSQL_ROOT_PASSWORD=somewordpress
#MYSQL_DATABASE=wordpress
#MYSQL_USER=wordpress
#MYSQL_PASSWORD=wordpress

service mysql start
echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;" > setup.sql
echo "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_PASSWORD';" >> setup.sql
echo "GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" >> setup.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" >> setup.sql
mysql -p$MYSQL_ROOT_PASSWORD < setup.sql

kill $(cat /var/run/mysqld/mysqld.pid)

exec mysqld_safe
