################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
i2c_master.lss \

FLASH_IMAGE += \
i2c_master.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: i2c_master.elf secondary-outputs

# Tool invocations
i2c_master.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,i2c_master.map -mmcu=atmega32 -o "i2c_master.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

i2c_master.lss: i2c_master.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S i2c_master.elf  >"i2c_master.lss"
	@echo 'Finished building: $@'
	@echo ' '

i2c_master.hex: i2c_master.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex i2c_master.elf  "i2c_master.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: i2c_master.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 i2c_master.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) i2c_master.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
