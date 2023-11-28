FROM ubuntu:latest
LABEL authors="miaohaochu"
RUN apt-get update && apt-get install -y cmake g++ gdb

