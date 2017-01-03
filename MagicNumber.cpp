
//
// main.cpp
// Insertion Sort
// Created by ShiJiahuan on 11/11/2016.
// Copyright ©️ 2016 ShiJiahuan. All rights reserved.
//
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int judge(int solo);

int main() {
  int T;
  scanf("%d", &T);
  int L, R;
  int a[10010] = {0};
  for (int i = 1; i <= 10000; i++) {
    a[i] = a[i - 1] + judge(i); //将符合条件的个数存入数组中。
  }
  for (int i = 0; i < T; i++) {
    scanf("%d %d", &L, &R);
    printf("%d\n",
           a[R] - a[L - 1]); //这样循环时避免了区间部分重合时的重复计算。
  }
  return 0;
}

int judge(int solo) {
  int soloCopy = solo;
  int flag = 0;
  int sum = 0;
  int temp;
  while (soloCopy) {
    temp = soloCopy % 10;
    if (temp == 4 || temp == 6) //判断是否符合条件3
      flag = 1;
    sum += temp;
    soloCopy /= 10;
  }
  if (sum % 3 != 0 || flag == 0) { //判断是否符合条件2 & 3
    return 0;
  }
  while (solo % 2 == 0)
    solo /= 2;
  while (solo % 3 == 0)
    solo /= 3;
  while (solo % 7 == 0)
    solo /= 7;
  if (solo != 1) //判断是否符合条件1
    return 0;
  return 1;
}
