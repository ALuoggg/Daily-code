#include <stdio.h>
#include <stdlib.h>
#include "../include/ALhead_Memory.h"

// ***********************************************************************
// 函数原型声明

int main(void);

// ***********************************************************************
// 函数定义

int main(void) {
  // 初始化_首
  int *p;
  // 初始化_头文件_ALhead_Memory.h
  init_ALhead_Memory();
  // 初始化_次
  p = mem_allocate(sizeof(int));
  // 开始执行
  printf("%d", *p);
  *p = 555;
  printf("%d", *p);
  // 退出_头文件_ALhead_Memory.h
  exit_ALhead_Memory();
  // 结束
  return (1);
}
