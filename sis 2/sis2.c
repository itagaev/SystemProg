#include <linux/module.h> 
#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <asm/current.h>

void cpu_information(int cpu_id) {
    struct task_struct *proc;

    printk(KERN_INFO "Processes of CPU #%d:\n", cpu_id);
    char s[100] = "Name:", x[100] = "ID";
    printk(KERN_INFO "\t%-20s[%s]\n", s, x);
    for_each_process(proc) {
    
        if(proc->cpu == cpu_id) {
            printk("\t%-20s[%d]", proc->comm, proc->pid);
        }
    
    }

}

void proc_information(int k) {
    unsigned int eax=11,ebx=0,ecx=1,edx=0;
    asm volatile("cpuid"
        : "=a" (eax),
          "=b" (ebx),
          "=c" (ecx),
          "=d" (edx)
        : "0" (eax), "2" (ecx)
        : );
    int i;
    for(i = 0; i < ebx; i++){
        cpu_information(i);
    }

}

int init_module(void)
{
    printk(KERN_INFO "Hi, there are information about your CPUs:\n");
    proc_information(0);
    printk(KERN_INFO "Bye, see you soon!\n\n\n");
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Bye, see you soon!\n");
}

