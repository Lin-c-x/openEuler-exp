#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

unsigned char *kmallocmem1;
unsigned char *kmallocmem2;
unsigned char *kmallocmem3;
unsigned char *kmallocmem4;

static int __init mem_module_init(void)
{
    printk("Start kmalloc!\n");
    
    // Allocate 1KB for kmallocmem1
    kmallocmem1 = kmalloc(1024, GFP_KERNEL);
    if (!kmallocmem1) {
        printk("Failed to allocate kmallocmem1!\n");
        return -ENOMEM;
    }
    printk("kmallocmem1 addr = %p\n", kmallocmem1);

    // Allocate 8KB for kmallocmem2
    kmallocmem2 = kmalloc(8192, GFP_KERNEL);
    if (!kmallocmem2) {
        printk("Failed to allocate kmallocmem2!\n");
        kfree(kmallocmem1);
        return -ENOMEM;
    }
    printk("kmallocmem2 addr = %p\n", kmallocmem2);

    // Find the maximum allowed size of memory for kmallocmem3
    unsigned int max_size = 0;
    while (kmalloc(max_size, GFP_KERNEL)) {
        kfree(kmallocmem3);
        max_size += PAGE_SIZE;
        kmallocmem3 = kmalloc(max_size, GFP_KERNEL);
    }
    printk("kmallocmem3 addr = %p\n", kmallocmem3);

    // Allocate memory larger than the maximum allowed size for kmallocmem4
    kmallocmem4 = kmalloc(max_size + PAGE_SIZE, GFP_KERNEL);
    if (!kmallocmem4) {
        printk("Failed to allocate kmallocmem4!\n");
    }

    return 0;
}

static void __exit mem_module_exit(void)
{
    printk("Exit kmalloc!\n");

    kfree(kmallocmem1);
    kfree(kmallocmem2);
    kfree(kmallocmem3);
    kfree(kmallocmem4);
}

module_init(mem_module_init);
module_exit(mem_module_exit);

