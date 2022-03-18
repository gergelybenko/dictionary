FROM gcc:latest

COPY ./src /usr/src/dictionary

WORKDIR /usr/src/dictionary

RUN g++ -o dictionary main.cpp

CMD [ "./dictionary" ]