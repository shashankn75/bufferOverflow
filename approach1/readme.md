
PART1 execution:<br/>
for Part1 the stack is executable and addresses are static<br/>

how to run: <br/>

-Set the core dump size <br/>
unlimited ulimit -c unlimited /
-Disable the address randomization <br/>
sysctl -w kernel.randomize_va_space=0  /
-Set an environment variable to retrieve shell address<br/>
export MYSHELL="/bin/sh" -Retrieve shell address char *shell = getenv("MYSHELL"); <br/>
printf("%x\n", shell); <br/>
:ffffd45c <br/>
- put in the above shell address at line12 in bad.c <br/>
- gcc -m32 -fno-stack-protector -o bad bad.c /
- 

PART2 execution:<br/>
for Part2 the stack is non-executable and addresses are dynamic<br/>

how to run: <br/>


