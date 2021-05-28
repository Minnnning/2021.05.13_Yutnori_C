#pragma once
#include <afxwin.h>


class CPointXY :
    public CWnd
{
public:

    int Move(int * x, int * y, int n);
    
};

