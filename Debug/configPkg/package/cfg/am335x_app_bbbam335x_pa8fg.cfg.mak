# invoke SourceDir generated makefile for am335x_app_bbbam335x.pa8fg
am335x_app_bbbam335x.pa8fg: .libraries,am335x_app_bbbam335x.pa8fg
.libraries,am335x_app_bbbam335x.pa8fg: package/cfg/am335x_app_bbbam335x_pa8fg.xdl
	$(MAKE) -f /home/ruan/ti/pdk_am335x_1_0_9/packages/ti/drv/gpio/test/led_blink/am335x/armv7/bios/src/makefile.libs

clean::
	$(MAKE) -f /home/ruan/ti/pdk_am335x_1_0_9/packages/ti/drv/gpio/test/led_blink/am335x/armv7/bios/src/makefile.libs clean

