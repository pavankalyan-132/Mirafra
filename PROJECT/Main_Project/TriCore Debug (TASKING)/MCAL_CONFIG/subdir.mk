################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../MCAL_CONFIG/Port_PBcfg.c" 

COMPILED_SRCS += \
"MCAL_CONFIG/Port_PBcfg.src" 

C_DEPS += \
"./MCAL_CONFIG/Port_PBcfg.d" 

OBJS += \
"MCAL_CONFIG/Port_PBcfg.o" 


# Each subdirectory must supply rules for building sources it contributes
"MCAL_CONFIG/Port_PBcfg.src":"../MCAL_CONFIG/Port_PBcfg.c" "MCAL_CONFIG/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc39xb "-fC:/Users/Admin/AURIX-v1.10.36-workspace/Main_Project/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc39xb -Y0 -N0 -Z0 -o "$@" "$<"
"MCAL_CONFIG/Port_PBcfg.o":"MCAL_CONFIG/Port_PBcfg.src" "MCAL_CONFIG/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-MCAL_CONFIG

clean-MCAL_CONFIG:
	-$(RM) ./MCAL_CONFIG/Port_PBcfg.d ./MCAL_CONFIG/Port_PBcfg.o ./MCAL_CONFIG/Port_PBcfg.src

.PHONY: clean-MCAL_CONFIG

