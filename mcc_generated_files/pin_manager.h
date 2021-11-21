/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18LF27K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SENSOR2 aliases
#define SENSOR2_TRIS                 TRISAbits.TRISA2
#define SENSOR2_LAT                  LATAbits.LATA2
#define SENSOR2_PORT                 PORTAbits.RA2
#define SENSOR2_WPU                  WPUAbits.WPUA2
#define SENSOR2_OD                   ODCONAbits.ODCA2
#define SENSOR2_ANS                  ANSELAbits.ANSELA2
#define SENSOR2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SENSOR2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SENSOR2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SENSOR2_GetValue()           PORTAbits.RA2
#define SENSOR2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SENSOR2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SENSOR2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SENSOR2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SENSOR2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SENSOR2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SENSOR2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define SENSOR2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set SENSOR1 aliases
#define SENSOR1_TRIS                 TRISAbits.TRISA3
#define SENSOR1_LAT                  LATAbits.LATA3
#define SENSOR1_PORT                 PORTAbits.RA3
#define SENSOR1_WPU                  WPUAbits.WPUA3
#define SENSOR1_OD                   ODCONAbits.ODCA3
#define SENSOR1_ANS                  ANSELAbits.ANSELA3
#define SENSOR1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SENSOR1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SENSOR1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SENSOR1_GetValue()           PORTAbits.RA3
#define SENSOR1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SENSOR1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SENSOR1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SENSOR1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define SENSOR1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define SENSOR1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define SENSOR1_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define SENSOR1_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set NRESET aliases
#define NRESET_TRIS                 TRISBbits.TRISB3
#define NRESET_LAT                  LATBbits.LATB3
#define NRESET_PORT                 PORTBbits.RB3
#define NRESET_WPU                  WPUBbits.WPUB3
#define NRESET_OD                   ODCONBbits.ODCB3
#define NRESET_ANS                  ANSELBbits.ANSELB3
#define NRESET_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define NRESET_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define NRESET_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define NRESET_GetValue()           PORTBbits.RB3
#define NRESET_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define NRESET_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define NRESET_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define NRESET_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define NRESET_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define NRESET_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define NRESET_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define NRESET_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set V1 aliases
#define V1_TRIS                 TRISCbits.TRISC4
#define V1_LAT                  LATCbits.LATC4
#define V1_PORT                 PORTCbits.RC4
#define V1_WPU                  WPUCbits.WPUC4
#define V1_OD                   ODCONCbits.ODCC4
#define V1_ANS                  ANSELCbits.ANSELC4
#define V1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define V1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define V1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define V1_GetValue()           PORTCbits.RC4
#define V1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define V1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define V1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define V1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define V1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define V1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define V1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define V1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set DIO5 aliases
#define DIO5_TRIS                 TRISCbits.TRISC5
#define DIO5_LAT                  LATCbits.LATC5
#define DIO5_PORT                 PORTCbits.RC5
#define DIO5_WPU                  WPUCbits.WPUC5
#define DIO5_OD                   ODCONCbits.ODCC5
#define DIO5_ANS                  ANSELCbits.ANSELC5
#define DIO5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DIO5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DIO5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DIO5_GetValue()           PORTCbits.RC5
#define DIO5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DIO5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DIO5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DIO5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DIO5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DIO5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DIO5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define DIO5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISCbits.TRISC6
#define CS_LAT                  LATCbits.LATC6
#define CS_PORT                 PORTCbits.RC6
#define CS_WPU                  WPUCbits.WPUC6
#define CS_OD                   ODCONCbits.ODCC6
#define CS_ANS                  ANSELCbits.ANSELC6
#define CS_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define CS_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define CS_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define CS_GetValue()           PORTCbits.RC6
#define CS_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define CS_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define CS_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF3 pin functionality
 * @Example
    IOCAF3_ISR();
 */
void IOCAF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_InterruptHandler);

*/
extern void (*IOCAF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_DefaultInterruptHandler);

*/
void IOCAF3_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/