//
// Created by Chaewon Jeong on 2025. 1. 20..
//

#include "test21.h"

// 1. library
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// 2. 자료구조: 회의의 수, 회의 --> vector, 각회의는 시작시간-끝시간 > vector
int n;
vector<pair<int, int> > arr; // (시작시간, 끝 시간)의 pair로 저장된 vector

// 3. solve 함수
int solve() {
  int cnt = 1; // 1로 초기화 > 첫번째 회의는 무조건 함
  int endtime = arr[0].first;

  for (int i = 1; i < n; i++) {

  }
  return cnt;
}

// 4. main 함수 : 입력, solve(), 출력
int main() {
  FILE *fp;
  fopen(&fp, "test21_input.txt", "r+t");

  int tc;
  int s, e;
  int ans, sol;

  fscanf (fp, "%d", &tc);
  for (int i = 0; i < tc; i++) {
  // 입력
    fscanf (fp, "%d", &n);
    for (int j = 0; j < n; j++) {
      fscanf (fp, "%d, %d\n", &s,&e);
      arr.push_back(make_pair(s, e));
    }

    sort(arr.begin(), arr.end());
    for (int j = 0; j < arr.size(); j++) {
      printf("%d,%d\n", arr[j].first, arr[j].second);
    }
    fscanf (fp, "%d", &ans);
    printf ("%d\n", ans);
  // solve 함수 호출

  // 출력
    if (ans == solve()) {
      printf("correct\n");
    } else
      printf("wrong\n");
  }

  fclose (fp);
  return 0;
}