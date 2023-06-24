// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Variable
#define ALhead_Variable

#include <stdio.h>

// ***********************************************************************
// 常量声明

#define usg unsigned // 数据类型_缩写
#define cst const // 声明常量_缩写
#define sta static // 静态声明_缩写
#define str struct // 结构体_缩写
#define uint unsigned int // 复合数据类型_缩写
#define llong long long // 复合数据类型_缩写
#define ullong unsigned long long // 复合数据类型_缩写

// ***********************************************************************
// 函数原型声明

/// @brief 打印数组的指定成员
/// @param array 指定打印的数组
/// @param arraySize 数组的字节数
/// @param elementSize 元素的字节数
/// @param printType 指定一个可以打印该类型数组的函数
void print_array(const void *array, ullong arraySize, ullong elementSize, void (*printType)(const void *));

// ***********************************************************************
// 函数定义

void print_array(const void *array, ullong arraySize, ullong elementSize, void (*printType)(const void *)) {
  ullong elementConst; /// @brief 元素数量
  cst char *array_2; /// @brief 打印的数组
  cst char *arrayEnd; /// @brief 数组尾元素的首地址
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
