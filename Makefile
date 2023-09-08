paint.out: main.o paint.o canvas.o commands.o 
	gcc -g -Wall -Werror -o paint.out main.o paint.o canvas.o commands.o 

main.o: main.c paint.h
	gcc -g -Wall -Werror -c main.c 

paint.o: paint.c canvas.h commands.h
	gcc -g -Wall -Werror -c paint.c 

canvas.o: canvas.c
	gcc -g -Wall -Werror -c canvas.c

commands.o: commands.c canvas.h
	gcc -g -Wall -Werror -c commands.c 

input_validation.o: input_validation.c
	gcc -g -Wall -Werror -c input_validation.c

