@echo off
rmdir app\firmware\demo.X\.generated_files /S/Q
rmdir app\firmware\demo.X\debug /S/Q
rmdir app\firmware\demo.X\build /S/Q
rmdir app\firmware\demo.X\report /S/Q
rmdir app\firmware\demo.X\dist\default /S/Q
rmdir app\firmware\demo.X\dist\release\debug /S/Q
rmdir app\firmware\demo.X\nbproject\private /S/Q
del   app\firmware\demo.X\nbproject\Makefile* /F/Q
del   app\firmware\demo.X\nbproject\Package* /F/Q

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