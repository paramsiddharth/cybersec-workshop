FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt upgrade -y
RUN apt install -y git build-essential autoconf bison re2c libxml2-dev zlib1g-dev nginx

RUN git clone https://github.com/php/php-src

RUN git -C php-src checkout ab061f95ca966731b1c84cf5b7b20155c0a1c06a
RUN git -C php-src checkout HEAD~1
RUN cd php-src && ./buildconf --force && ./configure --enable-fpm --without-pear && make -j4 && make install

COPY php-fpm.conf /usr/local/etc/
COPY nginx-server.conf /etc/nginx/sites-enabled/default
COPY *.php /var/www/html/
COPY entrypoint.sh /

CMD /entrypoint.sh