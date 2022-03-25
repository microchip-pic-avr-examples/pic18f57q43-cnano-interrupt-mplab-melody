<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Vectored Interrupt Demo for Microchip Univeristy Interrupt Class

<!-- This is where the introduction to the example goes, including mentioning the peripherals used -->

This code example showcases vectored interrupt functionality using three separate interrupt sources: Timer 0, Timer 1 and Interrupt-on-Change. Timer 1 is configured as a high-priority interrupt source. Timer 0 and Interrupt-on-Change are configured as low-priority interrupt sources. The results of this code example will be displayed in the MPLAB® Data Visualizer through the UART interface.

## Related Documentation

<!-- Any information about an application note or tech brief can be linked here. Use unbreakable links!
     In addition a link to the device family landing page and relevant peripheral pages as well:
     - [AN3381 - Brushless DC Fan Speed Control Using Temperature Input and Tachometer Feedback](https://microchip.com/00003381/)
     - [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family) -->

- [PIC18F57Q43 Curiosity Nano Hardware User Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf)
- [PIC18F57Q43 Data Sheet](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC18F27-47-57Q43-Data-Sheet-40002147F.pdf)

## Software Used

<!-- All software used in this example must be listed here. Use unbreakable links!
     - MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
     - MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
     - MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/) -->

- MPLAB® X IDE 6.00.0 or newer [(MPLAB® X IDE 6.00)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-interrupt-mplab-mcc-github)
- MPLAB® XC8 2.35.0 or newer compiler [(MPLAB® XC8 2.35)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-interrupt-mplab-mcc-github)
- MPLAB® Code Configurator (Plugin) v5.1.1 [(MPLAB® Code Configurator)](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)
- MPLAB® Data Visualizer 1.3.1113 [(MPLAB® Data Visualizer)](<https://www.microchip.com/en-us/development-tools-tools-and-software/embedded-software-center/mplab-data-visualizer>)
- Microchip PIC18F-Q Series Device Support (1.13.211) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/) 

## Hardware Used

<!-- All hardware used in this example must be listed here. Use unbreakable links!
     - PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)
     - Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
     - POT Click board™ [(MIKROE-3402)](https://www.mikroe.com/pot-click) -->

- PIC18F57Q43 Curiosity Nano [(DM164150)](https://www.microchip.com/en-us/development-tool/DM164150)
- Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/developmenttools/ProductDetails/AC164162)     

## Setup

<!-- Explain how to connect hardware and set up software. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->

The PIC18F57Q43 Curiosity Nano Development Board is the selected hardware platform for this code example. The diagram below shows the hardware connections for this example.

Connection diagram if using Curiosity Nano Base for Click boards™:
<br><img src="images/Hardware_setup_with_base.png">

Connection diagram without using Curiosity Nano Base for Click boards™:
<br><img src="images/Hardware_setup.png">

## Operation

<!-- Explain how to operate the example. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->

1. Insert the PIC18F57Q43 Curiosity Nano into the Curiosity Nano click board.

2. Connect the PIC18F57Q43 Curiosity Nano development board to a PC using a micro USB cable to provide power and to allow for programming and debugging.

3. Open the *pic18f57q43-interrupt.X* project in MPLAB® X IDE.

4. Set *pic18f57q43-interrupt.X* project as the main project within the MPLAB® X IDE. This can be done by right clicking on the project name in the *Projects* tab and then clicking *Set as Main Project*:

5. Select the PIC18F57Q43 Curiosity Nano in the *Connected Hardware Tool* drop down list within the project settings in the MPLAB® X IDE. This can be done using the following steps:

   - Right click on the project and select *Properties*;
   - Select the PIC18F57Q43 Curiosity Nano in the *Connected Hardware Tool* list and then click *OK*:
  
6. Program the project to the PIC18F57Q43 Curiosity Nano Development board by right clicking on the project and selecting the *Make and Program Device* option:

7. Once the device has been successfully programmed, open the MPLAB® Data Visualizer within the MPLAB® X IDE.
   - Once the MPLAB® Data Visualizer has launched, open the drop down list and select the COMn port for serial connection and Click the *Start streaming COMn port* button. Refer to the figure below for more information about these steps.
<br><img src="images/Drop down list.png">
   - In the MPLAB® Data Visualizer terminal window, click COMn port as the data source as shown in the figure below.
<br><img src="images/Terminal option.png">

8. Type the number "1", "2", "3", or "4" into the MPLAB® Data Visualizer terminal in order to launch the respective demo on the PIC18F57Q43 Curiosity Nano Development Board. Details pertaining to each of the available demos are shown in the figures below:

- Demo 1: High/Low-Priority Interrupt While Executing Main Routine
<br><img src="images/High Low-Priority Interrupt While Executing Main Routine.png">

- Demo 2: High-Priority Interrupt with a Low-Priority Interrupt Pending
<br><img src="images/High-Priority Interrupt with a Low-Priority Interrupt Pending.png">

- Demo 3: High-Priority Interrupt Preempting Low-Priority Interrupts
<br><img src="images/High-Priority Interrupt Preempting Low-Priority Interrupts.png">

- Demo 4: Simultaneous High- and Low-Priority Interrupts
<br><img src="images/Simultaneous High- and Low-Priority Interrupts.png">

### Result

The figures below show the resulting terminal outputs for each of the available demos:

- Demo 1: High/Low-Priority Interrupt While Executing Main Routine
<br><img src="images/Demo 1 result.png">

- Demo 2: High-Priority Interrupt with a Low-Priority Interrupt Pending
<br><img src="images/Demo 2 result.png">

- Demo 3: High-Priority Interrupt Preempting Low-Priority Interrupts
<br><img src="images/Demo 3 result.png">

- Demo 4: Simultaneous High- and Low-Priority Interrupts
<br><img src="images/Demo 4 result.png">

## Summary

<!-- Summarize what the example has shown -->

This code example showcases the vectored interrupt feature of the PIC18F57Q43.
This demo is for the Microchip University 8-bit PIC® MCU Peripheral Deep Dive Interrupt class.