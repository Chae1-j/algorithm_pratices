//
// Created by Chaewon Jeong on 2025. 1. 12..
//

#include "test10.h"
// 1. library
#include <stdio.h>
#include <stdlib.h>
// 2. 자료구조 : map의 w와 h, map
int w, h;
int map[50][50];

// 3. solve 함수 : map을 받아서 내륙의 갯수(int)를 return
// 입력 : w x h 크기의 map(0과 1로 구성됨)
// 출력 : cell의 갯수
//      (1) cell의 값이 1
//      (2) cell의 상하좌우의 cell들도 값이 1
//      (3) cell 이 가장 자리에 있는 경우는 특별 취급
int solve() {
  int land = 0;

  int dir[4][2] = {{-1,0}, {1, 0}, {0,-1}, {0, 1}};
  int nx, ny; // neighbourhood x, neighbourhood y

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      // neighbourhood 중에서 1인 cell의 갯수 --> cnt
      int cnt = 0;
      // (1) cell의 값이 0인 cell은 고려하지 않음
      if (map[i][j] == 0)
        continue;
      // (2) 4-neighbourhood (x-1, y) (x+1, y), (x, y-1), (x, y+1)을 조사
      for (int k = 0; k < 4; k++) {
        // neighbourhood cell의 위치를 계산
        ny = i + dir[k][1];
        nx = j + dir[k][0];

        // neighbourhood cell의 x가 범위를 벗어나면 통과
        if (nx < 0 || nx >= w) {
          // 범위를 벗어난 neighbourhood cell은 그 값이 1이라고 간주
          cnt++;
          continue;
        }
        // neighbourhood cell의 y가 범위를 벗어나면 통과
        if (ny < 0 || ny >= h) {
          // 범위를 벗어난 neighbourhood cell은 그 값이 1이라고 간주
          cnt++;
          continue;
        }
      }

      if (map[ny][nx] == 1)
        cnt++;

      if (cnt == 4) {
        land++;
      }
    }
  }
  return 0;
}
// 4. main 함수 : 입력 --> solve 호출 --> 출력
int main() {
  FILE* fp;
  fopen_s(&fp, "test10_input.txt", "r+t");
  int tc; // number of test case
  int ans; // 정답
  int sol; // rufrhk

  fscanf_s(fp, "%d", &tc);
  for (int i = 0; i < tc; i++) {
    // 입력 : w, h 입력 --> h줄 w칸만큼 map을 입력. 주의! map 을 초기화 하는 과정이필요
      // w, h 입력
      fscanf_s(fp, "%d %d", &w, &h);
      // map 초기화
      for( int j = 0; j < 50; j++ ) {
        for (int k = 0; k < 50; k++) {
          map[j][k] = 0; // 0으로 초기화
        }
      }
      // map 입력
      for (int j = 0; j < h; j++) { // 줄만큼
        for (int k = 0; k < w; k++) { // 칸만큼
          fscanf_s(fp, "%d", &(map[j][k]));
        }
      }

      fscanf_s(fp, "%d", &ans);

      printf("%d, %d", w, h);
      for(int j = 0; j < h; j++) {
        for(int k = 0; k < w; k++) {
          printf(" %d", map[j][k]);
        }
        printf("\n");
      }
    // solve 호출
    sol = solve();
    printf("%d, %d\n", ans, sol);

    // 출력
    if (sol == ans)
      printf("correct\n");
    else
      printf("wrong\n");
  }
  fclose(fp);
  return 0;
}