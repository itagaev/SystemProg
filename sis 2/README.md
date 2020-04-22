Team: 
1. Tagayev Ilyas
2. Saidagali Adil
3. Turumbetova Alua

Project: Show processes which work on each CPU

Explanation:

#include <linux/module.h> - all modules <br />
#include <linux/init.h> - to initialize module<br />
#include <linux/sched.h> - schedule cpu time<br />
#include <linux/sched/signal.h> <br />
#include <asm/current.h> - get current cpu<br />

functions:<br />
cpu_information: parameter int cpu_id, prints info about cpu by id
proc_information: prints info about process
    ax - accumulator,<br />
    bx - base, <br />
    cx - counter, <br />
    dx - data <br />
