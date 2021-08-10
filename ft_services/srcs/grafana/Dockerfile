FROM alpine:3.12

RUN  apk add --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ --allow-untrusted --no-cache grafana

WORKDIR /usr/share/grafana

RUN mkdir -p /usr/share/grafana/dashboards/panels
COPY ./telegraf-datasource.yaml /usr/share/grafana/conf/provisioning/datasources/
COPY ./dashboards/panels.yaml /usr/share/grafana/conf/provisioning/dashboards/
COPY ./dashboards/panels/* /usr/share/grafana/conf/provisioning/dashboards/panels/


EXPOSE 3000

ENTRYPOINT grafana-server