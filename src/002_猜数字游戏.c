#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 函数原型声明

int main(void);

/// @brief 猜数字游戏
void 猜数字游戏(void);

// 函数定义

int main(void) {
  // 初始化
  llong 用户输入的菜单;
  srand((unsigned int)time(NULL));
  // 开始执行
  do { // 循环->选择菜单
    printf("请选择菜单>:\n\t1:开始游戏\n\t0:退出程序\n\tothers:请重新输入\n"); // 提示菜单r选项
    scanf("%llu", &用户输入的菜单); // 读取用户输入的菜单选项
    switch(用户输入的菜单) { // 执行菜单对应的内容
    case 1: // 开始游戏
      猜数字游戏();
      break;
    case 0: // 退出程序
      printf("即将推出程序!\n");
      break;
    default: // 清重新输入
      printf("清重新输入!\n");
      break;
    }
  } while(用户输入的菜单);
  // 结束
  return (1);
}

void 猜数字游戏(void) {
  // 初始化
  int 目标数字;
  int 用户输入的数字;
  // 开始执行
  目标数字 = (rand() % 100) + 1; // 指定目标数字
  printf("猜数字游戏已经开始!(输入-1可退出本次游戏)\n");
  while(1) { // 循环->判断用户输入的数字是否正确
    printf("清输入数字: ");
    scanf("%u", &用户输入的数字);
    if(用户输入的数字 == -1) {
      break;
    }
    else if(用户输入的数字 > 目标数字) {
      printf("大了\n");
    }
    else if(用户输入的数字 < 目标数字) {
      printf("小了\n");
    }
    else if(用户输入的数字 == 目标数字) {
      printf("恭喜你达对了!\n");
      break;
    }
  }
  printf("游戏结束!\n");
  // 结束
  return;
}
