FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt update && apt install -y \
    build-essential \
    cmake \
    git \
    # Dependencies for raylib
    pkg-config \ 
    libasound2-dev \
    mesa-common-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    xorg-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcursor-dev \
    libxinerama-dev \
    wget

# Download and build raylib from source
WORKDIR /tmp
RUN git clone --depth 1 --branch 5.0 https://github.com/raysan5/raylib.git && \
    cd raylib && \
    mkdir build && \
    cd build && \
    cmake .. -DBUILD_EXAMPLES=OFF -DBUILD_GAMES=OFF && \
    make -j$(nproc) && \
    make install && \
    cd / && \
    rm -rf /tmp/raylib
