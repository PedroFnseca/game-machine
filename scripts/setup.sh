#!/bin/bash

# To install Allegro 5.2 on Ubuntu 16.04
sudo add-apt-repository ppa:allegro/5.2 -y

# Update package list
sudo apt-get update

# Install allegro
sudo apt-get install -y liballegro*5.2 liballegro*5-dev

# Install allegro ttf
sudo apt-get install -y liballegro-ttf5-dev

# Install allegro image
sudo apt-get install -y liballegro-image5-dev