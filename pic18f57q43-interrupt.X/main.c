 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
/*
    Main application
*/

void Timer0_Callback(void) {
    for (int i=10; i>0; i--){
        INTERRUPT_GlobalInterruptHighDisable(); 
        INTERRUPT_GlobalInterruptLowDisable(); 
        printf("[Low Priority] Timer0 ISR is executing ... Counting down: %d \r\n\n", i);
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable(); 
    }
    PIE3bits.TMR0IE = 0; // Disable Timer0
}

void Timer1_Callback(void){
    for (int i=10; i>0; i--){
        INTERRUPT_GlobalInterruptHighDisable(); 
        INTERRUPT_GlobalInterruptLowDisable(); 
        printf("[High Priority] Timer1 ISR is executing ... Counting down: %d \r\n\n", i);
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable(); 
    }
    PIE3bits.TMR1IE = 0; // Disable Timer1
}

void RB4_IOC_Callback(void){
    for (int i=10; i>0; i--){
        INTERRUPT_GlobalInterruptHighDisable(); 
        INTERRUPT_GlobalInterruptLowDisable(); 
        printf("[Low Priority] IOC ISR is executing ... Counting down: %d \r\n\n", i);
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable(); 
    }
    PIE0bits.IOCIE = 0; // Disable RB4 IOC
}

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 

    bool done = false;  
   
    Timer0_OverflowCallbackRegister (Timer0_Callback);
    Timer1_OverflowCallbackRegister (Timer1_Callback);
    RB4_SetInterruptHandler (RB4_IOC_Callback);

    printf("---------------------------------------------------------------------------\r\n\n");
    printf("   Demo 1: High/Low-Priority Interrupt While Executing Main Routine        \r\n\n");
    printf("   Demo 2: High-Priority Interrupt with a Low-Priority Interrupt Pending   \r\n\n");
    printf("   Demo 3: High-Priority Interrupt Preempting Low-Priority Interrupts      \r\n\n");
    printf("   Demo 4: Simultaneous High- and Low-Priority Interrupts                  \r\n\n");
    printf("                   Please enter a number: (1/2/3/4)                        \r\n\n");
    while(!done) {
        done = true;
        UART1_Enable();
        

        while(!(UART1_IsRxReady()));
        switch(UART1_Read()){   
            case 49: //Decimal 1 = ASCII 49
                        // Demo 1: High/Low-Priority Interrupt While Executing Main Routine
                        printf("-------------------------------------------------------------------------\r\n\n");
                        printf("Entering Demo 1: High/Low-Priority Interrupt While Executing Main Routine\r\n\n");
                        printf("-------------------------------------------------------------------------\r\n\n");
                        break;
                    case 50: //Decimal 2 = ASCII 50
                        // Demo 2: High-Priority Interrupt with a Low-Priority Interrupt Pending
                        printf("------------------------------------------------------------------------------\r\n\n");
                        printf("Entering Demo 2: High-Priority Interrupt with a Low-Priority Interrupt Pending\r\n\n");
                        printf("------------------------------------------------------------------------------\r\n\n");
                        Timer1_Start();
                        break;
                    case 51: //Decimal 3 = ASCII 51
                        // Demo 3: High-Priority Interrupt Preempting Low-Priority Interrupts
                        printf("---------------------------------------------------------------------------\r\n\n");
                        printf("Entering Demo 3: High-Priority Interrupt Preempting Low-Priority Interrupts\r\n\n");
                        printf("---------------------------------------------------------------------------\r\n\n");
                        Timer1_Start();
                        break;
                    case 52: //Decimal 4 = ASCII 52
                        // Demo 4: Simultaneous High- and Low-Priority Interrupts
                        printf("---------------------------------------------------------------\r\n\n");
                        printf("Entering Demo 4: Simultaneous High- and Low-Priority Interrupts\r\n\n");
                        printf("---------------------------------------------------------------\r\n\n");
                        Timer1_Start();
                        Timer0_Start();
                        break;
                    default:
                        printf("Please enter a valid number!!! (1/2/3/4) \r\n\n");
                        UART1_Disable(); // FIFO Reset
                        done = false;
                        break;
        }
    }
    
    for (int i=10; i>0; i--){
        INTERRUPT_GlobalInterruptHighDisable(); 
        INTERRUPT_GlobalInterruptLowDisable(); 
        printf("        Main routine is executing ... Counting down: %d \r\n\n", i);
        INTERRUPT_GlobalInterruptHighEnable();
        INTERRUPT_GlobalInterruptLowEnable(); 
    }
    
    printf("-----------\r\n\n");
    printf("End of Demo\r\n\n");
    printf("-----------\r\n\n");

    while(1)
    {
    }    
}