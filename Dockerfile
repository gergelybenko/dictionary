# Start from a debian base image
FROM debian:latest
LABEL Description="Development environment"

ENV HOME /usr/local
RUN mkdir -p ${HOME}

# Update packages and set up gcc/g++ and other packages
RUN apt update -y && apt install -y
RUN apt -y install  wget \
                    build-essential \
                    cmake \
                    libpq-dev \
                    postgresql-server-dev-all

# Download boost
RUN cd ${HOME} && \
    wget -T 20 https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz -O boost.tar.gz && \
    mkdir boost && tar -C boost -xvf boost.tar.gz --strip-components 1 && \
    cd ./boost && \
    ./bootstrap.sh && \
    ./b2 install

# Download SOCI
RUN cd ${HOME} && \
    wget -T 20 https://github.com/SOCI/soci/archive/refs/tags/v4.0.3.tar.gz -O soci.tar.gz && \
    mkdir soci && tar -C soci -xvf soci.tar.gz --strip-components 1 && \
    cd soci && \
    cmake       -G "Unix Makefiles" \
                -S . -B . \
                -DSOCI_CXX11=ON \
                -DWITH_BOOST=ON \
                -DWITH_POSTGRESQL=ON \
                -DPOSTGRESQL_INCLUDE_DIR=$(pg_config --includedir) \
                -DPOSTGRESQL_LIBRARY=$(pg_config --libdir)/libpq.so \
                -DWITH_DB2=OFF \
                -DWITH_FIREBIRD=OFF \
                -DWITH_MYSQL=OFF \
                -DWITH_OBDC=OFF \
                -DWITH_ORACLE=OFF && \
    make && make install

CMD [ "/bin/bash" ]