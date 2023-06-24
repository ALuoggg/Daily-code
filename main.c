#include <stdio.h>
#include <stdlib.h>
#include "./include/ALhead_Memory.h"
#include "./include/ALhead_Variable.h"

// ***********************************************************************
// 函数原型声明

int main(void);

/// @brief 打印一个字符
/// @param pointer 字符的首地址
void printChar(const void *pointer);

// ***********************************************************************
// 函数定义

int main(void) {
  // 初始化_首
  char a[] = "abcdefghijklmnopqrstuvwxyz", b[100];
  // 初始化_次
  mem_set(b, 35, 100);
  // 开始执行
  mem_cpy(a, b, sizeof(a));
  print_array(b, sizeof(b), sizeof(b[0]), printChar);
  // 结束
  return (1);
}

void printChar(const void *pointer) {
  // 初始化_首
  const char *pointer_2; //
  // 初始化_次
  pointer_2 = pointer;
  // 开始执行
  printf("%c", *pointer_2);
  return;
}
