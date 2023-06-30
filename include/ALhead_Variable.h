// ***********************************************************************
// 判断_头文件引用
#ifndef _ALhead_Variable // 变量
#define _ALhead_Variable // 变量

// ***********************************************************************
// 引用头文件

#include <stdio.h>

// ***********************************************************************
// 函数原型声明

/// @brief 打印数组的指定成员
/// @param array 指定打印的数组
/// @param arraySize 数组的字节数
/// @param elementSize 元素的字节数
/// @param printType 指定一个可以打印该类型数组的函数
void print_array(const void *array, unsigned long long arraySize, unsigned long long elementSize, void (*printType)(const void *));

// ***********************************************************************
// 函数定义

void print_array(const void *array, unsigned long long arraySize, unsigned long long elementSize, void (*printType)(const void *)) {
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
#endif // _ALhead_Variable
