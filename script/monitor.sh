#!/bin/bash

# This script will keep the audio player running no matter what
# Make sure that the player binary is in your PATH and that the config file define is set below

CONFIG_FILE="config.yml"

until playq --config "$CONFIG_FILE"; do
  echo "Audio player crashed, exit code $?." >&2
  sleep 1
done