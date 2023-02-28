#pragma once
#include "..\Premiere\Premiere.h"
#include <string>

// 一些输出debug信息的函数 主要都是字符串编码的转换 意义不大
// _con里有控制台的内存操作 还是有意义的
BOOL _makeErrStr(LPWSTR lpszStr, LPCWSTR lpRemindStr);
VOID _msg(LPCWSTR szStr);
VOID _msgdbg(LPCWSTR szRemindStr);
VOID _con(LPCWSTR szStr);
VOID _condbg(LPCWSTR szRemindStr);