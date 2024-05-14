FROM debian:buster
# update & install php
RUN	apt update && \
	apt upgrade -y && \
	apt install wget php7.3 php-fpm php-mysql mariadb-client -y
# download wordpress
RUN wget https://fr.wordpress.org/wordpress-6.5.3-fr_FR.tar.gz -P / && \
	mkdir -p /var/www && \
	tar -xvf /wordpress-6.5.3-fr_FR.tar.gz -C /var/www && \
	rm -rf /wordpress-6.5.3-fr_FR.tar.gz
# get read acces on wordpress
RUN chown -R root:root /var/www/wordpress
RUN chown -R www-data:www-data /var/www/wordpress
# copy conf file & setup.sh
COPY conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
COPY tools/setup_wp.sh /setup_wp.sh
EXPOSE 9000
ENTRYPOINT [ "/setup_wp.sh" ]