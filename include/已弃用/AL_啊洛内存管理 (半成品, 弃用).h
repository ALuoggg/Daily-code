// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Memory // 内存
#define ALhead_Memory // 内存

// ***********************************************************************
// C标准库_引用

#include <stdlib.h>

// ***********************************************************************
// 宏定义
#define Ptr_指针数量 Ptr_pointer[0] /// @brief 代替了`Ptr_pointer[0]`
#define Ptr_最大下标 Ptr_pointer[0] /// @brief 代替了`Ptr_pointer[0]`

// ***********************************************************************
// 全局变量声明

/// @brief 申请内存成功后存储的指针
/// @note `Ptr_pointer[0]`存储了数组的元素数量
extern void **Ptr_pointer;

// ***********************************************************************
// 函数原型声明

/// @brief 初始化`ALhead_Memory`头文件
/// @return 返回值//成功: 返回非零值//失败: 0
void *init_ALhead_Memory(void);

/// @brief 退出`ALhead_Memory`头文件
void exit_ALhead_Memory(void);

/// @brief 申请内存块
/// @param size 申请内存块的大小
/// @return 返回值//成功: 返回内存块的首地址//失败: 返回NULL
void *mem_allocate(size_t size);

/// @brief 释放内存块
/// @param p 内存块的首地址
void mem_free(void *p);

unsigned int 删除_指针(i_1);

/// @brief 寻找`Ptr_pointer`里为的NULL元素
/// @param 起始下标 寻找的起始下标
/// @return 返回值//找到NULL: 返回对应的下标//未找到: 0
static size_t 获取_空闲指针(size_t 起始下标);

/// @brief 获取从指定位置开始出现的第一个非NULL指针
/// @param 起始下标 指定寻找`Ptr_pointer`中非NULL指针的起始下标
/// @return 返回值//成功: 1//失败: 0
static size_t 获取_非空闲指针(size_t 起始下标);

/// @brief 在`*Ptr_pointer`中, 倒找非空闲指针
/// @param 起始下标 倒找非空闲指针的起始下标
/// @param 存储_非空闲指针_下标 用于存储非空闲指针下标的指针
/// @return 返回值//成功: 返回1, 并且将非空闲指针的下标存储到`存储_非空闲指针_下标`//失败: 0
static unsigned int 倒取_非空闲指针(size_t 起始下标, size_t *存储_非空闲指针_下标);

/// @brief 清理`*Ptr_pointer`里的NULL指针, 并缩小`*Ptr_pointer`的大小
/// @returns 返回值//成功: 1//失败: 0
static void 清理_空闲指针(void);

/// @brief 将`源`内存块复制到`目标`内存块
/// @param 源 复制内存块的源地址
/// @param 目标 复制内存块的目标地址
/// @param size 复制内存块的大小
/// @return 返回`目标`
void *mem_cpy(void *源, void *目标, size_t size);

/// @brief 交换两个内厝块
/// @param a 第一个内存块
/// @param b 第二个内存块
/// @param size 交换的大小
void swap(void *a, void *b, size_t size);

// ***********************************************************************
// 全局变量定义

void **Ptr_pointer = NULL;

// ***********************************************************************
// 函数定义

void *init_ALhead_Memory(void) {
  Ptr_pointer = malloc(sizeof(size_t) * 1); /// @brief 已释放_使用`exit_ALhead_Memory`函数释放
  if(Ptr_pointer != NULL) {
    Ptr_pointer[0] = 0;
  }
  return (Ptr_pointer);
}

void exit_ALhead_Memory(void) { // 以完善
  // 初始化_首
  unsigned int i_1; /// @brief 循环变量
  // 开始执行
  for(i_1 = 1; i_1 <= Ptr_pointer[0]; i_1++) { // 释放`*Ptr_pointer`里存储的指针
    free(Ptr_pointer[i_1]);
  }
  free(Ptr_pointer); // 释放`Ptr_pointer`本身
  // 结束
  return;
}

