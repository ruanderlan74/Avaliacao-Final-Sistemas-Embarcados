/**
 *  \file   main.c
 *
 *  \brief  Example application main file. This application will toggle the led.
 *          The led toggling will be done inside an callback function, which
 *          will be called by Interrupt Service Routine. Interrupts are
 *          triggered manually and no external source is used to trigger
 *          interrupts.
 *
 */

/*
 * Copyright (C) 2014 - 2016 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/family/arm/a8/intcps/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>

/* BIOS Header files */
#include <ti/sysbios/knl/Task.h>
#endif

#include <stdio.h>

#include <ti/sysbios/BIOS.h>
/* TI-RTOS Header files */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include "GPIO_log.h"
#include "GPIO_board.h"

#include <ti/board/board.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <MPU_6050_Register.h>
#include <ftoa.h>
#include <convert.h>
#include <math.h>


float readACCEL_X();
float readACCEL_Y();
float readACCEL_Z();
float readGYRO_X();
float readGYRO_Y();
float readGYRO_Z();
float convertValRegToFloat(int val,int LSB);
float convertValRegToFloat(int val,int LSB);

/*Declarando tasks e interrupção de Sw*/

Task_Handle task0;
Task_Handle task1;
Task_Handle task2;
Task_Handle task3;
Swi_Handle swi0;
Swi_Handle swi1;
Swi_Handle swi2;
Swi_Handle swi3;
Clock_Handle myClock;
Clock_Handle myClock0;
Clock_Handle myClock1;
Clock_Handle myClock2;
Semaphore_Handle semTaskEICAS;
Semaphore_Handle semTaskRNAV;
Semaphore_Handle semTaskEW;
Semaphore_Handle semTaskRADAR;

Semaphore_Handle semTask0;
Semaphore_Handle semTask1;
Semaphore_Handle semTask2;

int iSwitchTask = 0;
int intNum    = 98;
int System    = 0;
int contEICAS = 0;
int contRNAV  = 0;
int contEW    = 0;
int contRADAR = 0;
int cont      = 0;
int g         = 9.81;
int nr = 0;
float reading_ACCEL_X;
float reading_ACCEL_Y;
float reading_ACCEL_Z;
float reading_GYRO_X;
float reading_GYRO_Y;
float reading_GYRO_Z;
int quant_vz_comp = 0;
I2C_HwAttrs i2c_cfg;
u_int8_t enable_read_compensador = 0;
float ValorDeComp_acel_x = 0;
float ValorDeComp_acel_y = 0;
float ValorDeComp_acel_z = 0;
float ValorDeComp_giro_x = 0;
float ValorDeComp_giro_y = 0;
float ValorDeComp_giro_z = 0;
float acel_x = 0;
float acel_y = 0;
float acel_z = 0;
float giro_x = 0;
float giro_y = 0;
float giro_z = 0;
u_int8_t enable_sys = 0;
char buff_ACCEL_X[100];
char buff_ACCEL_Y[100];
char buff_ACCEL_Z[100];
char buff_GYRO_X[100];
char buff_GYRO_Y[100];
char buff_GYRO_Z[100];

int SystemModeOperation;
int SystemClkCockpitGlobal  = 80;



