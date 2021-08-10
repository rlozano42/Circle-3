FROM       alpine:3.12.1

RUN        apk --no-cache update && apk --no-cache upgrade
RUN        apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/community --allow-untrusted --no-cache

# EXPOSE     4999

ENTRYPOINT /usr/bin/telegraf;