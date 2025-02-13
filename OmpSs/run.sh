#!/bin/bash

IMAGE="bscpm/ompss_2_at_fpga:latest"
CONTAINER_NAME_PREFIX="ompss_2_at_fpga"
CONTAINER_APPS_DEST="/home/ompss/apps"
CONTAINER_USER="ompss"
CONTAINER_GROUP="ompss"

HOST_APPS_SRC=$(pwd)/apps
HOST_XILINX_TOOLS="/tools/Xilinx"
HOST_XILINX_LIC="/tools/Xilinx/Xilinx.lic"
HOST_PETALINUX="/tools/Xilinx/PetaLinux"

# Generate a unique container name with a timestamp
TIMESTAMP=$(date +"%Y%m%d%H%M%S")
CONTAINER_NAME="${CONTAINER_NAME_PREFIX}_${TIMESTAMP}"

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    echo "Docker is not installed. Please install Docker and try again."
    exit 1
fi

# Start the Docker container as root
echo "Starting Docker container as root with name: $CONTAINER_NAME..."
docker run -itd \
    -v $HOST_XILINX_TOOLS:/opt/xilinx/ \
    -v $HOST_PETALINUX:/opt/petalinux/ \
    -v $HOST_XILINX_LIC:/home/ompss/.Xilinx/Xilinx.lic \
    -e DISPLAY=$DISPLAY \
    -e PATH="/opt/xilinx/Vivado/2024.2/bin/:/opt/xilinx/Vitis_HLS/2024.2/bin/:$PATH" \
    --network host \
    --name $CONTAINER_NAME \
    $IMAGE bash

# Check if the container is running
if ! docker ps --format '{{.Names}}' | grep -q "^${CONTAINER_NAME}$"; then
    echo "Failed to start the container."
    exit 1
fi

# Copy each folder from the host to the container
echo "Copying apps from host to container..."
docker cp $HOST_APPS_SRC $CONTAINER_NAME:$CONTAINER_APPS_DEST

# Check if the copy was successful
if [ $? -eq 0 ]; then
    echo "Folder $HOST_APPS_SRC successfully copied to the container."
else
    echo "Failed to copy folder $HOST_APPS_SRC to the container."
    exit 1
fi

# Adjust permissions inside the container as root
echo "Adjusting permissions inside the container as root..."
docker exec -u root $CONTAINER_NAME chown -R $CONTAINER_USER:$CONTAINER_GROUP $CONTAINER_APPS_DEST
docker exec -u root $CONTAINER_NAME chown $CONTAINER_USER:$CONTAINER_GROUP /home/$CONTAINER_USER/.Xilinx

# Attach to the container interactively as the specified user
echo "Attaching to the container interactively..."
docker exec -it \
    -u $CONTAINER_USER $CONTAINER_NAME /bin/bash
