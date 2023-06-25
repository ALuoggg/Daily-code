#include <stdio.h>
#include <stdlib.h>
#include "../include/ALhead_Memory.h"
#include "../include/ALhead_constant.h"

// ***********************************************************************
// 全局变量声明
void *待释放的指针;

// ***********************************************************************
// 函数原型声明

int main(void);

/// @brief 求_第[rank]个斐波那契数
/// @param rank 指定所求的斐波那契数
/// @return 返回对应的斐波那契数
unsigned long long get_FibonacciNumber(const unsigned long long rank);

// ***********************************************************************
// 函数定义

int main(void) {
  // 初始化_首
  unsigned long long stepNumber;
  unsigned int 用户输入的菜单;
  // 初始化_次
  // 开始执行
  do {
    printf("菜单:\n\t0:退出程序\n\t1:求斐波那契数\n\tothers:请重新输入\n请输入菜单>:\t");
    scanf("%d", &用户输入的菜单);
    switch(用户输入的菜单) { // 执行菜单
    case 1: // 求斐波那契数
      printf("请输入台阶数: ");
      scanf("%llu", &stepNumber);
      printf("结果: %llu\n", get_FibonacciNumber(stepNumber));
      break;
    case 0:
      break;
    default: // 请重新输入
      break;
    }
  } while(用户输入的菜单);
  // 结束
  return (0);
}

unsigned long long get_FibonacciNumber(const unsigned long long rank) {
  // 初始化_首
  static unsigned long long *FibonacciNumber = NULL; // @brief 斐波那契数列
  static unsigned long long *NewFibonacciNumber = NULL; // @brief 新_斐波那契数列
  static unsigned long long lastrank;
  unsigned long long i_1; // @brief 循环变量
  // 特例
  if((rank == 1) || (rank == 2)) {
    return (1);
  }
  // 初始化_次
  if((FibonacciNumber == NULL) || (lastrank < rank)) { // 没计算过斐波那契数列 || 之前计算过的斐波那契数列大小不满足这次的需求
    if(FibonacciNumber != NULL) { // 之前计算过的斐波那契数列大小不满足这次的需求
      NewFibonacciNumber = malloc(sizeof(unsigned long long) * rank);
      mem_cpy(FibonacciNumber, NewFibonacciNumber, sizeof(FibonacciNumber));
      free(FibonacciNumber);
      FibonacciNumber = NewFibonacciNumber;
    }
    else { // 没计算过斐波那契数列
      FibonacciNumber = malloc(sizeof(unsigned long long) * rank);
    }
    { // 计算斐波那契数列
      FibonacciNumber[0] = 1;
      FibonacciNumber[1] = 1;
      for(i_1 = 2; i_1 < rank; i_1++) {
        FibonacciNumber[i_1] = FibonacciNumber[i_1 - 1] + FibonacciNumber[i_1 - 2];
      }
    }
  }
  else if(lastrank >= rank) {
    // 此时可以直接从已经计算完的数列里提取
  }
  // 开始执行
  // 结束
  return (FibonacciNumber[rank - 1]);
}
