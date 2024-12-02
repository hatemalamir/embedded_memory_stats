###******************************************************************************
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
###*****************************************************************************


### This is the final assessment of the Coursera Specialization of Embedded
### Software Essentials, Introduction to Embedded Software and Development
### Environments.

### The repository is organized into multiple files and directories:
###      README.md - This file
###      `course1` - sources files of the assessment. Contains the following:
###      - Makefile - The makefile
###      - sources.mk - The source file
###      - msp432p401r.lds - The linker file you are to use for linking
###      - `src` folder : contains the following:
###      -- course1.c - 
###      -- data.c - 
###      -- main.c - Main file
###      -- memory.c - File that interacts with memory through an IO abstraction
###        interface
###      -- stats.c - Simple statistic functions
###      -- interrupts_msp432p401r_gcc.c - MSP432 specific C-file for interrupts
###      -- startup_msp432p401r_gcc.c - MSP432 specific C-file for startup
###      -- system_msp432p401r.c - MSP432 specific C-file for for system
###        information
###      - `include` folder : contains the three directories of supporting header
###        files
###      -- common - Common headers for all targets. Contains the following:
###      --- course1.h - 
###      --- data.h - 
###      --- memory.h - 
###      --- platform.h - 
###      --- stats.h - 
###      -- msp432 - Contains MSP432 headers. Contains the following:
###      --- msp.h - 
###      --- msp432p401r.h - 
###      --- msp_compatibility.h - 
###      --- system_msp432p401r.h - 
###      -- CMSIS - Contains ARM architecture specific headers
###      --- cmsis_gcc.h - 
###      --- core_cm4.h - 
###      --- core_cmFunc.h - 
###      --- core_cmInstr.h - 
###      --- core_cmSimd.h - 
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
###      
