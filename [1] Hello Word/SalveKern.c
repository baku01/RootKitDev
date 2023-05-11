#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("l0gic");
MODULE_DESCRIPTION("Basic Kernel Module");
MODULE_VERSION("0.01");

static int __init Exemplo_De_Init(void)
{
    printk(KERN_INFO "Salve, Paizão!\n");
    return 0;
}

static void __exit Exemplo_De_Saida(void)
{
    printk(KERN_INFO "Falou fiote\n");
}

module_init(Exemplo_De_Init);
module_exit(Exemplo_De_Saida);