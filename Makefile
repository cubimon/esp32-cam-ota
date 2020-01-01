PROJECT_NAME := esp32-cam-ota
ESP32_IP := 192.168.4.1

include $(IDF_PATH)/make/project.mk

ota: app
	curl ${ESP32_IP}:8032 --data-binary @- < build/${PROJECT_NAME}.bin

