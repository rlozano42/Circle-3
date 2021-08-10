FROM alpine:3.12

RUN apk update

RUN         apk add php7 php7-mysqli php7-json php7-mbstring php7-fpm nginx

RUN         adduser -D -g 'www' www && \
		    mkdir -p /run/nginx www

RUN		    chown -R www:www /var/lib/nginx && \
		    chown -R www:www /www

RUN         wget http://wordpress.org/latest.tar.gz \
            && tar -xzvf latest.tar.gz \
            && rm latest.tar.gz \
            && mv /wordpress /www/

COPY        wp-config.php /www/
COPY 	    nginx.conf /etc/nginx/nginx.conf

EXPOSE      5050

ENTRYPOINT  php-fpm7  && \
            /usr/sbin/nginx -g "daemon off;"