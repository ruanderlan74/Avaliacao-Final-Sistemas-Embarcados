#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/ruan/ti/bios_6_52_00_12/packages;/home/ruan/ti/pdk_am335x_1_0_9/packages;/home/ruan/ti/edma3_lld_2_12_05_30B/packages;/home/ruan/ti/ndk_2_26_00_08/packages
override XDCROOT = /home/ruan/ti/xdctools_3_50_03_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/ruan/ti/bios_6_52_00_12/packages;/home/ruan/ti/pdk_am335x_1_0_9/packages;/home/ruan/ti/edma3_lld_2_12_05_30B/packages;/home/ruan/ti/ndk_2_26_00_08/packages;/home/ruan/ti/xdctools_3_50_03_33_core/packages;..
HOSTOS = Linux
endif
