#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	const char* file = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	ssize_t n;
	int fd;
	
	fd = open(file, O_RDONLY);
	
	if (fd == -1){
		printf("Error access");
		return -1;
	}
	
	while (1){
		n = read(fd, &ev, sizeof ev);
		//printf("type: %x, %d",ev.code, ev.type);
		if (ev.type == 1) {
			if (ev.value == 1){
				printf("PRESSED %x (%i)", ev.code, ev.code);
			} else if (ev.value == 1){
				printf("RELEASED %x (%i)", ev.code, ev.code);
			}
		}
	} 
	return 0;
}