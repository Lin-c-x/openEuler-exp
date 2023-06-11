[root@localhost exp]# ./myRAMFS 
Welcome to myRAMFS!
[myRAMFS@localhost /] $ ls
total:1
name    type    size    FCB     dataStartBlock
..      dir     1       100     -
[myRAMFS@localhost /] $ touch file1 1
[myRAMFS@localhost /] $ ls
total:2
name    type    size    FCB     dataStartBlock
..      dir     2       100     -
file1   file    1       101     102
[myRAMFS@localhost /] $ write file1 content for file1
> Write finished, press any key to continue....
[myRAMFS@localhost /] $ read file1 1024
content for file1 
> Read finished, press any key to continue....
[myRAMFS@localhost /] $ mkdir dir1
[myRAMFS@localhost /] $ ls
total:3
name    type    size    FCB     dataStartBlock
..      dir     3       100     -
file1   file    1       101     102
dir1    dir     1       103     -
[myRAMFS@localhost /] $ cd dir1
[myRAMFS@localhost /dir1/] $ touch file2 1
[myRAMFS@localhost /dir1/] $ ls
total:2
name    type    size    FCB     dataStartBlock
..      dir     3       100     -
file2   file    1       104     105
[myRAMFS@localhost /dir1/] $ rn file2 file22
[myRAMFS@localhost /dir1/] $ ls
total:2
name    type    size    FCB     dataStartBlock
..      dir     3       100     -
file22  file    1       104     105
[myRAMFS@localhost /dir1/] $ rm file22
[myRAMFS@localhost /dir1/] $ ls
total:1
name    type    size    FCB     dataStartBlock
..      dir     3       100     -
[myRAMFS@localhost /dir1/] $ cd ..
[myRAMFS@localhost /] $ ls
total:3
name    type    size    FCB     dataStartBlock
..      dir     3       100     -
file1   file    1       101     102
dir1    dir     1       103     -
[myRAMFS@localhost /] $ rm dir1
not a file
[myRAMFS@localhost /] $ rmdir dir1
cycle delete dir dir1
[myRAMFS@localhost /] $ ls
total:2
name    type    size    FCB     dataStartBlock
..      dir     2       100     -
file1   file    1       101     102
[myRAMFS@localhost /] $ exit
[root@localhost exp]# 
