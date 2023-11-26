#include "malloc.h"
#include "test.h"

void print_ko(char* s, int mode)
{
    printf("%s KO\n", s);
    if (mode == 1)
    {
        show_alloc_mem_test();
        printf("\n-----\n\n");
    }
}

void print_ok(char* s, int mode)
{
    printf("%s OK\n", s);
    if (mode == 1)
    {
        show_alloc_mem_test();
        printf("\n-----\n\n");
    }
}

void    show_alloc_mem_test(void)
{
    unsigned long long size = 0;
    for (t_header* heap = g_heap; heap != NULL; heap = heap->next)
    {
        if (heap->flags & TINY)
            write(1, &"TINY : 0x", 9);
        if (heap->flags & SMALL)
            write(1, &"SMALL : 0x", 10);
        if (heap->flags & LARGE)
            write(1, &"LARGE : 0x", 10);
        ft_print_addr((size_t)heap);
        write(1, &"\n", 1);
        for (t_header* block = INC_HEADER(heap, HEADER); block != NULL; block = block->next)
        {

            if (!(block->flags & FREE))
                size += block->size - HEADER;
            write(1, &"0x", 2);
            ft_print_addr((size_t)INC_HEADER(block, HEADER));
            write(1, &" - 0x", 5);
            ft_print_addr((size_t)INC_HEADER(block, block->size - 1));
            write(1, &" : ", 3);
            ft_print_number(block->size - HEADER);
            write(1, &" bytes", 7);
            if (block->flags & FREE)
                write(1, &" FREE", 5);
            write(1, &"\n", 1);
        }
        write(1, &"\n", 1);
    }
    write(1, &"Total : ", 8);
    ft_print_number(size);
    write(1, &" bytes\n", 7);
}