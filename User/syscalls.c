/*
 * syscalls.c
 *
 *  Created on: 2026. jan. 17.
 *      Author: zsolt
 */

#include <sys/types.h>

void _exit(int status)
{
    (void)status;
    while (1)
    {
        /* Trap here */
    }
}

