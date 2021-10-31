

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
char buf[100];
strcpy(buf,argv[1]);
printf("Input was %s\n",buf );
return 0;


}

/*
gcc -fno-stack-protector -z execstack buf.c -o buf

sudo nano /proc/sys/kernel/randomize_va_space

find / -uer root -perm -4000 2> /dev/null
┌──(kali㉿kali)-[~/Desktop]
└─$ find / -user root -perm -4000 2>/dev/null                            1 ⨯
/usr/sbin/mount.nfs
/usr/sbin/mount.cifs
/usr/sbin/pppd
/usr/bin/newgrp
/usr/bin/kismet_cap_rz_killerbee
/usr/bin/kismet_cap_linux_bluetooth
/usr/bin/sudo
/usr/bin/passwd
/usr/bin/fusermount3
/usr/bin/chfn
/usr/bin/kismet_cap_nrf_mousejack
/usr/bin/su
/usr/bin/kismet_cap_ti_cc_2540
/usr/bin/kismet_cap_ti_cc_2531
/usr/bin/gpasswd
/usr/bin/chsh
/usr/bin/umount
/usr/bin/ntfs-3g
/usr/bin/kismet_cap_ubertooth_one
/usr/bin/kismet_cap_nrf_52840
/usr/bin/kismet_cap_linux_wifi
/usr/bin/pkexec
/usr/bin/kismet_cap_nxp_kw41z
/usr/bin/kismet_cap_nrf_51822
/usr/bin/mount
/usr/lib/dbus-1.0/dbus-daemon-launch-helper
/usr/lib/openssh/ssh-keysign
/usr/lib/xorg/Xorg.wrap
/usr/libexec/polkit-agent-helper-1
                                                                             
┌──(kali㉿kali)-[~/Desktop]
└─$ 


*/