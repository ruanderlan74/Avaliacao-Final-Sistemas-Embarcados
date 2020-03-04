## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,a8fg linker.cmd package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/am335x_app_bbbam335x_pa8fg.xdl
	$(SED) 's"^\"\(package/cfg/am335x_app_bbbam335x_pa8fgcfg.cmd\)\"$""\"/home/ruan/ti/pdk_am335x_1_0_9/packages/MyExampleProjects/GPIO_LedBlink_bbbAM335x_armTestProject/Debug/configPkg/\1\""' package/cfg/am335x_app_bbbam335x_pa8fg.xdl > $@
	-$(SETDATE) -r:max package/cfg/am335x_app_bbbam335x_pa8fg.h compiler.opt compiler.opt.defs
