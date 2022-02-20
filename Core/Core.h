#pragma once
#include "..\Premiere\Premiere.h"

#include "..\MainWindow\MainWindow.h"
#include "..\ControlWindow\ControlWindow.h"
VOID AllInit(HINSTANCE hInstance);
VOID AllCleanUp();
VOID RegisterAllClass();
VOID CreateAllWindow();
VOID MessageLoop();
