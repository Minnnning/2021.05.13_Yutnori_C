#include "pch.h"
#include "CPointXY.h"


//홈 x=275y=480 or x=275y=490
int CPointXY::Right_up(int x, int y, int n)     //↗방향
{
    if (x >= 275 && x < 485 && y>275) {
        x = 275 + (42 * n);
        y = 480 - (41 * n);
        if (x > 485) {
            x = 695 - (42 * n);
        }
    }
    return 0;
}


int CPointXY::Left_up(int x, int y, int n)     //↖방향
{
    if (x > 275 && x < 485 && y < 275) {
        x = x - (42 * n);
        y = y - (41 * n);
        if (y < 70) {
            y = 140 - y + (41 * n);
        }
    }
    return 0;
}


int CPointXY::Left_down(int x, int y, int n)   //↙방향
{
    if (x < 275 && x>65 && y < 275) {
        x = x - (42 * n);
        y = y + (41 * n);
        if (x < 65) {
            x = 130 - x + (42 * n);
        }
    }
    return 0;
}


int CPointXY::Right_down(int x, int y, int n)    // ↘방향
{
    if (x < 275 && x >= 65 && y >= 275) {
        x = x + (42 * n);
        y = y + (41 * n);
        if (x >= 275) {  //완주한경우 700은 의미 없음
            x = 700;
            y = 500;
        }
    }
    return 0;
}


int CPointXY::Horizon(int x, int y, int n)
{
    if (x <= 485 && x > 65 && y == 275) {
        x = x - (70 * n);
        y = 275;
        if (x < 65 && y == 275) {                      //중간에 멈추지 않고 쭉 간 경우
            x = 65 + 42 * (65 - (x - (70 * n))) / 70;
            y=275+ 41 * (65 - (x - (70 * n))) / 70;
        }
        if (x == 245) {                                // 중간지점에 도착한경우
            x = 275;
            y = 280;
        }
    }
    return 0;
}


int CPointXY::Vertical(int x, int y, int n)
{
    if (x == 275 && y >= 70) {
        x = 275;
        y = y + (70 * n);
        if (y >= 490) {    // 완주 700은 의미없음
            x = 700;
            y = 700;   
        }
    }
    return 0;
}
