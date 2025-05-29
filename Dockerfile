FROM ubuntu:20.04

# Устанавливаем переменные окружения для избежания интерактивных запросов
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC

# Устанавливаем tzdata без диалогов
RUN apt-get update && apt-get install -y --no-install-recommends tzdata && \
    ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    dpkg-reconfigure --frontend noninteractive tzdata

# Устанавливаем остальные зависимости
RUN apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libssl-dev \
    ca-certificates \
    libgtest-dev

# Очищаем кэш Hunter
RUN rm -rf /root/.hunter

# Копируем проект
COPY . /print
WORKDIR /print

# Сборка проекта
RUN cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
RUN cmake --build _build
