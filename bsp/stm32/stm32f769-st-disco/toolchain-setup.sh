#!/bin/bash

BASEPATH=$(cd `dirname $0`; pwd)
[[ $_ != $0 ]] && echo "configuring external toolchain" || (echo "Script has to be sourced" && exit 1)

if [ ! -e $HOME/toolchains/gcc-arm-none-eabi-9-2019-q4-major/bin ] ; then
    echo Toolchain is not found, downloading
    (mkdir -p $HOME/toolchains && cd $HOME/toolchains &&
     wget --no-check-certificate https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2 &&
     tar xjf gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2 &&
     echo Toolchain download done
    ) || (echo Toolchain download failed)
fi

export ARM_NONE_GCC_PATH=$HOME/toolchains/gcc-arm-none-eabi-9-2019-q4-major
export CROSS_COMPILE=$ARM_NONE_GCC_PATH/bin/arm-none-eabi-
C_PATH=$C_PATH:$C_INCLUDE_PATH:$ARM_NONE_GCC_PATH/arm-none-eabi
C_INCLUDE_PATH=$C_INCLUDE_PATH:$ARM_NONE_GCC_PATH/arm-none-eabi/include
CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$ARM_NONE_GCC_PATH/arm-none-eabi/include
OBJC_INCLUDE_PATH=$OBJC_INCLUDE_PATH:$ARM_NONE_GCC_PATH/arm-none-eabi/include
export C_PATH
export C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH
export OBJC_INCLUDE_PATH
export RTT_CC=$BASEPATH/../../../
export RTT_CC='gcc'
export RTT_EXEC_PATH=$ARM_NONE_GCC_PATH/bin/
