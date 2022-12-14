#!/bin/sh

rmmod ps_cmd 
insmod ps_cmd.ko devname=mpv_ps_cmd
chmod a+rw /dev/mpv_ps_cmd
dmesg -c
echo ""
echo ""

