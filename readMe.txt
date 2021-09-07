# concurrent_cmd_util

Written By: Hunter Long 
Date: September 7th, 2021

PROJECT BACKGROUND:
This project was assigned to me as the sixth assignemnt when I took Systems Programming 
(CS-3424) at UTSA. It was essentially a test of our ability to use C's process control 
functions to exercise basic process creation. 

PROJECT FUNCTIONALITY:
This program accepts up to six commands (with any number of arguements) seperated by colons 
(whitespace on either side) from the command line, and then forks a child process for each 
command to be run concurrently. Each child process prints their PID as well as their PPID. 
  Example Input:
  $ ./assign6 ls -a -l : pwd : cat test.txt
  Example Output:
  PID: 1472, PPID: 1471, CMD: ls
  PID: 1473, PPID: 1471, CMD: pwd
  PID: 1474, PPID: 1471, CMD: cat
  /Users/hlong/Desktop/assignment6
  This is the content of test.txt.
  total 144
  drwxrwxrwx@ 7 hlong  staff    224 Sep  7 15:12 .
  drwxrwxrwx  6 hlong  staff    192 May 31 21:17 ..
  -rwxr-xr-x  1 hlong  staff  50320 Sep  7 15:08 assign6
  -rwxrwxrwx  1 hlong  staff   1984 Sep  7 14:46 assign6.c
  -rw-r--r--  1 hlong  staff   4476 Sep  7 15:08 assign6.o
  -rwxrwxrwx@ 1 hlong  staff    276 Sep  7 14:43 makefile
  -rw-r--r--  1 hlong  staff     33 Sep  7 15:11 test.txt
  
FUTURE IMPROVEMENTS:
There are two ways I would like to improve this project in the future. The first and most obvious 
way to me is to modify it to accept any number of arguements. The second, would be to accept an 
optional flag that would change the delimeter between commands to be an exclamation point instead 
of a colon, indicating that the output of the first command is being piped into the second, the 
second into the third, and so on. 


USING THIS PROJECT:
*This project was built and run with mac OS, I don't know if it will work with windows.*
To use this project you can simply download the assign6.c file and the makefile into the 
directory you would like to concurrently run commands in and execute the make command 
(this is assuming you have the gcc compiler installed). It will create the executable 
assign6 which can then be used from the command line as shown above. 
