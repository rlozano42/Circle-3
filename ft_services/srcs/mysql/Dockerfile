FROM alpine:3.12

COPY init_file ./
COPY my.cnf  ./
COPY wordpress.sql ./
COPY execute.sh ./

RUN apk update 
RUN apk add mysql mysql-client

RUN 	mkdir -p /run/mysqld &&\ 
        chown -R root:root /run/mysqld &&\
        mv /my.cnf /etc/

RUN 	chmod 777 execute.sh

EXPOSE 3306

CMD  sh execute.sh