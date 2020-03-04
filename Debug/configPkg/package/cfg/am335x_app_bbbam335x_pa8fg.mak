#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.A8F{1,0,6.3,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg.dep
package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg.dep: ;
endif

package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg: | .interfaces
package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg: package/cfg/am335x_app_bbbam335x_pa8fg.c package/cfg/am335x_app_bbbam335x_pa8fg.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cla8fg $< ...
	$(gnu.targets.arm.A8F.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -D_DEBUG_=1  -Dxdc_cfg__xheader__='"configPkg/package/cfg/am335x_app_bbbam335x_pa8fg.h"'  -Dxdc_target_name__=A8F -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_6_3_1 -g -I/home/ruan/ti/bios_6_52_00_12/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include/newlib-nano  -I/home/ruan/ti/bios_6_52_00_12/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg: export LD_LIBRARY_PATH=

package/cfg/am335x_app_bbbam335x_pa8fg.sa8fg: | .interfaces
package/cfg/am335x_app_bbbam335x_pa8fg.sa8fg: package/cfg/am335x_app_bbbam335x_pa8fg.c package/cfg/am335x_app_bbbam335x_pa8fg.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cla8fg -S $< ...
	$(gnu.targets.arm.A8F.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=hard -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -D_DEBUG_=1  -Dxdc_cfg__xheader__='"configPkg/package/cfg/am335x_app_bbbam335x_pa8fg.h"'  -Dxdc_target_name__=A8F -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_6_3_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/am335x_app_bbbam335x_pa8fg.sa8fg: export LD_LIBRARY_PATH=

clean,a8fg ::
	-$(RM) package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg
	-$(RM) package/cfg/am335x_app_bbbam335x_pa8fg.sa8fg

am335x_app_bbbam335x.pa8fg: package/cfg/am335x_app_bbbam335x_pa8fg.oa8fg package/cfg/am335x_app_bbbam335x_pa8fg.mak

clean::
	-$(RM) package/cfg/am335x_app_bbbam335x_pa8fg.mak
