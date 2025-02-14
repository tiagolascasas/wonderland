#!/bin/bash

CONTAINER_NAME_PREFIX="ompss_2_at_fpga"

containers=$(docker ps --format "{{.Names}}" | grep "^${CONTAINER_NAME_PREFIX}_")

if [ -z "$containers" ]; then
    echo "No running containers with the prefix '${CONTAINER_NAME_PREFIX}' found."
    exit 1
fi

most_recent_container=$(echo "$containers" | sort -r | head -n 1)

if [ -z "$most_recent_container" ]; then
    echo "Failed to determine the most recent container."
    exit 1
fi

echo "Attaching to the most recent container: $most_recent_container..."
docker exec -it $most_recent_container /bin/bash
