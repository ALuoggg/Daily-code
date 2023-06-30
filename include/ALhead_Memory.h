// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Memory // 内存
#define ALhead_Memory // 内存  macro name is a reserved identifier

// ***********************************************************************
// 全局变量声明

/// @brief 申请内存成功后存储的指针
extern size_t *pointer;

// ***********************************************************************
// 函数原型声明

/// @brief 初始化`ALhead_Memory`头文件
/// @return 返回值//成功: 返回非零值//失败: 0
unsigned int init_ALhead_Memory(void);

/// @brief 退出`ALhead_Memory`头文件
void exit_ALhead_Memory(void);

/// @brief 复制一段内存到另一段内存
/// @param source 复制内存的源地址
/// @param destination 复制内存的目标地址
/// @param size 复制内存的字节数
/// @return 返回值是参数中的[复制目标_地址]
void *
mem_cpy(const void *source, void *destination, unsigned long long size);

/// @brief 填充内存块
/// @param pointer 填充内存块的首地址
/// @param value 填充内存块的值
/// @param size 内存块的大小
/// @return 返回值是参数中的[pointer]
void *mem_set(void *pointer, unsigned char value, unsigned long long size);

/// @brief 申请内存
/// @param size 申请内存块的大小
/// @return 返回值//成功: 返回内存块的首地址//失败: 返回NULL
void *mem_allocate(size_t size);

// ***********************************************************************
// 结束判断_头文件引用
#endif // _ALhead_Memory_
