#include "pch.h"
#include "CPointXY.h"


//Ȩ x=275y=480 or x=275y=490
int CPointXY::Right_up(int x, int y, int n)     //�ֹ���
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


int CPointXY::Left_up(int x, int y, int n)     //�ع���
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


int CPointXY::Left_down(int x, int y, int n)   //�׹���
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


int CPointXY::Right_down(int x, int y, int n)    // �ٹ���
{
    if (x < 275 && x >= 65 && y >= 275) {
        x = x + (42 * n);
        y = y + (41 * n);
        if (x >= 275) {  //�����Ѱ�� 700�� �ǹ� ����
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
        if (x < 65 && y == 275) {                      //�߰��� ������ �ʰ� �� �� ���
            x = 65 + 42 * (65 - (x - (70 * n))) / 70;
            y=275+ 41 * (65 - (x - (70 * n))) / 70;
        }
        if (x == 245) {                                // �߰������� �����Ѱ��
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
        if (y >= 490) {    // ���� 700�� �ǹ̾���
            x = 700;
            y = 700;   
        }
    }
    return 0;
}
