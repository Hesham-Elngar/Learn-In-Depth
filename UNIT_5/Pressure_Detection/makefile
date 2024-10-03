#copyright:Hesham
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I
LIBS=
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=Pressure_Sensor_Project

all: $(Project_name).bin
	@echo "Build is Done"
	  	
%.o: %.c
	$(CC)gcc.exe -c -g $(CFLAGS) $< -o $@

$(ASOBJ): $(AS)
	$(CC)as.exe $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	del *.bin, *.o, *.elf	

clean:
	del *.bin, *.elf