#include <fcntl.h>
#include <unistd.h>

int isFimDeCurso()
{
	int sensor_fd;
	char s;
	sensor_fd=open("/sys/class/gpio/gpio13/value",O_RDONLY);

	
    lseek(sensor_fd,0,SEEK_SET);
    read(sensor_fd,&s,sizeof s);
	usleep(100);
	
	close(sensor_fd);

    if(strcmp(&s, '1') == 0) {
        return 1;
    }
    else {
	    return 0;
    }
}
