#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// this prints the character out
void show_char(char* thing_to_echo){
	printf("the character is %s\n",thing_to_echo);
}

// this shows what command it's going to send and then does it
void send_event(int first, int second){
	char one[16], two[16];
	char device[] = "/dev/input/event0";
	char command[256];
	sprintf(one, "%d", first);
	sprintf(two, "%d", second);
	snprintf(command, sizeof command, "input tap %s %s",one,two);
	printf("%s\n",command);

	system(command);
}

int main(int argc, char **argv){
	int fd;
	if (argc !=2){
		printf("Usage: %s <device>\n",argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	struct input_event ev;

	while(1){
		read(fd, &ev, sizeof(struct input_event));
		if(ev.type==1){
			// 0 is being released
			// 1 corresponds to the key being pressed
			// 2 is held
			if(ev.value == 1 || ev.value== 0){
				switch(ev.code){
					case 17:
						show_char("LEFT ARM");
						// PUNCH
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 78; sendevent /dev/input/event0 3 53 435; sendevent /dev/input/event0 3 54 2111; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 30:
						show_char("RIGHT ARM");
						// INTERACT
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 46; sendevent /dev/input/event0 3 53 381; sendevent /dev/input/event0 3 54 2111; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 31:
						show_char("RIGHT NIPPLE");
						// DANCE
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 80; sendevent /dev/input/event0 3 53 529; sendevent /dev/input/event0 3 54 2087; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 32:
						show_char("RIGHT LEG");
						// MOVE LEFT
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 44; sendevent /dev/input/event0 3 53 275; sendevent /dev/input/event0 3 54 2107; sendevent /dev/input/event0 0 0 0");
					}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 33:
						show_char("LEFT LEG");
						// MOVE RIGHT
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 43; sendevent /dev/input/event0 3 53 239; sendevent /dev/input/event0 3 54 2101; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 34:
						show_char("LEFT NIPPLE");
						// JUMP
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 45; sendevent /dev/input/event0 3 58 3; sendevent /dev/input/event0 3 53 327; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 57:
						show_char("EAR");
						// LASERS
						if(ev.value == 1){
							system("sendevent /dev/input/event0 3 57 79; sendevent /dev/input/event0 3 53 494; sendevent /dev/input/event0 3 54 2105; sendevent /dev/input/event0 0 0 0");
						}
						else{
							system("sendevent /dev/input/event0 3 57 4294967295; sendevent /dev/input/event0 0 0 0");
						}
						break;
					case 36:
						show_char("j");
						break;
				}
			}
		}
	}

	return 1;
}
