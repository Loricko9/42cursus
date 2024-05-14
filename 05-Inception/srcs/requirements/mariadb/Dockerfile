FROM debian:buster
# install mariaDB
RUN apt update && \
	apt upgrade -y && \
	apt install mariadb-server -y
# copy file conf mariadb
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
EXPOSE 3306
# copy & exec script for setup database & user
COPY tools/setup.sh /setup.sh
ENTRYPOINT ["/setup.sh"]
