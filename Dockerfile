# Start from a debian base image
FROM debian:latest

# Update packages and set up gcc/g++ and other packages
RUN apt update -y && apt install -y
RUN apt -y install  wget \
                    build-essential \
                    cmake \
                    libpq-dev \
                    postgresql-server-dev-all

# Download and build libpq++
ARG PQXX=./libpqxx-7.7.0
ARG PQXX_BUILD=${PQXX}/build

RUN wget https://github.com/jtv/libpqxx/archive/refs/tags/7.7.0.tar.gz
RUN tar -xvf 7.7.0.tar.gz
RUN cmake -S ${PQXX} -B ${PQXX_BUILD} && \
        make -C ${PQXX_BUILD} && \
        cmake --install ${PQXX_BUILD}

# Copy source and set up work dir
COPY ./src /usr/src/dictionary
WORKDIR /usr/src/dictionary

CMD [ "/bin/bash" ]