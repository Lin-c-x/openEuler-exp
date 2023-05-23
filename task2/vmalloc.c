#include <linux/module.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");

unsigned char *vmallocmem1;
unsigned char *vmallocmem2;
unsigned char *vmallocmem3;
unsigned char *vmallocmem4;

static int __init mem_module_init(void)
{
    printk("Start vmalloc!\n");
    
    // Allocate 8KB for vmallocmem1
    vmallocmem1 = vmalloc(8192);
    if (!vmallocmem1) {
        printk("Failed to allocate vmallocmem1!\n");
        return -ENOMEM;
    }
    printk("vmallocmem1 addr = %p\n", vmallocmem1);

    // Allocate 1MB for vmallocmem2
    vmallocmem2 = vmalloc(1024 * 1024);
    if (!vmallocmem2) {
        printk("Failed to allocate vmallocmem2!\n");
        vfree(vmallocmem1);
        return -ENOMEM;
    }
    printk("vmallocmem2 addr = %p\n", vmallocmem2);

    // Allocate 64MB for vmallocmem3
    vmallocmem3 = vmalloc(64 * 1024 * 1024);
    if (!vmallocmem3) {
        printk("Failed to allocate vmallocmem3!\n");
        vfree(vmallocmem1);
        vfree(vmallocmem2);
        return -ENOMEM;
    }
    printk("vmallocmem3 addr = %p\n", vmallocmem3);

    // Allocate memory larger than the kmalloc maximum limit for vmallocmem4
    vmallocmem4 = vmalloc(128 * 1024 * 1024);
    if (!vmallocmem4) {
        printk("Failed to allocate vmallocmem4!\n");
    } else {
        printk("vmallocmem4 addr = %p\n", vmallocmem4);
    }

    return 0;
}

static void __exit mem_module_exit(void)
{
    printk("Exit vmalloc!\n");

    vfree(vmallocmem1);
    vfree(vmallocmem2);
    vfree(vmallocmem3);
    vfree(vmallocmem4);
}

module_init(mem_module_init);
module_exit(mem_module_exit);

