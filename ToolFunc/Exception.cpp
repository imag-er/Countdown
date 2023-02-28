
#include "Exception.h"
BOOL _makeErrStr(LPWSTR lpszStr, LPCWSTR lpRemindStr)
{
    DWORD errCode = GetLastError();
    if (errCode == 0) return 0;
    return wsprintfW(lpszStr, L"%s : %d\n", lpRemindStr, (int)errCode);
}
VOID _msg(LPCWSTR szStr)
{
    MessageBoxW(0, szStr, NULL, MB_OK);
}
VOID _msgdbg(LPCWSTR szRemindStr)
{
    LPWSTR szOutputStr = new WCHAR[STRLENGTH];
    if (0 == _makeErrStr(szOutputStr, szRemindStr))
        return;
    _msg(szOutputStr);
    delete[] szOutputStr;
    return;
}
VOID _con(LPCWSTR szStr)
{
    AllocConsole();
    WriteConsoleW
    (
        GetStdHandle(STD_OUTPUT_HANDLE),
        szStr,
        wcslen(szStr),
        NULL,
        NULL
    );
}
VOID _condbg(LPCWSTR szRemindStr)
{
    LPWSTR szOutputStr = new WCHAR[STRLENGTH];
    if (0 == _makeErrStr(szOutputStr, szRemindStr))
        return;
    _con(szOutputStr);
    delete[] szOutputStr;
    return;
}