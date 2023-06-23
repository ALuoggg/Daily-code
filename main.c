#include <stdio.h>
#include "./include/ALhead_内存.h"
#include "./include/ALhead_变量.h"

// 函数原型声明

int main(void);

/// @brief 打印一个字符
/// @param pointer 字符的首地址
void printChar(const void *pointer);

// 函数定义

int main(void) {
  // 初始化
  char a[] = "abcdefghijklmnopqrstuvwxyz", b[100] = {0};
  // 开始执行
  mem_cpy(a, b, sizeof(a));
  printArray(b, sizeof(b), sizeof(b[0]), printChar);
  // 结束
  return (1);
}

void printChar(const void *pointer) {
  printf("%s", (const char *)pointer);
  return;
}
