Team: 
1. Tagayev Ilyas
2. Saidagali Adil
3. Turumbetova Alua

Project: Show processes which work on each CPU

Explanation:

#include <linux/module.h> - all modules <br />
#include <linux/moduleparam.h> - module parameters<br />
#include <linux/init.h> - to initialize module<br />
#include <linux/sched.h> - schedule cpu time<br />
#include <linux/sched/signal.h> <br />
#include <asm/current.h> - get current cpu<br />

functions:<br />
module_param: initialize module<br />
print_total_cpu: print total number of cpu <br />
    ax - accumulator,<br />
    bx - base, <br />
    cx - counter, <br />
    dx - data <br />
filter_by_cpu: argument is CPU number, result: show each process