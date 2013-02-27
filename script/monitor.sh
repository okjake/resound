#!/bin/bash

# This script will keep the audio player running
# Make sure that the player binary is in your PATH and that the config file define is set below

CONFIG_FILE="../example/config.yml"

until resound --config "$CONFIG_FILE"; do
  echo "Resound crashed, exit code $?." >&2
  sleep 1
done