const unsigned CheckIfSigned[33]=
{0x00000000,
0x00000001,0x00000002,0x00000004,0x00000008,
0x00000010,0x00000020,0x00000040,0x00000080,
0x00000100,0x00000200,0x00000400,0x00000800,
0x00001000,0x00002000,0x00004000,0x00008000,
0x00010000,0x00020000,0x00040000,0x00080000,
0x00100000,0x00200000,0x00400000,0x00800000,
0x01000000,0x02000000,0x04000000,0x08000000,
0x10000000,0x20000000,0x40000000,0x80000000};
const unsigned ConvertToSigned[32]=
{0xffffffff,
0xfffffffe,0xfffffffc,0xfffffff8,0xfffffff0,
0xffffffe0,0xffffffc0,0xffffff80,0xffffff00,
0xfffffe00,0xfffffc00,0xfffff800,0xfffff000,
0xffffe000,0xffffc000,0xffff8000,0xffff0000,
0xfffe0000,0xfffc0000,0xfff80000,0xfff00000,
0xffe00000,0xffc00000,0xff800000,0xff000000,
0xfe000000,0xfc000000,0xf8000000,0xf0000000,
0xe0000000,0xc0000000,0x80000000};
const unsigned digits2bits[33]=
{0x00000000,
0x00000001,0x00000003,0x00000007,0x0000000f,
0x0000001f,0x0000003f,0x0000007f,0x000000ff,
0x000001ff,0x000003ff,0x000007ff,0x00000fff,
0x00001fff,0x00003fff,0x00007fff,0x0000ffff,
0x0001ffff,0x0003ffff,0x0007ffff,0x000fffff,
0x001fffff,0x003fffff,0x007fffff,0x00ffffff,
0x01ffffff,0x03ffffff,0x07ffffff,0x0fffffff,
0x1fffffff,0x3fffffff,0x7fffffff,0xffffffff};

#define I2C_MPU_6065_INSTANCE   (1)

#define MPU_6050_SLAVE_ADDR     (0x68)





/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined (SOC_AM571x)
#if defined (__TI_ARM_V7M4__)
#define DELAY_VALUE       (0x6FFFFFU) /* Update Delay as it is not sufficent for M4 core */
#else
#define DELAY_VALUE       (0x6FFFFFU)
#endif
#else
#define DELAY_VALUE       (0x6FFFFFU)
#endif

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Delay function */
void AppDelay(unsigned int delayVal);

/* Callback function */
void AppGpioCallbackFxn(void);

#if defined(idkAM574x) || defined(idkAM572x) || defined(idkAM571x)
/* GPIO clock and pinmux configurations */
extern void AppGPIOInit(void);
#endif

#if defined(idkAM574x) || defined(idkAM572x)
extern void GPIOApp_UpdateBoardInfo(void);
extern void GPIOAppUpdateConfig(uint32_t *gpioBaseAddr, uint32_t *gpioPin);
#endif

/*
 *  ======== Board_initI2C ========
 */
static void Board_initGPIO(void)
{
    Board_initCfg boardCfg;

#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
    GPIO_v0_HwAttrs gpio_cfg;

    /* Get the default SPI init configurations */
    GPIO_socGetInitCfg(GPIO_LED0_PORT_NUM, &gpio_cfg);

    /* Modify the default GPIO configurations if necessary */

    /* Set the default GPIO init configurations */
    GPIO_socSetInitCfg(GPIO_LED0_PORT_NUM, &gpio_cfg);

#if defined(SOC_K2G)
    /* Setup GPIO interrupt configurations */
    GPIO_socSetIntMux(GPIO_LED0_PORT_NUM, GPIO_LED0_PIN_NUM, NULL, GPIO_MUX_SEL);
#endif
#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
    /* Setup GPIO interrupt configurations */
    GPIO_socSetBankInt(GPIO_LED0_PORT_NUM, GPIO_LED0_PIN_NUM, NULL);
#endif
#endif

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

#if defined(idkAM572x) || defined(idkAM574x)
    GPIOApp_UpdateBoardInfo();
#endif
}

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
volatile uint32_t gpio_intr_triggered = 0;
uint32_t gpioBaseAddr;
uint32_t gpioPin;

/*
 *  ======== test function ========
 */
#ifndef BARE_METAL
void gpio_test(UArg arg0, UArg arg1)

