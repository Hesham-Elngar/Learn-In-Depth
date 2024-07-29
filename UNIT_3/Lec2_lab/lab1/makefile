#copyright:Hesham
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I
LIBS=
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)

all: hesham.bin
	@echo "Build is Done"
	  	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

$(ASOBJ): $(AS)
	$(CC)as.exe $< -o $@

hesham.elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@
	
hesham.bin: hesham.elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	del *.bin, *.o, *.elf	

clean:
	del *.bin, *.elf