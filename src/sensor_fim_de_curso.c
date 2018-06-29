#include <fcntl.h>
#include <unistd.h>

int isFimDeCurso()
{
	int sensor_fd;
	char s_elb1, s_elb2;
	sensor_elb1_fd=open("/sys/class/gpio/gpio62/value",O_RDONLY);
	sensor_elb2_fd=open("/sys/class/gpio/gpio13/value",O_RDONLY);

	
    lseek(sensor_elb1_fd,0,SEEK_SET);
    read(sensor_elb1_fd,&s_elb1,sizeof s_elb1);
    lseek(sensor_elb2_fd,0,SEEK_SET);
    read(sensor_elb2_fd,&s_elb2,sizeof s_elb2);
	usleep(100);
	
	close(sensor_elb1_fd);
	close(sensor_elb2_fd);

    if(s_elb1 == '1' && s_elb2 == '1') {
        return 1;
    }
    else {
	    return 0;
    }
}