{
#else
void main()
{
    Board_initGPIO();

#endif
    uint32_t testOutput = 1;

    /* GPIO initialization */
    GPIO_init();

    /* Set the callback function */
    GPIO_setCallback(USER_LED0, AppGpioCallbackFxn);

    /* Enable GPIO interrupt on the specific gpio pin */
    GPIO_enableInt(USER_LED0);

    /* Write high to gpio pin to control LED1 */
    GPIO_write((USER_LED1), GPIO_PIN_VAL_HIGH);
    AppDelay(DELAY_VALUE);

    GPIO_log("\n GPIO Led Blink Application \n");

#if defined(SOC_K2L) || defined(SOC_C6678) || defined(SOC_C6657)
    /* No GPIO pin directly connected to user LED's on K2L/K2G/C6678/C6657 EVM, just trigger interrupt once */
    GPIO_toggle(USER_LED0);
    while (!gpio_intr_triggered);

    GPIO_log("\n All tests have passed \n");
#else

    while(1)
    {
#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined(SOC_AM571x)|| defined(SOC_AM335x) || defined(SOC_AM437x)

#if defined (idkAM572x) || defined (idkAM574x)
        /* Update GPIO info based on the board */
        GPIOAppUpdateConfig(&gpioBaseAddr, &gpioPin);
#else
        gpioBaseAddr = GPIO_BASE_ADDR;
        gpioPin      = GPIO_LED_PIN;
#endif
        /* Trigger interrupt */
        GPIOTriggerPinInt(gpioBaseAddr, 0, gpioPin);
#endif
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
        GPIO_toggle(USER_LED0);
#endif
        AppDelay(DELAY_VALUE);
        if (testOutput)
        {
            GPIO_log("\n All tests have passed \n");
            testOutput = 0;
        }
    }
#endif
    Task_exit();
}

#ifndef BARE_METAL
/*
 *  ======== main ========
 */

/*
 *  ======== AppLoopDelay ========
 */
void AppLoopDelay(uint32_t delayVal)
{
    volatile uint32_t i;

    for (i = 0; i < (delayVal * 1000); i++)
        ;
}




void gpio_test0(){
    while(1){
        GPIOPinWrite(SOC_GPIO_2_REGS, 10, GPIO_PIN_HIGH);
        AppDelay(DELAY_VALUE);
        GPIOPinWrite(SOC_GPIO_2_REGS, 10, GPIO_PIN_LOW);
        AppDelay(DELAY_VALUE);


    }
}
void gpio_test1(){
    while(1){
        GPIOPinWrite(SOC_GPIO_2_REGS, 12, GPIO_PIN_HIGH);
        AppDelay(DELAY_VALUE);
        GPIOPinWrite(SOC_GPIO_2_REGS, 12, GPIO_PIN_LOW);
        AppDelay(DELAY_VALUE);
    }
}

void gpio_test_0()
{
   while(1)
   {
       AppDelay(DELAY_VALUE);
       if(iSwitchTask)
       {
           iSwitchTask = 0;
           Task_yield();

       }
   }
}

void gpio_test_1()
{
   while(1)
   {
       AppDelay(DELAY_VALUE);
       if(iSwitchTask)
       {
           iSwitchTask = 0;
           Task_yield();

       }
   }
}


/*void gpio_test_00()
{
    while(1){
        GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_HIGH);
        AppDelay(DELAY_VALUE);
        GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_LOW);
        Semaphore_pend(semTask, BIOS_WAIT_FOREVER);
    }
}

void gpio_test_01()
{
    while(1){
        GPIOPinWrite(SOC_GPIO_1_REGS, 24, GPIO_PIN_HIGH);
        AppDelay(100*DELAY_VALUE);
        GPIOPinWrite(SOC_GPIO_1_REGS, 24, GPIO_PIN_LOW);
        Semaphore_pend(semTask, BIOS_WAIT_FOREVER);
    }
}

*/

void myNewSwitch(Task_Handle prev, Task_Handle next)
{
    int GPIOPin2TurnOn = 0;
    int GPIOPin2TurnOff = 0;

    if(prev == task0)
    {
        GPIOPin2TurnOff = 21;
        UART_printStatus("\n Leaving Task 0. \n");

    }
    else if (prev == task1)
    {
        GPIOPin2TurnOff = 22;
        UART_printStatus("\n Leaving Task 1. \n");
    }
    if(next == task0)
    {
        UART_printStatus("\n Entering Task 0. \n");
        GPIOPin2TurnOn = 21;
    }
    else if (next == task1)
    {
        UART_printStatus("\n Entering Task 1. \n");
        GPIOPin2TurnOn = 22;
    }
    if(GPIOPin2TurnOn != 0)
    {
        GPIOPinWrite(SOC_GPIO_1_REGS, GPIOPin2TurnOn, GPIO_PIN_HIGH);
    }
    if(GPIOPin2TurnOff != 0)
        {
            GPIOPinWrite(SOC_GPIO_1_REGS, GPIOPin2TurnOff, GPIO_PIN_LOW);
        }
}


void tskEICAS()
{
    while(1)
    {
            GPIOPinWrite(SOC_GPIO_1_REGS, 21, GPIO_PIN_HIGH);
            AppLoopDelay(800U);
            GPIOPinWrite(SOC_GPIO_1_REGS, 21, GPIO_PIN_LOW);
            Semaphore_pend(semTaskEICAS,BIOS_WAIT_FOREVER);
    }

}


void tskRNAV()
{
    while(1)
    {
            GPIOPinWrite(SOC_GPIO_1_REGS, 22, GPIO_PIN_HIGH);
            AppLoopDelay(8000U);
            GPIOPinWrite(SOC_GPIO_1_REGS, 22, GPIO_PIN_LOW);
            Semaphore_pend(semTaskRNAV,BIOS_WAIT_FOREVER);
    }
}

void tskEW()
{
    while(1)
    {
        if(System == 1){

                GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_HIGH);
                AppLoopDelay(1000U);
                GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_LOW);
                Semaphore_pend(semTaskEW,BIOS_WAIT_FOREVER);

        }else{
            Semaphore_pend(semTaskEW,BIOS_WAIT_FOREVER);
        }
    }
}