void *mem_allocate(size_t size) { // 以完善
  // 初始化
  size_t *p; /// @brief 申请的内存块的首地址
  size_t 空闲指针的下标; /// @brief 临时存放`Ptr_pointer`中空闲指针对应的下标
  size_t *new_Ptr_pointer; /// @brief 临时存放`Ptr_pointer`的新地址
  // 初始化_次
  p = malloc(size); /// @brief 已释放_使用`exit_ALhead_Memory`函数释放
  // 开始执行
  if(p != NULL) { // 如果_申请内存_成功
    if(空闲指针的下标 = 获取_空闲指针(0)) { // 如果_寻找空闲指针_成功
      new_Ptr_pointer = realloc(Ptr_pointer, ((Ptr_pointer[0] + 2) * sizeof(size_t)));
      if(new_Ptr_pointer != NULL) { // 如果_扩展`Ptr_pointer`_成功
        Ptr_pointer = new_Ptr_pointer;
        new_Ptr_pointer = NULL;
        Ptr_pointer[0] += 1;
      }
      else { // 如果_扩展`Ptr_pointer`_失败
        free(p);
        p = NULL;
      }
    }
    else { // 如果_有空闲位置
      Ptr_pointer[空闲指针的下标] = p;
    }
  }
  // 结束
  return (p);
}

static unsigned int 获取_指针下标(void *p, size_t 起始下标, size_t *存储_指针下标) { // 未完善!!!!!

  // 初始化_首

  size_t i_1; /// @brief 循环变量
  size_t 返回值; /// @brief 函数的返回值

  // 初始化_次

  // 开始执行

  for(i_1 = 起始下标; i_1 <= Ptr_最大下标; ++i_1) { // 寻找_`p`在`*Ptr_pointer`对应的下标
    if(Ptr_pointer[i_1] = p) { // 如果_寻找`p`_成功
      *存储_指针下标 = i_1; // 存储值_赋值!!!!!
      返回值 = 1; // 返回值_赋值!!!!!
      goto 寻找p_成功; // 跳出循环!!!!!
    }
  }
  返回值 = 0; // 返回值_赋值!!!!!
寻找p_成功: /// @brief 成功_寻找`p`

  // 结束

  return (返回值);
}

void mem_free(void *p) { // 未完善!!!!!

  // 初始化

  size_t temp; /// @brief 循环变量

  // 开始执行

  if(p != NULL) {
    free(p);
    if(获取_指针下标(p, 0, &temp)) {
    }
  }
  else {
  }

  // 结束

  return;
}

static unsigned int 删除_指针(size_t 指针下标) { // 未完善

  // 初始化_首

  void **new_Ptr_pointer; /// @brief 临时存储`Ptr_pointer`的新值
  unsigned int 返回值; /// @brief 函数的返回值

  // 初始化_次

  // 开始执行

  if(指针下标 != Ptr_最大下标) { // 如果_欲删除的指针在`*Ptr_pointer`中_不是最后一个元素
    swap(&(Ptr_pointer[指针下标]), &(Ptr_pointer[Ptr_最大下标]), sizeof(Ptr_pointer[0]));
  }
  new_Ptr_pointer = realloc(Ptr_pointer, sizeof(Ptr_pointer[0]) * Ptr_最大下标); // 缩小`*Ptr_pointer`所占内存块大小
  if(new_Ptr_pointer != NULL) { // 如果_调整内存块大小_成功
    Ptr_pointer = new_Ptr_pointer;
    new_Ptr_pointer = NULL;
    返回值 = 1;
  }
  else if(指针下标 != Ptr_最大下标) { // 如果_调整内存块大小_失败 && 如果_欲删除的指针在`*Ptr_pointer`中_不是最后一个元素
    swap(&(Ptr_pointer[Ptr_最大下标]), &(Ptr_pointer[指针下标]), sizeof(Ptr_pointer[0]));
    返回值 = 0; // 返回值_赋值!!!!!
  }

  // 结束

  return (返回值);
}

static size_t 获取_空闲指针(size_t 起始下标) { // 未完善
  // 初始化_首
  size_t i_1; /// @brief 循环变量
  size_t 返回值; /// @brief 函数的返回值
  // 开始执行
  for(i_1 = 起始下标; i_1 <= Ptr_元素数量; ++i_1) { // 寻找空闲指针
    if(Ptr_pointer[i_1] == NULL) { // 如果_找到了空闲指针
      返回值 = i_1; // 返回值_赋值!!!!!
      break; // 跳出循环!!!!!
    }
  }
  if(i_1 > Ptr_元素数量) { // 如果_没找到空闲指针
    返回值 = 0; // 返回值_赋值!!!!!
  }
  // 结束
  return (返回值);
}

