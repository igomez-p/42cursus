
FROM debian:buster

RUN apt update && \
	apt install -y vim nginx php-fpm php-mysql mariadb-server openssl

COPY /srcs/default /etc/nginx/sites-available
COPY /srcs/wordpress /var/www/html/wordpress/
COPY /srcs/phpMyAdmin /var/www/html/phpMyAdmin/
COPY /srcs/init.sql /tmp/
COPY /srcs/wordpress.sql /tmp/
COPY /srcs/index.html /var/www/html/

RUN service mysql start && \
	mysql -u root --password= < /tmp/init.sql && \
	mysql wordpress -u root --password= < /tmp/wordpress.sql && \
	openssl req -x509 -nodes -days 365 \
	-newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" \
	-keyout /etc/ssl/private/default.key \
	-out /etc/ssl/certs/default.crt && \
	openssl dhparam -out /etc/nginx/dhparam.pem 1000

CMD service nginx start && \
	service php7.3-fpm start && \
	service mysql start && \
	bash

