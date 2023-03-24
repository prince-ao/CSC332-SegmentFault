#include "helloWorld.h"

void helloWorld(){
	char *dummy_text = "Hello, World!\n";
	write(STDOUT_FILENO, dummy_text, strlen(dummy_text));
}
