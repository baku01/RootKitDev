# RootKitDev


### Oque é o Kernel
O kernel é essencial em qualquer sistema operacional, sendo basicamente o “cérebro” de um computador. Ele consegue gerenciar os componentes de hardware da máquina para que os softwares instalados consigam trabalhar perfeitamente.

### Oque é um Rootkit
Um rootkit é uma coleção de software de computador, geralmente malicioso, projetado para permitir o acesso a um computador ou a uma área de seu software que não é permitida de outra forma ( por exemplo, para um usuário não autorizado ) e muitas vezes mascara sua existência ou a existência de outro software. 


[1] Hello Word no Kernel do Linux

```c
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

```


Referencias
--
- [Diamorphine](https://github.com/m0nad/Diamorphine)
- [Wikipedia Rootkit](https://en.wikipedia.org/wiki/Rootkit)
- [Linux Device Drivers](http://lwn.net/Kernel/LDD3/)
- [LKM HACKING](https://web.archive.org/web/20140701183221/https://www.thc.org/papers/LKM_HACKING.html)
- [Xcellerator - Linux Rootkits: New Methods for Kernel 5.7+](https://xcellerator.github.io/posts/linux_rootkits_11/)
- [Xcellerator - Linux Rootkits](https://xcellerator.github.io/posts/linux_rootkits_01/)
- [zizzu0 LinuxKernelModules](https://github.com/zizzu0/LinuxKernelModules/)
- [WRITING A SIMPLE ROOTKIT FOR LINUX](https://web.archive.org/web/20160620231623/http://big-daddy.fr/repository/Documentation/Hacking/Security/Malware/Rootkits/writing-rootkit.txt)