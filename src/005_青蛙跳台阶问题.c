#include <stdio.h>

// ***********************************************************************
// 函数原型声明

int main(void);

// ***********************************************************************
// 函数定义

int main(void) {
  // 初始化_首
  unsigned long long stepNumber;
  // 初始化_次
  { // 设置台阶数
    printf("请输入台阶数: ");
    scanf("%llu", &stepNumber);
  }
  // 开始执行

  // 结束
  return (0);
}

unsigned long long get_jumpNumber(unsigned long long stepNumber) {
  // 初始化
  unsigned long long jumpNumber;
  // 初始化_次
  jumpNumber = 0;
  // 开始执行
  if(stepNumber < 2) {
    return (1);
  }

  // 结束
  return (jumpNumber);
}
