#pragma once
#include "..\Premiere\Premiere.h"
#include <string>
BOOL _makeErrStr(LPWSTR lpszStr, LPCWSTR lpRemindStr);
VOID _msg(LPCWSTR szStr);
VOID _msgdbg(LPCWSTR szRemindStr);
VOID _con(LPCWSTR szStr);
VOID _condbg(LPCWSTR szRemindStr);