@echo off
rmdir dsPIC33_tc6.X\.generated_files /S/Q
rmdir dsPIC33_tc6.X\debug /S/Q
rmdir dsPIC33_tc6.X\build /S/Q
rmdir dsPIC33_tc6.X\report /S/Q
rmdir dsPIC33_tc6.X\dist\default /S/Q
rmdir dsPIC33_tc6.X\dist\release\debug /S/Q
rmdir dsPIC33_tc6.X\nbproject\private /S/Q
del   dsPIC33_tc6.X\nbproject\Makefile* /F/Q
del   dsPIC33_tc6.X\nbproject\Package* /F/Q

rmdir liblwip.X\.generated_files /S/Q
rmdir liblwip.X\debug /S/Q
rmdir liblwip.X\report /S/Q
rmdir liblwip.X\build /S/Q
rmdir liblwip.X\dist\default /S/Q
rmdir liblwip.X\dist\release\debug /S/Q
rmdir liblwip.X\nbproject\private /S/Q
del   liblwip.X\nbproject\Makefile* /F/Q
del   liblwip.X\nbproject\Package* /F/Q

rmdir libtc6.X\.generated_files /S/Q
rmdir libtc6.X\debug /S/Q
rmdir libtc6.X\report /S/Q
rmdir libtc6.X\build /S/Q
rmdir libtc6.X\dist\default /S/Q
rmdir libtc6.X\dist\release\debug /S/Q
rmdir libtc6.X\nbproject\private /S/Q
del   libtc6.X\nbproject\Makefile* /F/Q
del   libtc6.X\nbproject\Package* /F/Q

pause