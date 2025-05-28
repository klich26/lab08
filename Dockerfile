FROM ubuntu:18.04
RUN apt update
RUN apt install -yy gcc g++ cmake
COPY . print/
WORKDIR print
ENV LOG_PATH /home/logs.txt
VOLUME /home/logs
WORKDIR /print/_install/bin
ENTRYPOINT ["./demo"]
