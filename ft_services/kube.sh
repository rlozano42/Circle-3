#!/bin/bash
cp -rf ~/.minikube /sgoinfre/students/${USER}
rm -rf ~/.minikube
ln -s /sgoinfre/students/${USER} ~/.minikube