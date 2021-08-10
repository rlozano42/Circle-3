#!/bin/bash
eval $(minikube docker-env)
kubectl delete -f mysql.yaml
kubectl delete -f grafana.yaml
kubectl delete -f telegraf.yaml
kubectl delete -f telegraf.yaml
docker image rm -f influxdb
docker image rm -f grafana
docker image rm -f telegraf
docker system prune -f
#kubectl delete pv pvc-a3f5b685-bc9c-40a6-ab16-b7637df9c035