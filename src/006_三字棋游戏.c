// ***********************************************************************
// C标准库引用
#include <stdio.h>

// ***********************************************************************
// 函数原型声明

int main(void);

/// @brief 三字棋游戏入口
void program_main(void);

/// @brief 三字棋游戏
/// @return 返回值//胜利: 1//失败: 0
unsigned int game(void);

// ***********************************************************************
// 函数定义

int main(void) {
  // 初始化_首
  // 初始化_次
  // 开始执行
  program_main();
  // 结束
  return (0);
}

void program_main(void) {
  // 初始化_首
  unsigned int 用户输入的菜单;
  // 开始执行
  do {
    printf("菜单: \n\t0: 退出程序\n\t1: 开始游戏\t\nOthers: 请重新选择");
    printf("请选择菜单>: ");
    scanf("%d", &用户输入的菜单);
    switch(用户输入的菜单) {
    case 0: // 退出程序
      printf("退出程序\n");
      break;
    case 1: // 开始游戏
      printf("三字棋\n");
      game();
      break;
    default: // 请重新选择
      printf("请重新选择\n");
      break;
    }
  } while(用户输入的菜单);
  // 结束
}

void game(void) {
  // 初始化_首
  unsigned int 游戏结果;
  // 初始化_次
  游戏结果 = 0;
  // 开始执行
  // 结束
  return (游戏结果);
}
