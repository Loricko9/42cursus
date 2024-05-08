FROM debian:buster
# update & install php
RUN	apt update && \
	apt upgrade && \
	apt install wget php8.2 php-fpm php-mysql mariadb-client
# download wordpress
RUN wget https://fr.wordpress.org/wordpress-6.5.3-fr_FR.tar.gz -P / && \
	mkdir -p /var/www && \
	tar -xvf /wordpress-6.5.3-fr_FR.tar.gz -C /var/www
# get read acces on wordpress
RUN chown -R root:root /var/www/wordpress
# copy conf file
COPY conf/php-fpm.conf /etc/php/8.2/fpm/php-fpm.conf
VOLUME /var/www/html/wp-content/uploads
CMD ["apache2-foreground"]