void tskRADAR()
{
    while(1)
    {
        if(System == 1){

                GPIOPinWrite(SOC_GPIO_1_REGS, 24, GPIO_PIN_HIGH);
                AppLoopDelay(800U);
                GPIOPinWrite(SOC_GPIO_1_REGS, 24, GPIO_PIN_LOW);
                Semaphore_pend(semTaskRADAR,BIOS_WAIT_FOREVER);

        }else{
            Semaphore_pend(semTaskRADAR,BIOS_WAIT_FOREVER);
        }
    }
}




void isrFunc()
{
  /* if(cont >= 80){
       if(System != 0){
           System = 0;
           UART_printStatus("Modo navegacao ativado \n");
       }else{
           System = 1;
           UART_printStatus("Modo combate ativado \n");
       }
       cont = 0;
   }else{
       UART_printStatus("Tempo < q 4 segs \n");
   }
   GPIOPinIntClear(SOC_GPIO_1_REGS, GPIO_INT_LINE_1, 16);
    */

    GPIOPinIntClear(SOC_GPIO_1_REGS, GPIO_INT_LINE_1, 16);
}

void swiFunc()
{


    if(contEICAS == 1U){

           Semaphore_post(semTaskEICAS);

           contEICAS=0;
       }
       if(contRNAV == 20 * 1U){

           Semaphore_post(semTaskRNAV);

           contRNAV=0;
       }
       if(contEW == 4 * 1U){

           Semaphore_post(semTaskEW);

           contEW=0;
       }
       if(contRADAR == 2 * 1U){

           Semaphore_post(semTaskRADAR);

           contRADAR=0;
       }

       contEICAS++;
       contRNAV++;
       contEW++;
       contRADAR++;
       cont++;

}

