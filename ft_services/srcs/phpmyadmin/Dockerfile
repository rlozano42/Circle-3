FROM alpine:3.12

RUN         apk add phpmyadmin nginx php7 php7-mysqli php7-json php7-mbstring php7-fpm php7-opcache

RUN         adduser -D -g 'www' www && \
		    mkdir -p /run/nginx www &&\
            chown -R www:www /var/lib/nginx && \
		    chown -R www:www /www

RUN		    mv /usr/share/webapps/phpmyadmin /www/

RUN         mkdir  -p  /etc/phpmyadmin/tmp \
            && chmod 777 /etc/phpmyadmin/tmp

COPY        config.inc.php /etc/phpmyadmin/config.inc.php
COPY 	    nginx.conf /etc/nginx/nginx.conf

EXPOSE      5000

#RUN         echo "$cfg['Servers'][$i]['host'] = '$MYSQL_IP';" >> /etc/phpmyadmin/config.inc.php

ENTRYPOINT  php-fpm7 && \
            /usr/sbin/nginx -g "daemon off;"
            