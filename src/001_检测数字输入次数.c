#include <stdio.h>

#define True 1

//函数原型声明
int main(void);
long long 输出数字输入次数(long long 数组元素数, long long 数组[数组元素数]);

// 函数
int main(void) {
  // 初始化_首
  const long long 数组元素数 = 10;
  long long temp;
  // 初始化_次
  long long 数字输入的次数[数组元素数] = {0};
  // 开始执行
  printf("请开始输入数字:\n");
  for (; True;) { // 输入数子
    scanf("%lld", &temp);
    if ((temp != EOF) && ((0 <= temp) && (temp <= 9))) {
      数字输入的次数[temp]++;
    }
    else if (temp == EOF) {
      printf("结束输入!\n");
      break;
    }
  }
  输出数字输入次数(数组元素数, 数字输入的次数);
  // 结束
  return (0);
}

long long 输出数字输入次数(long long 数组元素数, long long 数组[数组元素数]) {
  // 初始化
  long long i_1;
  // 开始执行
  for (i_1 = 0; i_1 < 数组元素数; i_1++) {
    printf("%lld出现了%lld次\n", i_1, 数组[i_1]);
  }
  // 结束
  return (0);
}