uint8_t readSensor(I2C_Handle h, uint8_t reg){
    uint8_t rxData = 0;
    uint8_t txData = 0;
    I2C_Transaction t;
    int16_t transferStatus;
    I2C_transactionInit(&t);
    memset(&txData, 0x00, sizeof(txData));
    t.slaveAddress = MPU_6050_SLAVE_ADDR;
    t.writeBuf = &txData;
    t.writeCount = 1;
    t.readBuf = &rxData;
    t.readCount = 1;
    t.timeout = 1000U;
    txData = reg;
    transferStatus = I2C_transfer(h, &t);
    if(I2C_STS_SUCCESS != transferStatus){
        //UART_printf("\n Data Transfer failed with transfer status %d \n",transferStatus);
    }
    return rxData;
}

void writeSensor(I2C_Handle h, uint8_t reg, uint8_t val){
    uint8_t txData[2] = {0,0};
    I2C_Transaction t;
    int16_t transferStatus;
    I2C_transactionInit(&t);
    //memset(&txData, 0x00, sizeof(txData));

    t.slaveAddress = MPU_6050_SLAVE_ADDR;
    t.writeBuf = &txData;
    t.writeCount = 2;
    t.readCount = 0;
    t.timeout = 1000U;
    txData[0] = reg;
    txData[1] = val;

    transferStatus = I2C_transfer(h, &t);

    if(I2C_STS_SUCCESS != transferStatus){
           //UART_printf("\n Data Transfer failed with transfer status %d \n",transferStatus);
       }

}

void IMUSetUp(){
    I2C_Params i2cParams;
    I2C_Handle handle;
    I2C_Params_init(&i2cParams);
    //i2cParams.bitRate = I2C_400kHz;
    handle = I2C_open(I2C_MPU_6065_INSTANCE, &i2cParams);
    if(handle == NULL) UART_printf("ERROR");

//    UART_printf("Init Acc/Gyro Setup... \n");
//    UART_printf("Device Reset... \n");
    writeSensor(handle, PWR_MGMT_1, 0x00);
//    UART_printf("Accelerometer Config... \n");
    writeSensor(handle, ACCEL_CONFIG, 0x10);
//    UART_printf("Gyro Config... \n");
    writeSensor(handle, GYRO_CONFIG, 0x10);
    I2C_close(handle);
//    UART_printf("Acc/Gyro Setup Ended... \n");
}

void tskCompensador(){

    IMUSetUp();

    UART_printf("%d\n",readtest());
    while(1){
        if(enable_read_compensador==1){
            GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_HIGH);
            ValorDeComp_acel_x = ValorDeComp_acel_x + readACCEL_X();
            ValorDeComp_acel_y = ValorDeComp_acel_y + readACCEL_Y();
            ValorDeComp_acel_z = ValorDeComp_acel_z + readACCEL_Z();

            ValorDeComp_giro_x = ValorDeComp_giro_x + readGYRO_X();
            ValorDeComp_giro_y = ValorDeComp_giro_y + readGYRO_Y();
            ValorDeComp_giro_z = ValorDeComp_giro_z + readGYRO_Z();

            quant_vz_comp++;
            enable_read_compensador = 0;
            GPIOPinWrite(SOC_GPIO_1_REGS, 23, GPIO_PIN_LOW);
        }
        Semaphore_pend(semTask0,BIOS_WAIT_FOREVER);
    }

}

void tskGetvalorReal(){
    while(1){
        if(enable_sys){
            GPIOPinWrite(SOC_GPIO_1_REGS, 21, GPIO_PIN_HIGH);
            acel_x = ValorDeComp_acel_x - readACCEL_X();
            acel_y = ValorDeComp_acel_y - readACCEL_Y();
            acel_z = ValorDeComp_acel_z - readACCEL_Z();

            giro_x = ValorDeComp_giro_x - readGYRO_X();
            giro_y = ValorDeComp_giro_y - readGYRO_Y();
            giro_z = ValorDeComp_giro_z - readGYRO_Z();
            GPIOPinWrite(SOC_GPIO_1_REGS, 21, GPIO_PIN_LOW);
            Semaphore_pend(semTask1,BIOS_WAIT_FOREVER);


        }
    }
}

