################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ADC.obj: ../ADC.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmsp --abi=eabi -O2 --use_hw_mpy=none --include_path="/home/ecoprt/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --define=__MSP430F2012__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="ADC.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

clocks.obj: ../clocks.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmsp --abi=eabi -O2 --use_hw_mpy=none --include_path="/home/ecoprt/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --define=__MSP430F2012__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="clocks.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmsp --abi=eabi -O2 --use_hw_mpy=none --include_path="/home/ecoprt/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --define=__MSP430F2012__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ports.obj: ../ports.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmsp --abi=eabi -O2 --use_hw_mpy=none --include_path="/home/ecoprt/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --define=__MSP430F2012__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="ports.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

timers.obj: ../timers.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmsp --abi=eabi -O2 --use_hw_mpy=none --include_path="/home/ecoprt/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/ecoprt/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --define=__MSP430F2012__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="timers.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


