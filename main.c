#include <stdio.h>

// 函数原型声明

int main(void);

void 打印(char *a);

// 函数定义

int main(void) {
  // 初始化
  char *a = "啊洛嘎嘎嘎";
  // 开始执行
  打印(a);
  // 结束
  return (0);
}

void 打印(char *a) {
  // 初始化
  // 开始执行
  printf("%s", a);
  // 结束
  return;
}