void tskPLTdate(){
    while(1){
        if(enable_sys==1){
            GPIOPinWrite(SOC_GPIO_1_REGS, 22, GPIO_PIN_HIGH);

            ftoa(acel_x, buff_ACCEL_X, 4);
            ftoa(acel_y, buff_ACCEL_Y, 4);
            ftoa(acel_z, buff_ACCEL_Z, 4);
            ftoa(giro_x, buff_GYRO_X, 4);
            ftoa(giro_y, buff_GYRO_Y, 4);
            ftoa(giro_z, buff_GYRO_Z, 4);
            UART_printf("{\"Acelera\":{\"x\":\"%s\",\"y\":\"%s\",\"z\":\"%s\"},\"Giro\":{\"x\":\"%s\",\"y\":\"%s\",\"z\":\"%s\"}}\n",buff_ACCEL_X,buff_ACCEL_Y,buff_ACCEL_Z,buff_GYRO_X,buff_GYRO_Y,buff_GYRO_Z);
            GPIOPinWrite(SOC_GPIO_1_REGS, 22, GPIO_PIN_LOW);
            Semaphore_pend(semTask2,BIOS_WAIT_FOREVER);
        }
    }
}

float readACCEL_X(){
    float ret = 0;
    uint16_t nr = 0;
    uint8_t high = 0;
    uint8_t low = 0;
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Params_init(&i2cParams);
    handle = I2C_open(1, &i2cParams);
    high = readSensor(handle, ACCEL_XOUT_H);
    low = readSensor(handle, ACCEL_XOUT_L);
    nr |=high;
    nr = nr<<8;
    nr |= low;
    ret = convertValRegToFloat(nr, LSB_SENSITIVITY_ACCEL_8G);
    I2C_close(handle);
    return ret;
}
int readtest(){
    int ret = 0;
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Params_init(&i2cParams);
    handle = I2C_open(1, &i2cParams);
    ret = readSensor(handle,WHO_AM_I);

    I2C_close(handle);
    return ret;
}
float readACCEL_Y(){
    float ret = 0;
        uint16_t nr = 0;
        uint8_t high = 0;
        uint8_t low = 0;
        I2C_Params i2cParams;
        I2C_Handle handle = NULL;
        I2C_Params_init(&i2cParams);
        handle = I2C_open(1, &i2cParams);
        high = readSensor(handle, ACCEL_YOUT_H);
        low = readSensor(handle, ACCEL_YOUT_L);
        nr |=high;
        nr = nr<<8;
        nr |= low;
        ret = convertValRegToFloat(nr, LSB_SENSITIVITY_ACCEL_8G);
        I2C_close(handle);
        return ret;
}
float readACCEL_Z(){
    float ret = 0;
        uint16_t nr = 0;
        uint8_t high = 0;
        uint8_t low = 0;
        I2C_Params i2cParams;
        I2C_Handle handle = NULL;
        I2C_Params_init(&i2cParams);
        handle = I2C_open(1, &i2cParams);
        high = readSensor(handle, ACCEL_ZOUT_H);
        low = readSensor(handle, ACCEL_ZOUT_L);
        nr |=high;
        nr = nr<<8;
        nr |= low;
        ret = convertValRegToFloat(nr, LSB_SENSITIVITY_ACCEL_8G);
        I2C_close(handle);
        return ret;
}

