large_proc_fork: large_proc_fork.c
	gcc -Wall -o large_proc_fork large_proc_fork.c

enable_over_commit:
	echo 1 > /proc/sys/vm/overcommit_memory

disable_over_commit:
	echo 0 > /proc/sys/vm/overcommit_memory
