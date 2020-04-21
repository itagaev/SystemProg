Team: 
1. Tagayev Ilyas
2. Saidagali Adil
3. Turumbetova Alua

Project: Show processes which work on each CPU

Explanation:

#include <linux/module.h> - all modules
#include <linux/moduleparam.h> - module parameters
#include <linux/init.h> - to initialize module
#include <linux/sched.h> - schedule cpu time
#include <linux/sched/signal.h> 
#include <asm/current.h> - get current cpu

functions:
module_param: initialize module
print_total_cpu: print total number of cpu 
    ax - accumulator,
    bx - base, 
    cx - counter, 
    dx - data