float readGYRO_X(){
    float ret = 0;
        uint16_t nr = 0;
        uint8_t high = 0;
        uint8_t low = 0;
        I2C_Params i2cParams;
        I2C_Handle handle = NULL;
        I2C_Params_init(&i2cParams);
        handle = I2C_open(1, &i2cParams);
        high = readSensor(handle, GYRO_XOUT_H);
        low = readSensor(handle, GYRO_XOUT_L);
        nr |=high;
        nr = nr<<8;
        nr |= low;
        ret = convertValRegToFloat(nr, LSB_SENSITIVITY_GYRO_1000);
        I2C_close(handle);
        return ret;
}
float readGYRO_Y(){
    float ret = 0;
            uint16_t nr = 0;
            uint8_t high = 0;
            uint8_t low = 0;
            I2C_Params i2cParams;
            I2C_Handle handle = NULL;
            I2C_Params_init(&i2cParams);
            handle = I2C_open(1, &i2cParams);
            high = readSensor(handle, GYRO_YOUT_H);
            low = readSensor(handle, GYRO_YOUT_L);
            nr |=high;
            nr = nr<<8;
            nr |= low;
            ret = convertValRegToFloat(nr, LSB_SENSITIVITY_GYRO_1000);
            I2C_close(handle);
            return ret;
}
float readGYRO_Z(){
    float ret = 0;
            uint16_t nr = 0;
            uint8_t high = 0;
            uint8_t low = 0;
            I2C_Params i2cParams;
            I2C_Handle handle = NULL;
            I2C_Params_init(&i2cParams);
            handle = I2C_open(1, &i2cParams);
            high = readSensor(handle, GYRO_ZOUT_H);
            low = readSensor(handle, GYRO_ZOUT_L);
            nr |=high;
            nr = nr<<8;
            nr |= low;
            ret = convertValRegToFloat(nr, LSB_SENSITIVITY_GYRO_1000);
            I2C_close(handle);
            return ret;
}


float convertValRegToFloat(int val,int LSB){
    int temp;
    temp = val & CheckIfSigned[16];
    if (temp != 0)
        temp = (val | ConvertToSigned[16-1]);
    else
        temp=val;
    float ret = (temp+0.0)/LSB;
    return ret;
}
float convertValRegToFloatGYRO(int val,int LSB){
    int temp;
    temp = val & CheckIfSigned[16];
    if (temp != 0)
        temp = (val | ConvertToSigned[16-1]);
    else
        temp=val;
    float ret = (temp+0.0)/LSB;
    return ret;
}
int convertBinarioToDecimal(int bin){
return 0;
}
int expNumber(int base,int exp){
    int nr = base;
    for(int i=0;i<exp;i++){
        nr *=nr;
    }
    return nr;
}


void swiCompensador(){
    if(enable_sys==0){
        if(quant_vz_comp == 5){
                enable_read_compensador = 0;
                ValorDeComp_acel_x /= 5;
                ValorDeComp_acel_y /= 5;
                ValorDeComp_acel_z /= 5;

                ValorDeComp_giro_x /= 5;
                ValorDeComp_giro_y /= 5;
                ValorDeComp_giro_z /= 5;

                enable_sys = 1;
            }else if(quant_vz_comp<5){
                enable_read_compensador = 1;
                Semaphore_post(semTask0);
            }
    }
}
void swiUPDATESTATUS(){
    //GPIOPinWrite(SOC_GPIO_1_REGS, USER_LED_1, GPIO_PIN_HIGH);
    if(enable_sys==1){
        Semaphore_post(semTask1);
    }

}
void swiSENDSTATUS(){
    //GPIOPinWrite(SOC_GPIO_1_REGS, USER_LED_2, GPIO_PIN_HIGH);
    if(enable_sys==1){
        Semaphore_post(semTask2);
    }
}

