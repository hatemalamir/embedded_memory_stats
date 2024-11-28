#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
# Modified by Hatem Alamir
# Copyright (C) 2024 by Hatem Alamir
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Main make file for assessment 2. Specifies controls for targeted builds
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      1) Host machine
#      2) MSP432 microcontroller 
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
TARGET = c1m2

# Architectures Specific Flags
ifeq ($(PLATFORM),HOST)
	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = -std=c99 -Wall -Werror -g -O0 -D$(PLATFORM)
	CPPFLAGS = -I$(INCLUDES) -MP -MMD -MF $@.dep
	LDFLAGS = -Wl,-Map=$(TARGET).map
else ifeq($(),MSP432)
	CPU = cortex-m4
	ARCH = thumb
	CORE = armv7e-m
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
	LINKER_FILE = msp432p401r.lds

	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = -std=c99 -Wall -Werror -g -O0 -mcpu=$(CPU) -m$(ARCH) -march=$(CORE) -mfloat-abi=hard -mfpu=$(FPU) --specs=$(SPECS) -D$(PLATFORM)
	CPPFLAGS = -I$(INCLUDES) -MP -MMD -MF $@.dep
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
	$(error Invalid value for PLATFORM: $(PLATFORM). Expected HOST or MSP432.)
endif

PPCS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.dep)

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: compile-all
complile_all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
	rm -f $(TARGET).map $(TARGET).out $(OBJS) $(ASMS) $(DEPS) $(DEPS) $(PPCS)
