#ifndef __MINI_CRT_H
#define __MINI_CRT_H

#ifndef  __cplusplus
extern "C" {
#endif


//malloc
#ifndef  NULL
#define NULL (0)
#endif

void free(void *ptr);
void *malloc(unsigned size);
static int brk(void *end_data_segment);
int mini_crt_init_heap();



//string
char *itoa(int n, char *str, int radix);
int strcmp(const char *src, const char *dst);
char *strcpy(char *dest, char *str);
unsigned strlen(const char *str);




//IO
typedef  int FILE;
#define EOF (-1)


#define stdin  ((FILE*)0)
#define stdout ((FILE*)1)
#define stderr ((FILE*)2)


int mini_crt_io_init();
FILE* fopen(const char*filename, const char*mode);
int fread(void *buffer, int size, int count, FILE* stream);
int fwrite(const void* buffer, int size, int count, FILE* stream);
int fclose(FILE* fp);
int fseek(FILE* fp, int offset, int set);


//printf
int fputs(int c, FILE* stream);
int fputs(const char* str, FILE* stream);
int printf(const char *format, ...);
int fprintf(FILE* stream, const char* format, ...);



//internal
void do_global_ctors();
void mini_crt_call_exit_routine();


//atexit
typedef void (*atexit_func_t)(void);
int atexit(atexit_func_t func);



#ifndef  __cplusplus
}
#endif


#endif
