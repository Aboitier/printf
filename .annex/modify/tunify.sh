#!/bin/sh

### add \n after the diouxXpcsd on the printf lines
grep "printf(" .annex/real_printf.c | grep "[diouxXfpcsd]" | cut -d '"' -f2
add a \n every two characters on the result
