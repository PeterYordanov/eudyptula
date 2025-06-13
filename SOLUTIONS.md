# Eudyptula Challenge Solutions

This repository contains my answers for all 20 tasks of the Eudyptula Challenge.  Each task is located in its own directory.

| Task | Directory | Contents |
| ---- | --------- | -------- |
| 1 | `task1` | simple Hello World module |
| 2 | `task2` | kernel build Makefile (used for custom kernel) |
| 3 | `task3` | patch to set `-eudyptula` in the kernel version |
| 4 | `task4` | coding-style fixes with a kernel module |
| 5 | `task5` | simple misc device |
| 6 | `task6` | module demonstrating time delays |
| 7 | `task7` | README only; no code was required |
| 8 | `task8` | debugfs-based module |
| 9 | `task9` | sysfs attribute example |
| 10 | `task10` | clean-up patches for staging driver |
| 11 | `task11` | patch adding `id` sysfs attribute to FTDI driver |
| 12 | `task12` | linked list handling module |
| 13 | `task13` | kmem-cache implementation |
| 14 | `task14` | patch adding `id` field to `task_struct` |
| 15 | `task15` | new syscall patch and small test program |
| 16 | `task16` | patch to use `gfp_t` in Lustre code |
| 17 | `task17` | kernel thread example |
| 18 | `task18` | work-queue module using list helpers |
| 19 | `task19` | netfilter module to log incoming packets |
| 20 | `task20` | ioctl implementation for FAT filesystem |

Tasks that are patches (`task3`, `task10`, `task11`, `task14`, `task15`, `task16`, and `task20`) are supplied as `.patch` files ready to apply to a kernel tree.  Tasks without code (`task2` and `task7`) include documentation only.
