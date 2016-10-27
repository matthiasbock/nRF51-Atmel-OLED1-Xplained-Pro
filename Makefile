
#
# Toolchain
#
TOOLCHAIN_PATH   = /usr/bin/
TOOLCHAIN_PREFIX = arm-none-eabi
AS      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-as
CC      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-gcc
LD      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-ld
OBJCOPY = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objcopy
OBJDUMP = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objdump
SIZE    = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-size
GDB     = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-gdb

newlib  = /usr/lib/arm-none-eabi/newlib/libc.a

#
# Compiler and Linker
#
CFLAGS += -DNRF51
CFLAGS += -std=gnu99 -Wall -Wextra -g
CFLAGS += -mcpu=cortex-m0 -mthumb -mabi=aapcs -mfloat-abi=soft
CFLAGS += -ffreestanding
# keep every function in separate section. This will allow linker to dump unused functions
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin --short-enums
CFLAGS += -I nordic/arm/
CFLAGS += -I nordic/
CFLAGS += -I nordic/sdk/nrf51822/Include
CFLAGS += -I sdk/
CFLAGS += -I sdk/arduino/
CFLAGS += -I gfx/
CFLAGS += -I ssd1306/

# TODO: auto-detect chip revision
CHIP_REVISION = aa

# without SoftDevice:
LINKER_SCRIPT = sdk/linker/nrf51-blank-xx$(CHIP_REVISION).ld
# with SoftDevice:
#LINKER_SCRIPT = sdk/linker/nrf51-s110-xx$(CHIP_REVISION).ld

LDFLAGS += -T $(LINKER_SCRIPT)
LDFLAGS += -L /usr/lib/gcc/arm-none-eabi/4.8/armv6-m/
LDFLAGS += -L /usr/lib/arm-none-eabi/newlib/armv6-m/
LDFLAGS += -static
LDFLAGS += -nostartfiles -nostdlib
LDFLAGS += --start-group
LDFLAGS += -lgcc

# required for semihosting 
CFLAGS  += --specs=rdimon.specs
LDFLAGS += -lrdimon 

# filename of used softdevice (full path)  
SOFTDEVICE = nordic/softdevice/s110_nrf51822_7.3.0_softdevice.hex


#
# Build targets
#
all: demo_buttons.elf demo_oled.elf

clean:
	rm -f *.o *.elf

%.o: %.c %s
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

demo_buttons.elf: sdk/nrf51_startup.o nordic/system_nrf51.o demo_buttons.o
	$(LD) $(LDFLAGS) $^ -o $@

demo_oled.elf: sdk/nrf51_startup.o nordic/system_nrf51.o nordic/nrf_delay.o sdk/arduino/Arduino.o gfx/glcdfont.o ssd1306.o bcd.o oled.o demo_oled.o
	$(LD) $(LDFLAGS) $^ -o $@

.PHONY: debug
include sdk/debug/Makefile

