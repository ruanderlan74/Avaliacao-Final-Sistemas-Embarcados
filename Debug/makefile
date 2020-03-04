################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update

GEN_OPTS__FLAG := @"configPkg/compiler.opt"
GEN_CMDS__FLAG := -Wl,-T"configPkg/linker.cmd"

ORDERED_OBJS += \
"./GPIO_bbbAM335x_board.o" \
"./GPIO_log.o" \
"./GPIO_soc.o" \
"./I2C_soc.o" \
"./UART_soc.o" \
"./convert.o" \
"./ftoa.o" \
"./main_led_blink.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-lrdimon \
-lgcc \
-lm \
-lnosys \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
GPIO_LedBlink_bbbAM335x_armTestProject.out \

EXE_OUTPUTS__QUOTED += \
"GPIO_LedBlink_bbbAM335x_armTestProject.out" \

BIN_OUTPUTS += \
GPIO_LedBlink_bbbAM335x_armTestProject.hex \

BIN_OUTPUTS__QUOTED += \
"GPIO_LedBlink_bbbAM335x_armTestProject.hex" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "GPIO_LedBlink_bbbAM335x_armTestProject.out"

# Tool invocations
GPIO_LedBlink_bbbAM335x_armTestProject.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-gcc" -mtune=cortex-a8 -marm -Dam3359 -DSOC_AM335x -DbbbAM335x -Og -g -gdwarf-3 -gstrict-dwarf -Wall -finstrument-functions -MMD -MP -mfloat-abi=hard -Wl,-Map,"GPIO_LedBlink_bbbAM335x_armTestProject.map" -nostartfiles -static -Wl,--gc-sections -L"/home/ruan/ti/bios_6_52_00_12/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/hard" -Wl,--defsym,STACKSIZE=0x1C000 -Wl,--defsym,HEAPSIZE=0x400 --specs=nano.specs -o"GPIO_LedBlink_bbbAM335x_armTestProject.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

GPIO_LedBlink_bbbAM335x_armTestProject.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"/home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update/bin/arm-none-eabi-objcopy"  $(EXE_OUTPUTS__QUOTED) "GPIO_LedBlink_bbbAM335x_armTestProject.hex"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "GPIO_bbbAM335x_board.o" "GPIO_log.o" "GPIO_soc.o" "I2C_soc.o" "UART_soc.o" "convert.o" "ftoa.o" "main_led_blink.o" 
	-$(RM) "GPIO_bbbAM335x_board.d" "GPIO_log.d" "GPIO_soc.d" "I2C_soc.d" "UART_soc.d" "convert.d" "ftoa.d" "main_led_blink.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-/home/ruan/ti/pdk_am335x_1_0_9/packages/pdkAppImageCreate.sh /home/ruan/ti/pdk_am335x_1_0_9/packages /home/ruan/ti/gcc-arm-none-eabi-6-2017-q1-update /home/ruan/Área de Trabalho/GPIO_LedBlink_bbbAM335x_armTestProject/Debug GPIO_LedBlink_bbbAM335x_armTestProject AM335x arm
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

