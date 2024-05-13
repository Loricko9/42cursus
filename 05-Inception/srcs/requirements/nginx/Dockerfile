FROM debian:buster
# install nginx
RUN apt update && \
	apt upgrade -y && \
	apt install nginx -y
# get certificat TSL
RUN mkdir -p /etc/nginx/ssl && \
	apt install openssl -y
# setup certificat
RUN	openssl req -x509 -nodes -out /etc/nginx/ssl/certificat.crt -keyout /etc/nginx/ssl/certificat.key -subj "/C=FR/ST=IDF/L=Perpignan/O=42/OU=42/CN=lle-saul.42.fr/UID=lle-saul"
# setup nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf
# get acces right
RUN	chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html
# start nginx
CMD ["nginx", "-g", "daemon off;"]