// ***********************************************************************
// 判断_头文件引用
#ifndef ALhead_Variable // 变量
#define ALhead_Variable // 变量


// ***********************************************************************
// 函数原型声明

/// @brief 打印数组的指定成员
/// @param array 指定打印的数组
/// @param arraySize 数组_字节数
/// @param elementSize 元素_字节数
/// @param printType 指定一个可以打印该类型数组的函数
void printArray(const void *array, unsigned long long arraySize, unsigned long long elementSize, void (*printType)(const void *));

// ***********************************************************************
// 结束判断_头文件引用
#endif // ALhead_Variable
