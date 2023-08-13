// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Memory // Memory
#define ALhead_Memory // Memory

// ***********************************************************************
// 引用头文件

#include <stdlib.h>

// ***********************************************************************
// 全局宏定义

#ifndef AL_bool // AL_逻辑
#define AL_bool // AL_逻辑

#define true 1
#define false 0

#endif // AL_bool

#define 获取指针大小 (sizeof(void *))
#define 获取总指针集大小 (sizeof(void *) * 总指针集.len)
#define 获取总指针集最大下标 ((总指针集.len) - 1)

// ***********************************************************************
// 全局结构体定义 'static' ignored on this declaration 

static struct struct_动态指针集 {
  void **pointer; /// @brief 指向指针集的指针
  size_t len; /// @brief 指针集所含指针的数量
};

// ***********************************************************************
// 全局别名定义

typedef struct struct_动态指针集 动态指针集;
typedef unsigned int uint;
typedef unsigned char bool;

// ***********************************************************************
// 全局变量声明

static 动态指针集 总指针集;

// ***********************************************************************
// 函数原型声明

/// @brief 初始化`ALhead_Memory`头文件
/// @return 返回值##成功: 1##失败: 0
void init_ALhead_Memory(void);

/// @brief 释放所有(通过`ALhead_Memory`申请并且未释放的)指针
void exit_ALhead_Memory(void);

/* /// @brief 向指定的数组中添加一个元素
/// @param array_ptr 数组的指针
/// @param array_size 数组大小
/// @param elem_ptr 元素的指针
/// @param elem_size 元素大小
/// @return 返回值##成功: 返回数组的新指针##失败: 返回NULL
void *加_动态数组元素(void *array_ptr, size_t array_size, void *elem_ptr, size_t elem_size); */

/// @brief 将`pointer`加入到`总指针集.pointer`
/// @param pointer 要加入到`总指针集.pointer`的指针
/// @return 返回值##成功: 返回`总指针集.pointer`##失败: 返回NULL
static void *加_指针(void *pointer);

/// @brief 在`*总指针集.pointer`指针_下标`下标`对应的元素
/// @param 指针_下标
/// @return 返回值##成功: 返回`总指针集.pointer`##失败: 返回NULL
static void 减_指针(size_t 下标);

/// @brief 寻找`p`在`总指针集.pointer`的下标
/// @param p 在`总指针集.pointer`中寻找的指针
/// @param 存储_指针下标 存储`p`在`总指针集.pointer`的下标
/// @return 返回值##成功: 返回1##失败: 返回: 0
static bool 取_指针下标(void *p, size_t *const 存储_指针下标);

/// @brief 释放内存块
/// @param p 内存块的指针
void mem_free(void *p);

/// @brief 分配内存块
/// @param size 内存块的大小
/// @return 返回值##成功: 返回内存块的指针##失败: NULL
void *mem_alloc(size_t size);

// ***********************************************************************
// 函数定义

void init_ALhead_Memory(void) { // 以完善

  // 开始执行

  总指针集.len = 0;
  总指针集.pointer = NULL;

  // 结束

  return;
}

void exit_ALhead_Memory(void) { // 以完善

  // 初始化_首

  uint i_1;

  // 开始执行

  if(总指针集.len != 0) { // 如果_`总指针集.pointer`!=NULL
    for(i_1 = 0; i_1 < 获取总指针集最大下标; --i_1) { // 释放_`*总指针集.pointer`的所有指针
      free(总指针集.pointer[i_1]);
      总指针集.pointer[i_1] = NULL;
    }
    free(总指针集.pointer);
    总指针集.pointer = NULL;
  } // 无需_else

  // 结束

  return;
}

/* void *加_动态数组元素(void *array_ptr, size_t array_size, void *elem_ptr, size_t elem_size) { // 未完善!!!!!
} */

