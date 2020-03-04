################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
GPIO_bbbAM335x_board.o: /home/ruan/ti/drv/gpio/test/led_blink/src/am335x/GPIO_bbbAM335x_board.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"GPIO_bbbAM335x_board.d" -MT"GPIO_bbbAM335x_board.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

GPIO_log.o: /home/ruan/ti/drv/gpio/test/led_blink/src/GPIO_log.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"GPIO_log.d" -MT"GPIO_log.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

GPIO_soc.o: /home/ruan/ti/drv/gpio/soc/am335x/GPIO_soc.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"GPIO_soc.d" -MT"GPIO_soc.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

I2C_soc.o: /home/ruan/ti/drv/i2c/soc/am335x/I2C_soc.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"I2C_soc.d" -MT"I2C_soc.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

UART_soc.o: /home/ruan/ti/drv/uart/soc/am335x/UART_soc.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"UART_soc.d" -MT"UART_soc.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

build-861389649:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-861389649-inproc

build-861389649-inproc: /home/ruan/ti/drv/gpio/test/led_blink/am335x/armv7/bios/am335x_app_bbbam335x.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"/home/ruan/ti/xdctools_3_50_03_33_core/xs" --xdcpath="/home/ruan/ti/bios_6_52_00_12/packages;/home/ruan/ti/pdk_am335x_1_0_9/packages;/home/ruan/ti/edma3_lld_2_12_05_30B/packages;/home/ruan/ti/ndk_2_26_00_08/packages;" xdc.tools.configuro -o configPkg -t gnu.targets.arm.A8F -p ti.platforms.evmAM3359 -r debug -c "/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-861389649 /home/ruan/ti/drv/gpio/test/led_blink/am335x/armv7/bios/am335x_app_bbbam335x.cfg
configPkg/compiler.opt: build-861389649
configPkg/: build-861389649

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

main_led_blink.o: /home/ruan/ti/drv/gpio/test/led_blink/src/main_led_blink.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -c -mcpu=cortex-a8 -march=armv7-a -mtune=cortex-a8 -marm -mfloat-abi=hard -Dam3359 -DSOC_AM335x -DbbbAM335x -I"/home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano" -I"/home/ruan/ti/drv/gpio" -I"/home/ruan" -I"/packages" -I"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -c -finstrument-functions -MMD -MP -MMD -MP -MF"main_led_blink.d" -MT"main_led_blink.d"  $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


