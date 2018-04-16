/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cap2.c
**     Project     : Serial
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.223, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-04-07, 14:06, # CodeGen: 76
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TPM2
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-16
**           Maximal time for capture register
**             Xtal ticks              : 2048
**             microseconds            : 62500
**             milliseconds            : 62
**             seconds (real)          : 0.0625
**             Hz                      : 16
**           One tick of timer is
**             microseconds            : 0.953674
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM2C2V   [$005C]
**              Counter                : TPM2CNT   [$0051]
**              Mode                   : TPM2SC    [$0050]
**              Run                    : TPM2SC    [$0050]
**              Prescaler              : TPM2SC    [$0050]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       47            |  PTA7_TPM2CH2_ADP9
**             ----------------------------------------------------
**
**         Port name                   : PTA
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Signal edge/level           : both
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         Reset           - byte Cap2_Reset(void);
**         GetCaptureValue - byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cap2.c
** @version 01.30
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Cap2_module Cap2 module documentation
**  @{
*/         

/* MODULE Cap2. */

#include "Events.h"
#include "Cap2.h"




/*
** ===================================================================
**     Method      :  Cap2_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte Cap2_Reset(word *Value)

**  This method is implemented as a macro. See Cap2.h file.  **
*/

/*
** ===================================================================
**     Method      :  Cap2_GetCaptureValue (component Capture)
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               0.953674 us in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value)

**  This method is implemented as a macro. See Cap2.h file.  **
*/

/*
** ===================================================================
**     Method      :  Cap2_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cap2_Init(void)
{
  /* TPM2SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM2SC, 0x00U);              /* Stop HW */ 
  /* TPM2MOD: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM2MOD, 0x00U);            /* Disable modulo register */ 
  /* TPM2CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
  setReg8(TPM2CNTH, 0x00U);            /* Reset counter */ 
  /* TPM2C2V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM2C2V, 0x00U);            /* Clear capture register */ 
  /* TPM2SC: PS2=1,PS1=0,PS0=0 */
  clrSetReg8Bits(TPM2SC, 0x03U, 0x04U); /* Set prescaler register */ 
  /* TPM2C2SC: CH2F=0,CH2IE=1,MS2B=0,MS2A=0,ELS2B=1,ELS2A=1,??=0,??=0 */
  setReg8(TPM2C2SC, 0x4CU);            /* Enable both interrupt and capture function */ 
  /* TPM2SC: CLKSB=0,CLKSA=1 */
  clrSetReg8Bits(TPM2SC, 0x10U, 0x08U); /* Run counter */ 
}


/*
** ===================================================================
**     Method      :  Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cap2_Interrupt)
{
  (void)TPM2C2SC;                      /* Dummy read to reset interrupt request flag */
  /* TPM2C2SC: CH2F=0 */
  clrReg8Bits(TPM2C2SC, 0x80U);        /* Reset interrupt request flag */ 
  Cap2_OnCapture();                    /* Invoke user event */
}



/* END Cap2. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/