static size_t 获取_非空闲指针(size_t 起始下标) { // 有优化空间!!!!!
  // 初始化_首
  size_t i_1; /// @brief 循环变量
  size_t 返回值; /// @brief 函数的返回值
  // 初始化_次
  // 开始执行
  for(i_1 = 起始下标; i_1 <= Ptr_元素数量; ++i_1) { // 寻找_非空闲指针
    if(Ptr_pointer[i_1] != NULL) { // 如果_找到了非空闲指针
      // 赋值返回值
      返回值 = i_1;
      break; // 跳出循环
    }
  }
  if(i_1 > Ptr_元素数量) { // 如果_未找到非空闲指针
    // 赋值返回值
    返回值 = 0;
  }
  // 结束
  return (返回值);
}

static unsigned int 倒取_非空闲指针(size_t 起始下标, size_t *存储_非空闲指针_下标) {

  // 初始化_首

  size_t 返回值; /// @brief 函数的返回值

  // 初始化_次

  // 开始执行

  for(; 起始下标 >= 0; --起始下标) { // 倒找_非空闲指针
    if(Ptr_pointer[起始下标] != NULL) { // 如果_倒找非空闲指针_成功
      // 赋值返回值
      返回值 = 1;
      *存储_非空闲指针_下标 = 起始下标;
      break; // 跳出循环
    }
  }
  if(起始下标 < 0;) { // 如果_倒找非空闲指针_失败
    // 赋值返回值
    返回值 = 0;
  }

  // 结束

  return (返回值);
}

// 有优化空间 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

static unsigned int 清理_空闲指针(void) {

  // 初始化_首

  size_t 空闲指针的下标; /// @brief 记录空闲指针的下标
  size_t 最大判断下标; /// @brief 记录(将`*Ptr_pointer`里的空闲指针移动到`*Ptr_pointer`的尾端)时, 需要换位的最大下标 @note 比如`*Ptr_pointer`的最后一个元素存储NULL的话就不用管
  size_t 非空闲指针的下标; /// @brief 记录非空闲指针的下标
  size_t 返回值; /// @brief 函数的返回值

  // 初始化_次

  最大判断下标 = Ptr_元素数量 - 1;
  非空闲指针的下标 = 0; // 用于判断是否在`*Ptr_pointer`里找到过空闲指针

  // 开始执行

  for(空闲指针的下标 = 1; 空闲指针的下标 < 最大判断下标; ++空闲指针的下标) { // 将`*Ptr_pointer`里的空闲指针移动到`*Ptr_pointer`的尾端
    if(空闲指针的下标 = 获取_空闲指针(空闲指针的下标)) { // 如果_找到了空闲指针
      if(非空闲指针的下标 = 获取_非空闲指针(空闲指针的下标 + 1)) { // 如果_空闲指针后面有非空闲指针
        // 交换`Ptr_pointer`前面的空闲指针与`Ptr_pointer`后面的非空闲指针
        swap(&(Ptr_pointer[空闲指针的下标]), &(Ptr_pointer[非空闲指针的下标]), sizeof(Ptr_pointer[0]));
      }
    }
  }
  if(非空闲指针的下标 != 0) { // 如果_寻找空闲指针_成功
  }

  // 结束

  return (返回值);
}

void *mem_cpy(void *源, void *目标, size_t size) {
  // 初始化_首
  char *源_char; /// @brief 复制内存块的源地址_转为char类型
  char *目标_char; /// @brief 复制内存块的目标地址_转为char类型
  // 初始化_次
  // 开始执行
  while((size--) != 0) {
    目标_char[size] = 源_char[size];
  }
  // 结束
  return (目标);
}

void swap(void *a, void *b, size_t size) {
  // 初始化_首
  void *temp;
  // 初始化_次
  temp = malloc(size); // 已释放_在本函数`结束`时
  // 开始执行
  mem_cpy(b, temp, size);
  mem_cpy(a, b, size);
  mem_cpy(temp, a, size);
  // 结束
  free(temp);
  temp = NULL;
  return;
}

// ***********************************************************************
// 结束判断_头文件引用
#endif // ALhead_Memory
