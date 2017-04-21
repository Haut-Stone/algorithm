/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 23:09:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-20 23:17:19
*/

//第一次打个人赛的时候就因为这个东西，跪了一道题。还是记一下吧，平时也挺有用的╮(￣▽￣"")╭
//正确性尚未验证，从洛谷上直接扒过来的。

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

/*
利用蔡勒公式(ZellerWeek)即可快速求出指定日期是星期几。

蔡勒公式：w=(y+y/4+c/4-2c+13(m+1)/5+d-1)%7

c:世纪数-1的值，如21世纪，则c=20;

m:月数，m的取值是大于等于3，小于等于14.在蔡勒公式中，某年的1月和2月被看成上一年的13月和14月，例如2001年2月1日要当成2000年的14月1日计算。

y:月份，取公元纪年的后两位****，如1998年，y=98, 2001年，y=1。

d:某月内的日数。
 */


int ZellerWeek(int year,int month,int day)
{
    int m=month;
    int d=day;
    if(month<=2)
    {
        year--;
        m=month+12;            //处理小月份
    } 
    int y=year%100;
    int c=year/100;
    int w=(y+y/4+c/4-2*c+(13*(m+1)/5)+d-1)%7;
    if(w<0)
    {
        w+=7;     //蔡勒公式有时计算出的结果为负数，需要对结果进行+1处理
    }
    return w;
}
