#include "mutex.h"
#include <stdlib.h>
#include "variable.h"

void init_seg(Seg_type *seg_init, unsigned char number_sizeofData)
{
    seg_init->lock = 1;
    seg_init->Data = (unsigned char xdata *)malloc((size_t)number_sizeofData);
    seg_init->sizeof_Data = number_sizeofData;
}

void free_seg(Seg_type *seg_free)
{
    free((void _MALLOC_MEM_ *)seg_free->Data);
    seg_free->Data = NULL;
}

void lock_seg(Seg_type *seg_lock)
{
    seg_lock->lock = 1;
}

void unlock_seg(Seg_type *seg_unlock)
{
    seg_unlock->lock = 0;
}

unsigned char readfrom_seg(Seg_type *seg_read, unsigned char subscript)
{
    return seg_read->Data[subscript];
}

unsigned char writeto_seg(Seg_type *seg_write, unsigned char subscript, unsigned char value)
{
    if (subscript < seg_write->sizeof_Data)
    {
        seg_write->Data[subscript] = value;
        return writeto_seg_success;
    }
    return writeto_seg_fail;
}

unsigned char getstatus_seg(Seg_type *seg_getstatus)
{
    return seg_getstatus->lock;
}