SINAIS = 3.1.o 3.2.o 3.2execl.o #...
all: ${SINAIS} 
    gcc ${SINAIS} -o sinais_bin
%.o: %.c
    gcc -c $*.c
clean:
    rm -rf *.o
    rm sinais_bin