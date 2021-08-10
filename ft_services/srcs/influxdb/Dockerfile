FROM alpine:3.12


FROM alpine:3.12

# Instalar 
RUN apk --no-cache update && apk --no-cache upgrade && \
    apk add influxdb

# Copiar configuracion 
RUN mkdir -p /etc/influxdb
COPY influxdb.conf /etc/influxdb/influxdb.conf

#expose ports
EXPOSE 8086

ENTRYPOINT influxd