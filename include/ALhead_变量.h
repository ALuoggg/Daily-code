#ifndef ALhead_变量
#define ALhead_变量

#include <stdio.h>

#define llong long long
#define ullong unsigned long long
#define cst const
#define str struct

// ********************************************************************************
// 函数原型声明

/// @brief 复制一段内存复制到另一段内存
/// @param 复制源_地址 复制内存的源地址
/// @param 复制目标_地址 复制内存的目标地址
/// @param 复制_元素数量 复制内存的元素数量
void 复制内存(llong *复制源_地址, llong *复制目标_地址, llong 复制_元素数量);

/// @brief 使用printf打印数组元素
/// @param 元素数量 要[打印的数组]的元素数量
/// @param 数组 欲打印数组的首地址
/// @note 结尾处不会自动输出'\\n'
void 打印数组(llong 元素数量, llong *数组);

// ********************************************************************************
// 函数定义

void 复制内存(llong *复制源_地址, llong *复制目标_地址, llong 复制_元素数量) {
  // 初始化_首
  llong i_1;
  //开始执行
  for (i_1 = 0; i_1 < 复制_元素数量; i_1++) {
    复制目标_地址[i_1] = 复制源_地址[i_1];
  }
  //结束
  // return;
}

void 打印数组(llong 元素数量, llong *数组) {
  //初始化
  llong 数组最大下标 = 元素数量 - 1;
  llong i_1;
  //开始执行
  printf("{");
  for (i_1 = 0; i_1 < 数组最大下标; i_1++) {
    printf("%lld, ", 数组[i_1]);
  }
  printf("%lld", 数组[数组最大下标]);
  printf("}");
  //结束
}

#endif // ALhead_变量
