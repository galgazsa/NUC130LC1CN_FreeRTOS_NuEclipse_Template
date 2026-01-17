NUC130LC1CN FreeRTOS Base Project
🇭🇺 Magyar leírás

Ez a repository egy működő, letisztult FreeRTOS alapprojektet tartalmaz
Nuvoton NUC130LC1CN mikrokontrollerhez.

A projekt célja, hogy:

stabil kiindulási alapot adjon FreeRTOS használatához

NuEclipse + GCC környezetben azonnal fordítható legyen

könnyen klónozható és továbbfejleszthető legyen

Fő jellemzők

MCU: NUC130LC1CN (ARM Cortex-M0)

FreeRTOS (LTS)

Külső 12 MHz kristály

GCC ARM Embedded toolchain

NuEclipse IDE (Windows)

NU-Link Pro debugger támogatás

Tartalom

működő FreeRTOS kernel

helyes startup és linker script

FreeRTOS hook függvények

egyszerű teszt task

valid build (warning és error nélkül)

Ez a projekt nem tartalmaz alkalmazásspecifikus logikát,
csak egy megbízható FreeRTOS alapot.

🇬🇧 English description

This repository contains a clean and working FreeRTOS base project
for the Nuvoton NUC130LC1CN microcontroller.

The goal of this project is to provide:

a stable FreeRTOS starting point

a ready-to-build NuEclipse + GCC configuration

an easy-to-clone base for further development

Key features

MCU: NUC130LC1CN (ARM Cortex-M0)

FreeRTOS (LTS)

External 12 MHz crystal

GCC ARM Embedded toolchain

NuEclipse IDE (Windows)

NU-Link Pro debugger support

Included

fully working FreeRTOS kernel

correct startup and linker script

FreeRTOS hook implementations

simple test task

clean build (no warnings, no errors)

This project does not include any application-specific functionality.
It is intended to be a reliable FreeRTOS base template.

Build environment

OS: Windows

IDE: NuEclipse

Compiler: arm-none-eabi-gcc

Debugger: NU-Link Pro
