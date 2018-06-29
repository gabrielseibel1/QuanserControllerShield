#! /bin/sh
### BEGIN INIT INFO
# Provides:          quanserinit
# Required-Start:    
# Should-Start:      
# Required-Stop:     
# Default-Start:     S
# Default-Stop:
# Short-Description: Configures GPIO for QuanserShield.
# Description:       Configures GPIO for QuanserShield.
### END INIT INFO

case "$1" in
    start|restart|force-reload)
    #GPIO SENSORS
	if [ ! -d /sys/class/gpio/gpio13 ] ; then
	    echo -n "13" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio13/direction
	chgrp gpio /sys/class/gpio/gpio13/value
	chmod g+r /sys/class/gpio/gpio13/value
	
	if [ ! -d /sys/class/gpio/gpio34 ] ; then
	    echo -n "34" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio34/direction
	echo -n "1" > /sys/class/gpio/gpio34/value

	if [ ! -d /sys/class/gpio/gpio35 ] ; then
	    echo -n "35" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio35/direction
	echo -n "0" > /sys/class/gpio/gpio35/value
	
	if [ ! -d /sys/class/gpio/gpio77 ] ; then
	    echo -n "77" > /sys/class/gpio/export
	fi
#	echo -n "out" > /sys/class/gpio/gpio77/direction
	echo -n "0" > /sys/class/gpio/gpio77/value

    if [ ! -d /sys/class/gpio/gpio14 ] ; then
	    echo -n "14" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio14/direction
	chgrp gpio /sys/class/gpio/gpio14/value
	chmod g+r /sys/class/gpio/gpio14/value
	
	if [ ! -d /sys/class/gpio/gpio16 ] ; then
	    echo -n "16" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio16/direction
	echo -n "1" > /sys/class/gpio/gpio16/value

	if [ ! -d /sys/class/gpio/gpio17 ] ; then
	    echo -n "17" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio17/direction
	echo -n "0" > /sys/class/gpio/gpio17/value
	
	if [ ! -d /sys/class/gpio/gpio76 ] ; then
	    echo -n "76" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio76/direction
	echo -n "0" > /sys/class/gpio/gpio76/value
    
	if [ ! -d /sys/class/gpio/gpio64 ] ; then
	    echo -n "64" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio64/direction
	echo -n "0" > /sys/class/gpio/gpio64/value
    
    #GPIO MOTOR ENABLE
    if [ ! -d /sys/class/gpio/gpio38 ] ; then
	    echo -n "38" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio38/direction
	echo -n "0" > /sys/class/gpio/gpio38/value
	chgrp gpio /sys/class/gpio/gpio38/value
	chmod g+r /sys/class/gpio/gpio38/value
	
	if [ ! -d /sys/class/gpio/gpio39 ] ; then
	    echo -n "39" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio39/direction

    #PWM MOTOR
        # IO5 = pwm3
	if [ ! -d /sys/class/pwm/pwmchip0/pwm3 ] ; then
	    echo -n "3" > /sys/class/pwm/pwmchip0/export
	fi
	chgrp quanser /sys/class/pwm/pwmchip0/device/pwm_period
	chmod g+w /sys/class/pwm/pwmchip0/device/pwm_period
	chgrp quanser /sys/class/pwm/pwmchip0/pwm3/duty_cycle
	chmod g+w /sys/class/pwm/pwmchip0/pwm3/duty_cycle
	chgrp quanser /sys/class/pwm/pwmchip0/pwm3/enable
	chmod g+w /sys/class/pwm/pwmchip0/pwm3/enable
        
        # gpio16 = 0 = out
	if [ ! -d /sys/class/gpio/gpio18 ] ; then
	    echo -n "18" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio18/direction
	echo -n "0" > /sys/class/gpio/gpio18/value

        # gpio19 = in = no pull-up nor pull-down
	if [ ! -d /sys/class/gpio/gpio19 ] ; then
	    echo -n "19" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio19/direction
        
        # gpio76 = 0
	if [ ! -d /sys/class/gpio/gpio66 ] ; then
	    echo -n "66" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio66/direction
	echo -n "1" > /sys/class/gpio/gpio66/value

    #SPI
    # Configures IO10 for SPI #SS
	#	gpio26=0 (output)
	#	gpio27=1 (pull-up)
	#	gpio74=0 (IO10 is GPIO)
	if [ ! -d /sys/class/gpio/gpio26 ] ; then
	    echo -n "26" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio26/direction
	echo -n "0" > /sys/class/gpio/gpio26/value
	
	if [ ! -d /sys/class/gpio/gpio27 ] ; then
	    echo -n "27" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio27/direction
	echo -n "1" > /sys/class/gpio/gpio27/value
	
	if [ ! -d /sys/class/gpio/gpio74 ] ; then
	    echo -n "74" > /sys/class/gpio/export
	fi
	echo -n "0" > /sys/class/gpio/gpio74/value
	
	# Configures IO11 for SPI MOSI
	#	gpio24=0 (output)
	#	gpio25=input (floating)
	#	gpio44=1 (IO11 is SPI)
	#	gpio72=0 (IO11 is SPI)
	if [ ! -d /sys/class/gpio/gpio24 ] ; then
	    echo -n "24" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio24/direction
	echo -n "0" > /sys/class/gpio/gpio24/value
	
	if [ ! -d /sys/class/gpio/gpio25 ] ; then
	    echo -n "25" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio25/direction
	
	if [ ! -d /sys/class/gpio/gpio44 ] ; then
	    echo -n "44" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio44/direction
	echo -n "1" > /sys/class/gpio/gpio44/value
	
	if [ ! -d /sys/class/gpio/gpio72 ] ; then
	    echo -n "72" > /sys/class/gpio/export
	fi
	echo -n "0" > /sys/class/gpio/gpio72/value

	# Configures IO12 for SPI MISO
	#	gpio42=1 (input)
	#	gpio43=input (floating)
	if [ ! -d /sys/class/gpio/gpio42 ] ; then
	    echo -n "42" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio42/direction
	echo -n "1" > /sys/class/gpio/gpio42/value
	
	if [ ! -d /sys/class/gpio/gpio43 ] ; then
	    echo -n "43" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio43/direction

	# Configure IO13 for SPI SCLK
	#	gpio30=0 (output)
	#	gpio31=0 (pull-down, SCLK mode 0)
	#	gpio46=1 (IO13 is SPI)
	if [ ! -d /sys/class/gpio/gpio30 ] ; then
	    echo -n "30" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio30/direction
	echo -n "0" > /sys/class/gpio/gpio30/value
	
	if [ ! -d /sys/class/gpio/gpio31 ] ; then
	    echo -n "31" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio31/direction
	echo -n "0" > /sys/class/gpio/gpio31/value
	
	if [ ! -d /sys/class/gpio/gpio46 ] ; then
	    echo -n "46" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio46/direction
	echo -n "1" > /sys/class/gpio/gpio46/value

        chgrp quanser /dev/spidev1.0
        chmod g+rw /dev/spidev1.0

    #LFLAG
    # IO6 = gpio1
	if [ ! -d /sys/class/gpio/gpio1 ] ; then
	    echo -n "1" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio1/direction
	chgrp gpio /sys/class/gpio/gpio1/value
	chmod g+r /sys/class/gpio/gpio1/value

	# gpio20 = 1 => IO6=in	
	if [ ! -d /sys/class/gpio/gpio20 ] ; then
	    echo -n "20" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio20/direction
	echo -n "1" > /sys/class/gpio/gpio20/value

	# gpio21 = in => none
	if [ ! -d /sys/class/gpio/gpio21 ] ; then
	    echo -n "21" > /sys/class/gpio/export
	fi
	echo -n "in" > /sys/class/gpio/gpio21/direction

	if [ ! -d /sys/class/gpio/gpio68 ] ; then
	    echo -n "68" > /sys/class/gpio/export
	fi
	echo -n "out" > /sys/class/gpio/gpio68/direction
	echo -n "0" > /sys/class/gpio/gpio68/value

	;;
    stop)
    #GPIO SENSORS
    	echo -n "13" > /sys/class/gpio/unexport
	echo -n "34" > /sys/class/gpio/unexport
	echo -n "35" > /sys/class/gpio/unexport
	echo -n "77" > /sys/class/gpio/unexport
    	echo -n "14" > /sys/class/gpio/unexport
	echo -n "16" > /sys/class/gpio/unexport
	echo -n "17" > /sys/class/gpio/unexport
	echo -n "76" > /sys/class/gpio/unexport
	echo -n "64" > /sys/class/gpio/unexport

    #GPIO MOTOR ENABLE
        echo -n "38" > /sys/class/gpio/unexport
	echo -n "39" > /sys/class/gpio/unexport

    #PWM MOTOR
    echo -n "0" > /sys/class/pwm/pwmchip0/pwm3/enable
        echo -n "66" > /sys/class/gpio/unexport
	echo -n "19" > /sys/class/gpio/unexport
	echo -n "1" > /sys/class/gpio/gpio18/value
	echo -n "18" > /sys/class/gpio/unexport
	echo -n "1" > /sys/class/pwm/pwmchip0/unexport

    #SPI
    echo -n "1" > /sys/class/gpio/gpio26/value
	echo -n "26" > /sys/class/gpio/unexport
	
	echo -n "in" > /sys/class/gpio/gpio27/direction
	
	echo -n "74" > /sys/class/gpio/unexport
	
	echo -n "1" > /sys/class/gpio/gpio24/value
	echo -n "24" > /sys/class/gpio/unexport
	
	echo -n "25" > /sys/class/gpio/unexport

	echo -n "0" > /sys/class/gpio/gpio44/value
	echo -n "44" > /sys/class/gpio/unexport
	
	echo -n "72" > /sys/class/gpio/unexport

	echo -n "42" > /sys/class/gpio/unexport

	echo -n "43" > /sys/class/gpio/unexport

	echo -n "0" > /sys/class/gpio/gpio46/value
	echo -n "46" > /sys/class/gpio/unexport
	
	echo -n "in" > /sys/class/gpio/gpio31/direction
	echo -n "31" > /sys/class/gpio/unexport
	
	echo -n "1" > /sys/class/gpio/gpio30/value
	echo -n "30" > /sys/class/gpio/unexport

    #LFLAG
    echo -n "1" > /sys/class/gpio/unexport
	echo -n "20" > /sys/class/gpio/unexport
	echo -n "21" > /sys/class/gpio/unexport
	echo -n "68" > /sys/class/gpio/unexport

	;;
    status)
        #GPIO SENSORS
    	ls -d /sys/class/gpio/gpio*

        #PWM MOTOR
        echo -n Period:
    	cat /sys/class/pwm/pwmchip0/device/pwm_period
    	echo -n Duty Cicle:
    	cat /sys/class/pwm/pwmchip0/pwm1/duty_cycle
    	echo -n Enable:
    	cat /sys/class/pwm/pwmchip0/pwm1/enable
	;;
    *)
	echo -n "Usage: $0 " 
	echo "{start|stop|restart|force-reload|status}"
	exit 1
	;;
esac

exit 0
