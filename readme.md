# Calculator Project for ATmega32

This project implements a calculator using ATmega32 microcontroller, with support for floating numbers and negative numbers. It includes drivers for DIO (Digital Input/Output), LCD (Liquid Crystal Display), and Keypad.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Usage](#usage)
- [Layers and Drivers](#layers-and-drivers)

## Introduction

This project demonstrates the implementation of a calculator with basic arithmetic operations like addition, subtraction, multiplication, and division, handling floating numbers and negative numbers.

## Hardware Requirements

- ATmega32 microcontroller
- LCD display
- Keypad
- Supporting circuitry (power supply, resistors, etc.)

## Usage

1. Power on the microcontroller with the connected hardware.
2. The calculator will be displayed on the LCD.
3. Enter the numbers and operators using the keypad.
4. Press '=' to perform the calculation and display the result.
5. Press 'c' to clear the display and start a new calculation.

## Layers and Drivers

### HAL (Hardware Abstraction Layer)

- **LCD Driver:** Implements functions to interface with the LCD display.
- **Keypad Driver:** Provides functions to interface with the keypad.

### MCAL (Microcontroller Abstraction Layer)

- **DIO Driver:** Controls digital input/output operations for the microcontroller.
"# Calculator-Atmega32" 
"# Calculator-Atmega32" 
