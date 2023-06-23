// ***********************************************************************
// 执行定义判断
#ifndef ALhead_变量
#define ALhead_变量

#include <stdio.h>

// ***********************************************************************
// 常量声明

#define usg unsigned // 数据类型_缩写
#define uint unsigned int // 数据类型_缩写
#define llong long long // 复合数据类型_缩写
#define ullong unsigned long long // 复合数据类型_缩写
#define cst const // 声明常量_缩写
#define sta static // 静态声明_缩写
#define str struct // 结构体_缩写

// ***********************************************************************
// 函数原型声明

/// @brief 打印数组的指定成员
/// @param array 指定打印的数组
/// @param arraySize 数组的字节数
/// @param elementSize 元素的字节数
/// @param printType 指定一个可以打印该类型数组的函数
void printArray(const void *array, ullong arraySize, ullong elementSize, void (*printType)(const void *));

// ***********************************************************************
// 函数定义

void printArray(const void *array, ullong arraySize, ullong elementSize, void (*printType)(const void *)) {
  ullong elementConst; /// @brief 元素数量
  const char *array_2; /// @brief 打印的数组
  ullong i_1;
  // 初始化_次
  elementConst = sizeof(arraySize) / sizeof(elementSize);
  array_2 = array;
  // 开始执行
  { // 打印数组
    printf("{");
    for(i_1 = 0; i_1 < elementConst; i_1++) { // 打印数组元素
      printType(array_2);
      array_2 += elementSize;
    }
    printf("}");
  }
  // 结束
  return;
}

// ***********************************************************************
// 结束定义判断
#endif // ALhead_变量
