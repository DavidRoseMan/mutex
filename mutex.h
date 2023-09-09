#ifndef _mutex_h
#define _mutex_h

typedef xdata struct Seg_struct
{
    volatile unsigned char lock;
    volatile unsigned char *Data;
    volatile unsigned char sizeof_Data;
} Seg_type;

#define writeto_seg_success 1;
#define writeto_seg_fail 0;

void init_seg(Seg_type *seg_init, unsigned char number_sizeofData);
void free_seg(Seg_type *seg_free);
void lock_seg(Seg_type *seg_lock);
void unlock_seg(Seg_type *seg_unlock);
unsigned char readfrom_seg(Seg_type *seg_read, unsigned char subscript);
unsigned char writeto_seg(Seg_type *seg_write, unsigned char subscript, unsigned char value);
unsigned char getstatus_seg(Seg_type *seg_getstatus);

#endif
