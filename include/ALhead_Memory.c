// ***********************************************************************
// C标准库_引用

#include <stdlib.h>

// ***********************************************************************
// 函数原型声明

#include "ALhead_Memory.h"

// ***********************************************************************
// 全局变量定义

extern size_t *pointer = NULL;

// ***********************************************************************
// 函数定义

unsigned int init_ALhead_Memory(void) {
  pointer = malloc(sizeof(size_t) * 1); /// @brief 使用`exit_ALhead_Memory`函数释放
  if(pointer != NULL) {
    pointer[0] = 0;
  }
  return (pointer);
}

void exit_ALhead_Memory(void) {
  // 初始化_首
  unsigned int i_1; /// @brief 循环变量
  // 开始执行
  for(i_1 = 1; i_1 <= pointer[0]; i_1++) { // 释放`__pointer__`里存储的指针
    free(pointer[i_1]);
  }
  free(pointer);
  // 结束
  return;
}

void *mem_cpy(const void *source, void *destination, unsigned long long size) {
  // 初始化_首
  unsigned long long i_1;
  const char *source_2 = source;
  char *destination_2 = destination;
  // 开始执行
  for(i_1 = 0; i_1 < size; i_1++) {
    *(destination_2++) = *(source_2++);
  }
  // 结束
  return (destination);
}

void *mem_set(void *pointer, unsigned char value, unsigned long long size) {
  // 初始化
  unsigned char *p; /// @brief 填充内存块的首地址
  unsigned char *pNext; /// @brief 填充内存块后的首地址
  // 初始化_次
  p = pointer;
  pNext = p + size;
  // 开始执行
  while(p < pNext) {
    *(p++) = value;
  }
  // 结束
  return (pointer);
}

void *mem_allocate(size_t size) {
  // 初始化
  size_t *p; /// @brief 申请的内存块的首地址
  size_t *temp; /// @brief 临时存放`__pointer__`的新地址
  // 初始化_次
  p = malloc(size); /// @brief 使用`exit_ALhead_Memory`函数释放
  // 开始执行
  if(p != NULL) { // 如果申请内存成功
    temp = realloc(__pointer__, ((pointer[0] + 2) * sizeof(size_t)));
    if(temp != NULL) { // 扩展`__pointer__`成功
      pointer = temp;
      pointer[0] += 1;
    }
    else { // 扩展`__pointer__`失败
      free(p);
    }
  }
  // 结束
  return (p);
}

void mem_free(void *p) {
  for() {
  }
}
