@echo off

set file="./rtthread.bin"
set flash_addr=0x08000000
set board_cfg="board/st_nucleo_f7.cfg"

echo flash fw for board_config %board_cfg%, file %file%, flash_addr %flash_addr%

if not exist %file% (
    echo Missing file "%file%"
    pause
)

tasklist | find /i "openocd.exe" >nul 2>nul && set status="running" || set status="stop"

if %status% == "stop" (
    echo status is stop
    openocd -s /usr/local/share/openocd/scripts -f %board_cfg% -c "reset_config connect_assert_srst srst_only;init;reset init;program %file% %flash_addr% verify reset exit"
) else (
    echo status is running
)
