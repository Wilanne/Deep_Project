################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/tft_ili9341/stm32f1_fonts.c \
../Lib/tft_ili9341/stm32f1_ili9341.c \
../Lib/tft_ili9341/stm32f1_xpt2046.c 

OBJS += \
./Lib/tft_ili9341/stm32f1_fonts.o \
./Lib/tft_ili9341/stm32f1_ili9341.o \
./Lib/tft_ili9341/stm32f1_xpt2046.o 

C_DEPS += \
./Lib/tft_ili9341/stm32f1_fonts.d \
./Lib/tft_ili9341/stm32f1_ili9341.d \
./Lib/tft_ili9341/stm32f1_xpt2046.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/tft_ili9341/%.o: ../Lib/tft_ili9341/%.c Lib/tft_ili9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

