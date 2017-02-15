
all:
	-@mkdir -p bin
	gcc main.c -lcurl -o bin/main
