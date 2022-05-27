all:
	gcc -g -c main.c
	gcc -g -c ./modules/linked_list/linked_list.c
	gcc -g -c ./modules/utils/utils.c
	gcc -o main *.o
	rm *.o
