#!/bin/bash
export LD_LIBRARY_PATH=./criterion-2.4.2/lib:$LD_LIBRARY_PATH
cc -I ./criterion-2.4.2/include push_swap_test.c stack_test.c back_and_forth_test.c ../push_swap/push_swap.a ../push_swap/libft/libft.a -L ./criterion-2.4.2/lib -lcriterion -o ps && ./ps --verbose

