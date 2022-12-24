# Atmega32_Projects

## Atmega32
The AVR microcontroller is based on the advanced Reduced Instruction Set Computer (RISC) architecture. ATmega32 microcontroller is a low power CMOS technology based controller. Due to RISC architecture AVR microcontroller can execute 1 million of instructions per second if cycle frequency is 1 MHz provided by crystal oscillator.

![image](https://user-images.githubusercontent.com/84026974/209445954-0e5bd675-8388-4bc3-a39e-6d18e507440e.png)

## Key Features:

Some general features of ATmega32 microcontroller is:

(i) 2 Kilo bytes of internal Static RAM

(ii)	32 X 8 general working purpose registers

(iii)	32 Kilo bytes of in system self-programmable flash program memory.

(iv)	1024 bytes EEPROM

(v)	Programmable serial USART

(vi)	8 Channel, 10 bit ADC

(vii)	One 16-bit timer/counter with separate prescaler, compare mode and capture mode.

(viii)	Available in 40 pin DIP, 44-pad QFN/MLF and 44-lead QTFP

(ix)	Two 8-bit timers/counters with separate prescalers and compare modes

(x)	32 programmable I/O lines

(xi)	In system programming by on-chip boot program

(xii)	Master/slave SPI serial interface

(xiii)	4 PWM channels

(xiv)	Programmable watch dog timer with separate on-chip oscillator


## ATmega32 Memories:

In ATmega32 microcontroller two main memory spaces i.e. the program memory and data memory space are used. In addition it uses an EEPROM memory for data storage.

•	In System Programmable Flash Program Memory:
ATmega32 microcontroller contains 32Kb of on-chip in system programmable flash memory for program storage. Flash memory is organized as 16K X 16K structure and its memory is divided into two sections application program section and boot program section.

•	SRAM Data Memory:
The Register file, the internal data SRAM and I/O memory are addressed by the lower 2144 data memory locations. The first 96 locations address the I/O memory and Register file, and the internal data Static RAM is addressed by the next 2048 locations.

Consider the five different addressing modes for the data memory is:
a)	Direct addressing modes
b)	Indirect addressing modes
c)	Indirect with displacement addressing modes
d)	Indirect with pre-decrement addressing modes
e)	Indirect with post-decrement addressing modes
SRAM data memory have 32 general purpose registers, 2048 bytes of internal data SRAM, and 64 I/O registers are accessible by using the above addressing modes.

•	EEPROM Data Memory:
ATmega32 contains 1024 bytes of data EEPROM memory. It can be used as a separate data space in which single bytes can be read and written.

## ADVANTAGES:
•	Processors are simpler to use, with the usage of 8bit and 16bit instead of 32/64bit which are more complex
•	Readily usable without additional computing components with 32k bytes of onboard self-programmable flash program memory as well as 23 programmable I/O lines
•	Code Efficient, all 31 registers are directly connected to the arithmetic logic unit (ALU), making it 10 times faster than conventional CISC microcontrollers
•	Optimized for AVR enhanced RISC instruction set

## DISADVANTAGES:
•	Lacks performance compared to higher bit microcontrollers

## APPLICATIONS:
* Daily Life Control Devices microcontroller applications gsm phone interfacing
1. Interfacing with other devices and control e.g. interfacing with GSM modem and controlling
2. Temperature sensing and control
3. lightening sense & control devices
4. Fire detection & safety devices

*	Industrial Control Devices
1. process control devices
2. Industrial instrumentation devices

* Metering & Measurement Devices
1. Hand-held metering systems
2. Volt Meter
3. Current Meter
4. Measuring revolving objects

* Motor Speed Control Devices
1. AC 3 phase and 2 phase motor control
2. DC motors controls
3. Stepper motor controls
4. Servo motor controls

* Medical & Health Devices
1. Medical laboratory devices
2. Surgical & Analysis equipment devices
