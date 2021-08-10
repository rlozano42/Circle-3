FROM alpine:3.12

# Installation of packages
RUN apk update && \
    apk add nginx openssl

RUN adduser -D -g 'www' www && \
    mkdir -p /run/nginx

RUN mkdir /www && \
	chown -R www:www /var/lib/nginx && \
	chown -R www:www /www

RUN openssl req -x509 -nodes -days 365 \
	-newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" \
	-keyout /etc/ssl/private/rlozano.key \
	-out /etc/ssl/certs/rlozano.crt

#archivo de configuración 
COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /www

#exponer los puertos 
EXPOSE 80 443

ENTRYPOINT /usr/sbin/nginx -g "daemon off;"