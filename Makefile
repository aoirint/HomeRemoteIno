FQBN = arduino:avr:nano

# Unix, maybe ttyACM#
# Windows, COM#
PORT = /dev/ttyUSB0

BAUDRATE = 38400

.PHONY: compile
compile:
	arduino-cli compile \
		-b "$(FQBN)"

.PHONY: upload
upload:
	arduino-cli upload -v \
		-b "$(FQBN)" \
		-p "$(PORT)"

.PHONY: screen
screen:
	screen "$(PORT)" "$(BAUDRATE)"
