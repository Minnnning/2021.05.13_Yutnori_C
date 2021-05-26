#pragma once
#include <afxwin.h>
class CPointXY :
    public CWnd
{
public:
    
    int x;
    int y;

    int Right_up(int x, int y, int n);
    int Left_up(int x, int y, int n);
    int Left_down(int x, int y, int n);
    int Right_down(int x, int y, int n);
    int Horizon(int x, int y, int n);
    int Vertical(int x, int y, int n);
};

