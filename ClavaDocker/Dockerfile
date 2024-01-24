# Use Ubuntu 22.10 as base image
FROM ubuntu:22.04

# Update the system and install necessary packages
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y openjdk-17-jdk
RUN apt-get install -y gcc
RUN apt-get install -y wget
RUN apt-get install -y unzip

# Check versions
RUN java -version
RUN gcc --version

# Set the working directory
WORKDIR /app

# Install Clava
ADD https://specs.fe.up.pt/tools/clava/clava-update .
RUN chmod +x clava-update
RUN ./clava-update
RUN ./clava --version

# Copy the test files
COPY edgedetect ./edgedetect

# Run Clava with the test files (no JS/aspects)
RUN ./clava -p edgedetect

