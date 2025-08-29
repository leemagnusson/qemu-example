CC = $(GCC_PATH)arm-none-eabi-g++

CFLAGS = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -specs=rdimon.specs -std=c++23 -g -O0

main.elf: main.cpp
	$(CC) $(CFLAGS) -o main.elf main.cpp

run: main.elf
	qemu-arm -cpu cortex-m4 main.elf

.EXTRA_PREREQS = Makefile