static void *加_指针(void *pointer) { // 以完善

  // 初始化_首

  void **new_总指针集_pointer;
  size_t 返回值; /// @brief 函数的返回值

  // 开始执行

  if(pointer != NULL) { // 如果_`pointer`!=NULL
    new_总指针集_pointer = realloc(总指针集.pointer, 获取总指针集大小 + 获取指针大小);
    if(new_总指针集_pointer != NULL) { // 如果_扩大`总指针集.pointer`_成功
      总指针集.pointer = new_总指针集_pointer;
      ++总指针集.len;
      new_总指针集_pointer = NULL;
      总指针集.pointer[获取总指针集最大下标] = pointer;
      pointer = NULL;
      返回值 = 总指针集.pointer; // 返回值_赋值
    }
    else { // 如果_扩大`总指针集.pointer`_失败
      返回值 = NULL; // 返回值_赋值
    }
  }
  else { // 如果_`pointer`==NULL
    返回值 = 总指针集.pointer; // 返回值_赋值
  }

  // 结束

  return (返回值);
}

static void 减_指针(size_t 下标) { // 以完善

  // 初始化_首

  void **new_总指针集_pointer; /// @brief 临时存储`总指针集.pointer`的新值

  // 开始执行

  if(下标 != 获取总指针集最大下标) { // 如果_要删除的指针不是最后一个
    总指针集.pointer[下标] = 总指针集.pointer[获取总指针集最大下标];
    总指针集.pointer[获取总指针集最大下标] = NULL;
  } // 无需_else
  new_总指针集_pointer = realloc(总指针集.pointer, 获取总指针集大小 - 获取指针大小);
  if(new_总指针集_pointer == NULL) { // 如果_重新分配`总指针集.pointer`_成功
    总指针集.pointer = new_总指针集_pointer;
    new_总指针集_pointer = NULL;
  } // 无需_else
  --总指针集.len;

  // 结束

  return;
}

static bool 取_指针下标(void *p, size_t *const 存储_指针下标) { // 以完善

  // 初始化_首

  size_t i_1; /// @brief 循环变量_下标
  bool 返回值; /// @brief 函数的返回值

  // 初始化_次

  // 开始执行
  for(i_1 = 0; i_1 <= 获取总指针集最大下标; ++i_1) { // 遍历_在`总指针集.pointer`中寻找`p`
    if(总指针集.pointer[i_1] == p) { // 如果_在`总指针集.pointer`中寻找`p`_成功
      *存储_指针下标 = i_1;
      返回值 = true; // 返回值_成功
      goto 寻找p成功; // 跳出循环!!!!!
    }
  }
  返回值 = false; // 返回值_失败
寻找p成功: /// @brief 成功_在`总指针集.pointer`中寻找`p`

  // 结束

  return (返回值);
}

void mem_free(void *p) { // 以完善

  // 初始化_首

  size_t p_总指针集对应的下标;

  // 开始执行

  if(取_指针下标(p, &p_总指针集对应的下标)) { // 如果_寻找`p`的下标_成功
    减_指针(p_总指针集对应的下标);
  } // 如果_寻找`p`的下标_失败 无所谓
  free(p);
  p = NULL;

  // 结束

  return;
}

void *mem_alloc(size_t size) { // 以完善

  // 初始化_首

  void *p; /// @brief 申请内存块的指针
  void *返回值; /// @brief 函数的返回值

  // 开始执行

  p = malloc(size);
  if(p != NULL) { // 如果_申请内存块_成功
    // 将(申请成功的内存块的)指针加入到`总指针集.pointer`
    if(加_指针(p) != NULL) { // 如果_将(申请成功的内存块的)指针加入到`总指针集.pointer`_成功
      p = NULL;
      返回值 = 总指针集.pointer[获取总指针集最大下标]; // 返回值_赋值
    }
    else { // 如果_将(申请成功的内存块的)指针加入到`总指针集.pointer`_失败
      free(p);
      p = NULL;
      返回值 = NULL; // 返回值_赋值
    }
  }
  else { // 如果_申请内存块_失败
    free(p);
    p = NULL;
    返回值 = NULL; // 返回值_赋值
  }

  // 结束

  return (返回值);
}

// ***********************************************************************
// 结束判断_头文件引用
#endif // ALhead_Memory
