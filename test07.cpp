//
// Created by Chaewon Jeong on 2025. 1. 4..
//
// 1. library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 2. 자료 구조

// 3. solve() --> 문제풀이
// 분할 정복 : N --> N-1

int solve(int N, int x, int y) {
// 0. 예외처리: N == 1일 때
  if(N == 1) {
    if (x == 0 && y == 0)
      return 0;
    else if (x == 1 && y == 0)
      return 1;
    else if (x == 0 && y == 1)
      return 2;
    else if (x == 1 && y == 1)
      return 3;
    else
      return -1; // error!
  }
// 1. 분할 : N --> N-1, (2^N X 2^N --> 2^(N-1) X 2^(N-1) 4분할
  int mid = N - 1;
  int half = pow(2, mid);

  int new_x, new_y;
  int offset;

  if( x < half) { // x < 2^(N-1)
    if (y < half) { // --> 0 번째 구간
      new_x = x;
      new_y = y;
      offset = 0;
    }
    else { // --> 2 번째 구간
      new_x = x;
      new_y = y - half;
      offset = 2 * half*half;
    }

  }
  else {
    if (y < half) { // --> 1 번째 구간
      new_x = x - half;
      new_y = y;
      offset = half*half;
    }
    else { // --> 4 번째 구간
      new_x = x - half;
      new_y = y - half;
      offset = 3 * half*half;
    }
  }
// 2. 정복 & 3. 결합
  return solve ( N - 1, new_x, new_y ) + offset;

// 4. main() --> 입출력, solve() 호출, 결과 출력

}

int main() {
// visual studio에서 프로그램을 실행 --> ctrl + F5
// 1. 입출력
  FILE* fp;
  fopen_s(&fp, "input.txt", "r+t");
  int tc;
  int a, b, c;
  int ans, sol;

  fscanf (fp, "%d", &tc);
  for(int i = 0; i < tc; i++) {
    fscanf_s (fp, "%d %d %d", &a, &b, &c);
    fscanf_s (fp, "%d", &ans, &sol);

//    printf ("%d %d %d\n", a, b, c);
//    printf("%d\n", ans);

    //2. solve호춯
    sol = solve(a, b, c);

    // 3. 결과 출력
    if(ans == sol)
      printf("correct\n");
    else
      printf("wrong\n");
  }

  fclose_s(fp);
  printf("Hello World!\n");
  return 0;
}