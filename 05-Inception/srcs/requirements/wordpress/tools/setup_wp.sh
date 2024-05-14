#!/bin/bash

if [ ! -f "/var/www/wordpress/wp-config.php" ]; then
	# download & install CLI for edit 2nd page of config
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	sleep 10
	# add data for 1st page of config
	sed -i "s/votre_nom_de_bdd/$MYSQL_DATABASE/" /var/www/wordpress/wp-config-sample.php
	sed -i "s/votre_utilisateur_de_bdd/$WORDPRESS_DB_USER/" /var/www/wordpress/wp-config-sample.php
	sed -i "s/votre_mdp_de_bdd/$WORDPRESS_DB_PASSWORD/" /var/www/wordpress/wp-config-sample.php
	sed -i "s/localhost/$WORDPRESS_DB_HOST/" /var/www/wordpress/wp-config-sample.php

	# rename file for apply change
	mv /var/www/wordpress/wp-config-sample.php /var/www/wordpress/wp-config.php

	# add data for 2nd page of config
	wp core install --allow-root --path=/var/www/wordpress --title='lle-saul_WEB' --admin_email='lle-saul@42-perpignan.fr' --admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASS --url=localhost

	wp theme install vertice --path=/var/www/wordpress --activate --allow-root

 	# create 2nd user
 	wp user create --allow-root --path=/var/www/wordpress $WORDPRESS_USER test@test.fr --user_pass=$WORDPRESS_USER_PASS --role=subscriber
fi

if [ ! -f "/run/php" ]; then
	mkdir -p /run/php
fi

/usr/sbin/php-fpm7.3 -F
