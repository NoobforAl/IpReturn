FROM archlinux:latest

WORKDIR /app

COPY . /app/

RUN pacman -Syyu --noconfirm

RUN pacman -S make gcc ulfius --noconfirm

EXPOSE 8080

CMD [ "make" ]
