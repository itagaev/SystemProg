#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <asm/current.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

static int parameter = 0;
module_param(parameter, int, 0660);

int show_all_cpu(void)
{
    unsigned int ax = 11, bx = 0, cx = 1, dx = 0;
    asm volatile("id of CPU"
                 : "=a"(ax),
                   "=b"(bx),
                   "=c"(cx),
                   "=d"(dx)
                 : "0"(ax), "2"(cx)
                 :);
    return bx;
}

void filter_cpu(int cpu_id)
{
    struct task_struct *proc;
    printk(KERN_INFO "All processes in CPU_ID %d:\n", cpu_id);
    for_each_process(proc)
    {
        if (proc->cpu == cpu_id)
        {
            printk(KERN_INFO "\tName of the process: [%s]. PID: [%d].\n", proc->comm, proc->pid);
        }
    }
}

void print_processes(int s)
{
    printk(KERN_INFO "Start of the function:");
    int i = 0;
    int cpus = show_all_cpu();
    if (s == 0)
    {
        filter_cpu(0);
    }
    if (s > 0 && s <= cpus)
    {
        for (i = 0; i < s; i++)
        {
            filter_cpu(i);
        }
    }
    else if (cpus < s || s < 0)
    {
        printk(KERN_INFO "There is %d CPU cores.\nThere is no such CPU!\n", cpus, cpus - 1);
    }
    printk(KERN_INFO "End of the function\n");
}

int init_module(void)
{
    printk(KERN_INFO "Start of SIS2\n");
    print_processes(parameter);
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "End of SIS2.\n");
}
