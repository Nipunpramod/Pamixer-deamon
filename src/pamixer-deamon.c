#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define SILENT_KEY 113  //Change this value according to the code recived from Findkeys 
#define VOLUME_DOWN_KEY 114  // ....
#define VOLUME_UP_KEY 115	// ....

void findDevice(char*);

int main(int argc, char const *argv[])
{
	struct input_event ev;
	char device[256];
	findDevice(device);
	int fd = open(device,O_RDONLY);
	setuid(1000);
	if (fd==-1){
		 perror("error");
		 return 1;
	}
	setenv("XDG_RUNTIME_DIR","/run/user/1000",0);
	while(1){
		read(fd,&ev,sizeof(ev));
		if (ev.type == EV_KEY && ev.value == 1){
			switch(ev.code){
				case VOLUME_DOWN_KEY:
					system("/usr/bin/pamixer -d 5 > /dev/null 2>&1");
					sleep(0.1);
					break;
				case VOLUME_UP_KEY:
					system("/usr/bin/pamixer -i 5 > /dev/null 2>&1");
					sleep(0.1);
					break;
				case SILENT_KEY:
					system("/usr/bin/pamixer -t > /dev/null 2>&1");
					sleep(0.1);
					break;
			}
		}		
	}
	close(fd);
	return 0;
}
void findDevice(char *dev){
	FILE* file = fopen("/opt/pamixer/config.txt","r");
	if(file == NULL)printf("%s\n","config file not found !");
	fgets(dev,256,file);
	int index = strlen(dev);
	dev[index-1]='\0';
	fclose(file);

}

