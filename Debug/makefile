################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/CCS9.0/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./AudioProcess/AudioProcess.obj" \
"./AudioProcess/FastMathApproximation.obj" \
"./Examples/Draft.obj" \
"./Examples/InputOutputLED.obj" \
"./Examples/TimerInterrupt.obj" \
"./PeripheralConfigure/PeripheralConfigure.obj" \
"./mini_library/mini_adc.obj" \
"./mini_library/mini_gpio.obj" \
"./mini_library/mini_interrupt.obj" \
"./mini_library/mini_ssi.obj" \
"./mini_library/mini_sysctl.obj" \
"./mini_library/mini_timer.obj" \
"E:/TI/TivaWare_2.1.4.178/driverlib/ccs/Debug/driverlib.lib" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include AudioProcess/subdir_vars.mk
-include Examples/subdir_vars.mk
-include PeripheralConfigure/subdir_vars.mk
-include mini_library/subdir_vars.mk
-include subdir_rules.mk
-include AudioProcess/subdir_rules.mk
-include Examples/subdir_rules.mk
-include PeripheralConfigure/subdir_rules.mk
-include mini_library/subdir_rules.mk
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
PedalProject.out \

EXE_OUTPUTS__QUOTED += \
"PedalProject.out" \

BIN_OUTPUTS += \
PedalProject.hex \

BIN_OUTPUTS__QUOTED += \
"PedalProject.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "PedalProject.out"

# Tool invocations
PedalProject.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"E:/CCS9.0/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"PedalProject.map" --heap_size=0 --stack_size=512 -i"E:/CCS9.0/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/lib" -i"E:/CCS9.0/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="PedalProject_linkInfo.xml" --rom_model -o "PedalProject.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

PedalProject.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"E:/CCS9.0/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armhex"  -o "PedalProject.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "AudioProcess\AudioProcess.obj" "AudioProcess\FastMathApproximation.obj" "Examples\Draft.obj" "Examples\InputOutputLED.obj" "Examples\TimerInterrupt.obj" "PeripheralConfigure\PeripheralConfigure.obj" "mini_library\mini_adc.obj" "mini_library\mini_gpio.obj" "mini_library\mini_interrupt.obj" "mini_library\mini_ssi.obj" "mini_library\mini_sysctl.obj" "mini_library\mini_timer.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "AudioProcess\AudioProcess.d" "AudioProcess\FastMathApproximation.d" "Examples\Draft.d" "Examples\InputOutputLED.d" "Examples\TimerInterrupt.d" "PeripheralConfigure\PeripheralConfigure.d" "mini_library\mini_adc.d" "mini_library\mini_gpio.d" "mini_library\mini_interrupt.d" "mini_library\mini_ssi.d" "mini_library\mini_sysctl.d" "mini_library\mini_timer.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

