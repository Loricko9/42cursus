FROM debian:buster
# install mariaDB
RUN apt update && \
	apt upgrade -y && \
	apt install mariadb-server -y
# copy file conf mariadb
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
# copy & exec script for setup database & user
COPY tools/setup.sh /app/setup.sh
ENTRYPOINT ["/app/setup.sh"]
