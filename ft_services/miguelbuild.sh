#!/bin/bash
eval $(minikube docker-env)
docker build -t influxdb ./srcs/influxdb
docker build -t grafana ./srcs/grafana
docker build -t telegraf ./srcs/telegraf
kubectl apply -f srcs/influxdb.yaml 
kubectl apply -f srcs/grafana.yaml 
kubectl apply -f srcs/telegraf.yaml 
#kubectl delete pv --all