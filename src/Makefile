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
ifneq ($(PLATFORM),)
ifneq ($(PLATFORM),MSP432)
ifneq ($(PLATFORM),HOST)
$(error Invalid value for PLATFORM: $(PLATFORM). Expected HOST or MSP432.)
endif
endif
else
	PLATFORM=HOST
endif

include sources.mk

# Platform Overrides
TARGET = c1m2

# Architectures Specific Flags
ifeq ($(PLATFORM),MSP432)
	# Compiler Flags and Defines
	CPU = cortex-m4
	ARCH = thumb
	CORE = armv7e-m
	FPU = fpv4-sp-d16
	SPECS = nosys.specs
	LINKER_FILE = ../msp432p401r.lds
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	# The instructions were to use -mfloat-abi=hard but that gives an error "FP
	# registers might be clobbered despite 'interrupt' attribute". Switching the
	# flag to "soft" was the quickest and most minimal solution especially that
	# we don't need floating-point operations in this assignment.
	CFLAGS = -std=c99 -Wall -Werror -g -O0 -mcpu=$(CPU) -m$(ARCH) -march=$(CORE) -mfloat-abi=soft -mfpu=$(FPU) --specs=$(SPECS) -D$(PLATFORM)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
	CC = gcc
	LD = collect2
	CFLAGS = -std=c99 -Wall -Werror -g -O0 -D$(PLATFORM)
	LDFLAGS =
endif
CPPFLAGS = $(INCLUDES)

PPCS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.dep)
OBJS = $(SOURCES:.c=.o)

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.dep: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -MP -MMD -MF $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(PPCS) $(ASMS) $(DEPS) $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET).map $(TARGET).out $(OBJS) $(ASMS) $(DEPS) $(DEPS) $(PPCS)
