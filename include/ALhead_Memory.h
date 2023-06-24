// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Memory
#define ALhead_Memory

// ***********************************************************************
// 函数原型声明

/// @brief 复制一段内存复制到另一段内存
/// @param 复制源_地址 复制内存的源地址
/// @param 复制目标_地址 复制内存的目标地址
/// @param 复制_元素数量 复制内存的元素数量
void *mem_cpy(const void *复制源_地址, void *复制目标_地址, unsigned long long 复制_元素数量);

/// @brief 填充内存块
/// @param pointer 填充内存块的首地址
/// @param value 填充内存块的值
/// @param size 内存块的大小
/// @return 返回值是参数中的[pointer]
void *mem_set(void *pointer, unsigned char value, unsigned long long size);

// ***********************************************************************
// 函数定义

void *mem_cpy(const void *复制源_地址, void *复制目标_地址, unsigned long long 复制_字节数) {
  // 初始化_首
  unsigned long long i_1;
  const char *复制源_地址_2 = 复制源_地址;
  char *复制目标_地址_2 = 复制目标_地址;
  // 开始执行
  for(i_1 = 0; i_1 < 复制_字节数; i_1++) {
    *(复制目标_地址_2++) = *(复制源_地址_2++);
  }
  // 结束
  return (复制目标_地址);
}

void *mem_set(void *pointer, unsigned char value, unsigned long long size) {
  // 初始化
  unsigned char *p; /// @brief 填充内存块的首地址
  unsigned char *pNext; /// @brief 填充内存块后的首地址
  // 初始化_次
  p = pointer;
  pNext = p + size;
  // 开始执行
  while(p < pNext) {
    *(p++) = value;
  }
  // 结束
  return (pointer);
}

// ***********************************************************************
// 结束判断_头文件引用
#endif // ALhead_Memory