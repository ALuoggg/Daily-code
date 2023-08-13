// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Variable // 变量
#define ALhead_Variable // 变量

// ***********************************************************************
// 引用头文件

#include <stdio.h>

// ***********************************************************************
// 函数原型声明

#include "../head/ALhead_Variable.h"

// ***********************************************************************
// 函数定义

void printArray(const void *array, const unsigned long long arraySize, const unsigned long long elementSize, void (*printType)(const void *)) {
  unsigned long long elementConst; /// @brief 元素数量
  const char *array_2; /// @brief 打印的数组
  const char *arrayEnd; /// @brief 数组尾元素的首地址
  // 初始化_次
  elementConst = arraySize / elementSize;
  array_2 = array;
  arrayEnd = array_2 + ((elementConst - 1) * elementSize);
  // 开始执行
  { // 打印数组
    printf("{");
    for(; array_2 != arrayEnd; array_2 += elementSize) { // 打印数组元素
      printType(array_2);
      printf(", ");
    }
    printType(array_2);
    printf("}");
  }
  // 结束
  return;
}

// ***********************************************************************
// 结束判断_头文件引用
#endif // ALhead_Variable
