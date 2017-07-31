#include<stdio.h>

int get_sum(int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    sum+=i;
    return sum;
}

int main(void)
{
    int i=100,result;
    result=get_sum(i);
    printf("1+2+3+...+%d=%d\n",i,result);
    return 0;
}

//本意是求1-100的和，但是这里结果却输出4950.应该将第6行改为for(i=0;i<=n;i++)
//要使用gdb调试，应该用gcc -g gdb1.c     然后用gdb a.out进入调试
//可用break以行号、函数名、条件表达式设置断点，用run、continue、next、print等常用命令进行操作

//调试结果
/*
[limeng@localhost study]$ gdb a.out
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...done.
(gdb) run
Starting program: /home/limeng/study/a.out
1+2+3+...+100=4950
[Inferior 1 (process 4804) exited normally]
(gdb) kill
The program is not being run.
(gdb) watch i=99
No symbol "i" in current context.
(gdb) break 6
Breakpoint 1 at 0x400504: file gdb1.c, line 6.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 1, get_sum (n=100) at gdb1.c:6
6	    for(i=0;i<n;i++)
(gdb) watch i=99
Watchpoint 2: i=99    //应该是条件表达式，而不是赋值语句
(gdb) clear 6
Deleted breakpoint 1
(gdb) continue
Continuing.



kill
^C
Program received signal SIGINT, Interrupt.
get_sum (n=100) at gdb1.c:6
6	    for(i=0;i<n;i++)
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) n
Program not restarted.
(gdb) exit
Undefined command: "exit".  Try "help".
(gdb) quit
A debugging session is active.

	Inferior 1 [process 4808] will be killed.

Quit anyway? (y or n) y
[limeng@localhost study]$ gdb a.out
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...done.
(gdb) break 6
Breakpoint 1 at 0x400504: file gdb1.c, line 6.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 1, get_sum (n=100) at gdb1.c:6
6	    for(i=0;i<n;i++)
(gdb) watch i==99
Hardware watchpoint 2: i==99
(gdb) continue
Continuing.

Hardware watchpoint 2: i==99

Old value = 0
New value = 1
0x0000000000400517 in get_sum (n=100) at gdb1.c:6
6	    for(i=0;i<n;i++)
(gdb) print i
$1 = 99
(gdb) print sum
$2 = 4851
(gdb) next
7	    sum+=i;
(gdb) print i
$3 = 99
(gdb) print sum
$4 = 4851
(gdb) next
6	    for(i=0;i<n;i++)
(gdb) print i
$5 = 99
(gdb) print i
$6 = 99
(gdb) print sum
$7 = 4950
(gdb) info breakpoint
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000400504 in get_sum at gdb1.c:6
	breakpoint already hit 1 time
2       hw watchpoint  keep y                      i==99
	breakpoint already hit 1 time
(gdb) delete 1 2
(gdb) info breakpoint
No breakpoints or watchpoints.
(gdb) kill
Kill the program being debugged? (y or n) y
(gdb) quit
[limeng@localhost study]$ gdb a.out
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...done.
(gdb) break 7
Breakpoint 1 at 0x40050d: file gdb1.c, line 7.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 1, get_sum (n=100) at gdb1.c:7
7	    sum+=i;
(gdb) print i<n
$1 = 1
(gdb) print i
$2 = 0
(gdb) print sum
$3 = 0
(gdb) print i=200
$4 = 200
(gdb) continue
Continuing.
1+2+3+...+100=200
[Inferior 1 (process 5102) exited normally]
(gdb) whatis i
No symbol "i" in current context.
(gdb) break 7
Note: breakpoint 1 also set at pc 0x40050d.
Breakpoint 2 at 0x40050d: file gdb1.c, line 7.
(gdb) info breakpoints
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x000000000040050d in get_sum at gdb1.c:7
	breakpoint already hit 1 time
2       breakpoint     keep y   0x000000000040050d in get_sum at gdb1.c:7
(gdb) clear
Deleted breakpoints 1 2
(gdb) info breakpoints
No breakpoints or watchpoints.
(gdb) break 7
Breakpoint 3 at 0x40050d: file gdb1.c, line 7.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 3, get_sum (n=100) at gdb1.c:7
7	    sum+=i;
(gdb) whatis i
type = int
(gdb) whatis sum+0.5
type = double
(gdb) set variale i=200
No symbol "variale" in current context.
(gdb) set variable i=200
(gdb) print i
$5 = 200
(gdb) kill
Kill the program being debugged? (y or n) y
(gdb) break 13
Breakpoint 4 at 0x40052c: file gdb1.c, line 13.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 4, main () at gdb1.c:13
13	    int i=100,result;
(gdb) next
14	    result=get_sum(i);
(gdb) next

Breakpoint 3, get_sum (n=100) at gdb1.c:7
7	    sum+=i;
(gdb) next
6	    for(i=0;i<n;i++)
(gdb) next

Breakpoint 3, get_sum (n=100) at gdb1.c:7
7	    sum+=i;
(gdb) clear
Deleted breakpoint 3
(gdb) break 13
Note: breakpoint 4 also set at pc 0x40052c.
Breakpoint 5 at 0x40052c: file gdb1.c, line 13.
(gdb) info breakpoints
Num     Type           Disp Enb Address            What
4       breakpoint     keep y   0x000000000040052c in main at gdb1.c:13
	breakpoint already hit 1 time
5       breakpoint     keep y   0x000000000040052c in main at gdb1.c:13
(gdb) delete 4
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) next
Program not restarted.
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/limeng/study/a.out

Breakpoint 5, main () at gdb1.c:13
13	    int i=100,result;
(gdb) next
14	    result=get_sum(i);
(gdb) next
15	    printf("1+2+3+...+%d=%d\n",i,result);
(gdb) next
1+2+3+...+100=4950
16	    return 0;
(gdb) kill
Kill the program being debugged? (y or n) y
(gdb) gdb a.
Undefined command: "gdb".  Try "help".
(gdb) quit
[limeng@localhost study]$ gcc -g gdb1.c
[limeng@localhost study]$ gdb a.out
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...done.
(gdb) info breakpoints
No breakpoints or watchpoints.
(gdb) break 13
Breakpoint 1 at 0x40052c: file gdb1.c, line 13.
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 1, main () at gdb1.c:13
13	    int i=100,result;
(gdb) step
14	    result=get_sum(i);
(gdb) step
get_sum (n=100) at gdb1.c:5
5	    int sum=0,i;
(gdb) step
6	    for(i=0;i<n;i++)
(gdb) step
7	    sum+=i;
(gdb) step
6	    for(i=0;i<n;i++)
(gdb) continue
Continuing.
1+2+3+...+100=4950
[Inferior 1 (process 5181) exited normally]
(gdb) clear
No breakpoint at this line.
(gdb) break 6
Breakpoint 2 at 0x400504: file gdb1.c, line 6.
(gdb) info break
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x000000000040052c in main at gdb1.c:13
	breakpoint already hit 1 time
2       breakpoint     keep y   0x0000000000400504 in get_sum at gdb1.c:6
(gdb) delete 1
(gdb) run
Starting program: /home/limeng/study/a.out

Breakpoint 2, get_sum (n=100) at gdb1.c:6
6	    for(i=0;i<n;i++)
(gdb) stepi
0x000000000040050b	6	    for(i=0;i<n;i++)
(gdb) stepi
0x0000000000400517	6	    for(i=0;i<n;i++)
(gdb) stepi
0x000000000040051a	6	    for(i=0;i<n;i++)
(gdb) stepi
0x000000000040051d	6	    for(i=0;i<n;i++)
(gdb) stepi
7	    sum+=i;
(gdb) continue
Continuing.
1+2+3+...+100=4950
[Inferior 1 (process 5203) exited normally]
(gdb) quit
[limeng@localhost study]$
*/
