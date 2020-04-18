#!/bin/sh
file="./rtthread.bin"
flash_addr=0x08000000
board_cfg="board/st_nucleo_f7.cfg"

echo "flash fw for board_config $board_cfg, file $file, flash_addr $flash_addr"

if [ ! -r ${file} ]; then
    echo "Missing file \"${file}\""
    exit 1
fi

if [ -z "$(pidof openocd)" ]; then
    openocd -s /usr/local/share/openocd/scripts -f $board_cfg -c "reset_config connect_assert_srst srst_only;init;reset init;program ${file} ${flash_addr} verify reset exit"
else
    # Use absolute path; we don't know in which folder openocd has been started
    absfile="$(cd "$(dirname "${file}")"; pwd)/$(basename "${file}")"
    pipe="/tmp/$$.pipe"
    mkfifo ${pipe}
    telnet localhost 4444 < ${pipe} &
    telnet_pid=$!
    exec 6> "${pipe}"
    echo "reset init;program ${absfile} ${flash_addr} verify reset;exit" >&6
    wait ${telnet_pid}
    exec 6>&-
    rm ${pipe}
fi
