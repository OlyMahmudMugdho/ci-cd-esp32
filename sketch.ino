name: Compile ESP32-S3 Arduino Sketch

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout Repository
        uses: actions/checkout@v4

      - name: Install Arduino CLI
        run: |
          curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sudo BINDIR=/usr/local/bin sh

      - name: Configure Arduino CLI
        run: |
          arduino-cli config init --overwrite

          arduino-cli config add board_manager.additional_urls \
            https://espressif.github.io/arduino-esp32/package_esp32_index.json

          arduino-cli core update-index
          arduino-cli core install esp32:esp32

      - name: Install Libraries
        run: |
          # Install required libraries here if needed.
          # Example:
          # arduino-cli lib install "PubSubClient"
          echo "No external libraries specified."

      - name: Show Arduino CLI Info
        run: |
          arduino-cli version
          arduino-cli board listall | grep esp32 || true

      - name: Compile Sketch
        run: |
          arduino-cli compile \
            --fqbn esp32:esp32:esp32s3 \
            .