/*void swiFunc()
{
    UART_printStatus("\n Swi triggered. \n");
    Semaphore_post(semTask);
}
*/
int main(void)
{
    /* Call board init functions */


    I2C_socGetInitCfg(1, &i2c_cfg);
    I2C_socSetInitCfg(1, &i2c_cfg);
    I2C_init();

    Board_initGPIO();

    //System = 0;




    Task_Params task00Params;
    Task_Params task01Params;
    Task_Params task02Params;
    Task_Params task03Params;


    Task_Params_init(&task00Params);
    Task_Params_init(&task01Params);
    Task_Params_init(&task02Params);
    Task_Params_init(&task03Params);


    task00Params.stackSize = 0x1400;
    task01Params.stackSize = 0x1400;
    task02Params.stackSize = 0x1400;
    task03Params.stackSize = 0x1400;

    task00Params.priority = 15;
    task01Params.priority = 1;
    task02Params.priority = 2;
    task03Params.priority = 5;

    task0 = Task_create(tskCompensador, &task00Params, NULL);
    task1 = Task_create(tskGetvalorReal, &task01Params, NULL);
    task2 = Task_create(tskPLTdate, &task02Params, NULL);



    /* Create HWI*/
    Hwi_Params hwiParams;
    Hwi_Params_init(&hwiParams);
    hwiParams.enableInt = TRUE;
    Hwi_create(98, isrFunc, &hwiParams, NULL);
    Hwi_enableInterrupt(98);


    GPIODirModeSet(SOC_GPIO_1_REGS, 16,GPIO_CFG_INPUT);
    GPIOIntTypeSet(SOC_GPIO_1_REGS, 16, GPIO_INT_TYPE_RISE_EDGE);
    GPIOPinIntEnable(SOC_GPIO_1_REGS, GPIO_INT_LINE_1, 16);

    /* Create SWI */

    Swi_Params swiParams0;
    Swi_Params_init(&swiParams0);
    swi0 = Swi_create(swiCompensador, &swiParams0, NULL);
    Swi_Params swiParams1;
    Swi_Params_init(&swiParams1);
    swi1 = Swi_create(swiUPDATESTATUS, &swiParams1, NULL);
    Swi_Params swiParams2;
    Swi_Params_init(&swiParams2);
    swi2 = Swi_create(swiSENDSTATUS, &swiParams2, NULL);


    Swi_enable();


    GPIODirModeSet(SOC_GPIO_1_REGS, 21, GPIO_CFG_OUTPUT);
    GPIODirModeSet(SOC_GPIO_1_REGS, 22, GPIO_CFG_OUTPUT);
    GPIODirModeSet(SOC_GPIO_1_REGS, 23, GPIO_CFG_OUTPUT);
    GPIODirModeSet(SOC_GPIO_1_REGS, 24, GPIO_CFG_OUTPUT);



    /* Create Clock */

    Clock_Params clkParams0;
    Clock_Params_init(&clkParams0);
    clkParams0.startFlag=TRUE;
    clkParams0.period=1;
    myClock0 = Clock_create(swiCompensador,1,&clkParams0,NULL);

    Clock_Params clkParams1;
    Clock_Params_init(&clkParams1);
    clkParams1.startFlag=TRUE;
    clkParams1.period=1;
    myClock1 = Clock_create(swiUPDATESTATUS,1,&clkParams1,NULL);

    Clock_Params clkParams2;
    Clock_Params_init(&clkParams2);
    clkParams2.startFlag=TRUE;
    clkParams2.period=1;
    myClock2 = Clock_create(swiSENDSTATUS,1,&clkParams2,NULL);

    /* Create Semaphore */

    Semaphore_Params semParams0;
    Semaphore_Params_init(&semParams0);
    semParams0.mode = Semaphore_Mode_BINARY;
    semTask0 = Semaphore_create(1,&semParams0,NULL);

    Semaphore_Params semParams1;
    Semaphore_Params_init(&semParams1);
    semParams1.mode = Semaphore_Mode_BINARY;
    semTask1 = Semaphore_create(1,&semParams1,NULL);

    Semaphore_Params semParams2;
    Semaphore_Params_init(&semParams2);
    semParams2.mode = Semaphore_Mode_BINARY;
    semTask2 = Semaphore_create(1,&semParams2,NULL);




 #if defined(idkAM574x) || defined(idkAM572x) || defined(idkAM571x)
    AppGPIOInit();
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}
#endif

/*
 *  ======== AppDelay ========
 */
void AppDelay(unsigned int delayVal)
{
    while(delayVal)
    {
        delayVal--;
    }
}

/*
 *  ======== Callback function ========
 */
void AppGpioCallbackFxn(void)
{
    /* Toggle LED1 */
    GPIO_toggle(USER_LED1);
    AppDelay(DELAY_VALUE);
    gpio_intr_triggered = 1;
}


