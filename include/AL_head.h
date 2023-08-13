// ***********************************************************************
// 判断_头文件引用
#ifndef AL_head // AL_所有定义
#define AL_head /// @brief AL_所有定义

// ***********************************************************************
// 全局宏定义

// ***************************************
#ifndef AL_clang // AL_clang编译器专用
#define AL_clang /// @brief AL_clang编译器专用

#define clang_未使用 __attribute__((unused)) /// @brief 免于_clang编译器的无用'变量/函数'检测

#endif // AL_clang

// ***************************************
#ifndef AL_bool // AL_逻辑
#define AL_bool // AL_逻辑

#define true 1
#define false 0

#endif // AL_bool

// ***************************************
#ifndef AL_value // AL_数值
#define AL_value // AL_数值

#define char_bit (sizeof(char) * 8) /// @brief 'char'类型的位数L
#define uchar_bit (sizeof(unsigned char) * 8) /// @brief 'unsigned char'类型的位数L
#define short_bit (sizeof(short) * 8) /// @brief 'short'类型的位数
#define ushort_bit (sizeof(unsigned short) * 8) /// @brief 'unsigned short'类型的位数
#define int_bit (sizeof(int) * 8) /// @brief 'int'类型的位数
#define uint_bit (sizeof(unsigned int) * 8) /// @brief 'unsigned int'类型的位数
#define long_bit (sizeof(long) * 8) /// @brief 'long'类型的位数
#define ulong_bit (sizeof(unsigned long) * 8) /// @brief 'unsigned long'类型的位数
#define size_t_bit (sizeof(size_t) * 8) /// @brief 'size_t'类型的位数

#endif // AL_value

// ***************************************
#ifndef AL_宏函数 // AL_宏函数
#define AL_宏函数 // AL_宏函数

/// @brief 交换两个变量
/// @note 变量类型要一致
#define swap(a, b)   \
  do {               \
    (a) = (a) ^ (b); \
    (b) = (b) ^ (a); \
    (a) = (b) ^ (a); \
  } while(0)

#endif // AL_宏函数

// ***********************************************************************
// 全局别名定义

#ifndef AL_typedef // AL_别名定义
#define AL_typedef /// @brief AL_别名定义

typedef unsigned usd;
typedef unsigned int uint;
typedef unsigned char bool;

#endif // AL_typedef

// ***********************************************************************
// 结束判断_头文件引用

#endif // AL_head
