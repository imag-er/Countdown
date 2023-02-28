#pragma once

// 核心部分
#include "..\Premiere\Premiere.h"

#include "..\MainWindow\MainWindow.h"

// 这几个函数顾名思义 作用很明显
// 至于为什么叫"All" 是因为原先我还搞了一个gui用来切换文本之类的
// 后来因为忘了啥原因删了

VOID AllInit(HINSTANCE hInstance);
VOID AllCleanUp();
VOID RegisterAllClass();
VOID CreateAllWindow();
VOID MessageLoop();
