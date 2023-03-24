cc := "gcc"

alias r := run
alias b := build

build:
	{{ cc  }} *.c commands/*.c -o main
run: build
	./main
