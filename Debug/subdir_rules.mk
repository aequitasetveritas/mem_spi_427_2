################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"/home/escualo/ti/gcc/bin/msp430-elf-gcc" -c -mmcu=msp430fe427a -I"/home/escualo/ti/gcc/msp430-elf/include" -I"/home/escualo/ti/ccsv6/ccs_base/msp430/include_gcc" -Os -g -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


