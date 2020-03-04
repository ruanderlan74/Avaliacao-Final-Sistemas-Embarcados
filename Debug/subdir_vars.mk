################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
/home/ruan/ti/drv/gpio/test/led_blink/am335x/armv7/bios/am335x_app_bbbam335x.cfg 

C_SRCS += \
/home/ruan/ti/drv/gpio/test/led_blink/src/am335x/GPIO_bbbAM335x_board.c \
/home/ruan/ti/drv/gpio/test/led_blink/src/GPIO_log.c \
/home/ruan/ti/drv/gpio/soc/am335x/GPIO_soc.c \
/home/ruan/ti/drv/i2c/soc/am335x/I2C_soc.c \
/home/ruan/ti/drv/uart/soc/am335x/UART_soc.c \
../convert.c \
../ftoa.c \
/home/ruan/ti/drv/gpio/test/led_blink/src/main_led_blink.c 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_MISC_DIRS += \
./configPkg/ 

C_DEPS += \
./GPIO_bbbAM335x_board.d \
./GPIO_log.d \
./GPIO_soc.d \
./I2C_soc.d \
./UART_soc.d \
./convert.d \
./ftoa.d \
./main_led_blink.d 

GEN_OPTS += \
./configPkg/compiler.opt 

OBJS += \
./GPIO_bbbAM335x_board.o \
./GPIO_log.o \
./GPIO_soc.o \
./I2C_soc.o \
./UART_soc.o \
./convert.o \
./ftoa.o \
./main_led_blink.o 

GEN_MISC_DIRS__QUOTED += \
"configPkg/" 

OBJS__QUOTED += \
"GPIO_bbbAM335x_board.o" \
"GPIO_log.o" \
"GPIO_soc.o" \
"I2C_soc.o" \
"UART_soc.o" \
"convert.o" \
"ftoa.o" \
"main_led_blink.o" 

C_DEPS__QUOTED += \
"GPIO_bbbAM335x_board.d" \
"GPIO_log.d" \
"GPIO_soc.d" \
"I2C_soc.d" \
"UART_soc.d" \
"convert.d" \
"ftoa.d" \
"main_led_blink.d" 

GEN_FILES__QUOTED += \
"configPkg/linker.cmd" \
"configPkg/compiler.opt" 

C_SRCS__QUOTED += \
"/home/ruan/ti/drv/gpio/test/led_blink/src/am335x/GPIO_bbbAM335x_board.c" \
"/home/ruan/ti/drv/gpio/test/led_blink/src/GPIO_log.c" \
"/home/ruan/ti/drv/gpio/soc/am335x/GPIO_soc.c" \
"/home/ruan/ti/drv/i2c/soc/am335x/I2C_soc.c" \
"/home/ruan/ti/drv/uart/soc/am335x/UART_soc.c" \
"../convert.c" \
"../ftoa.c" \
"/home/ruan/ti/drv/gpio/test/led_blink/src/main_led_blink.c" 


