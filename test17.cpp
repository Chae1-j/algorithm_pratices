//
// Created by Chaewon Jeong on 2025. 1. 19..
//

#include "test17.h"
// 1. library
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

// 2. 자료구조

// 3. solve 함수 --> solve 함수 내에서 queue를 사용
//        입력 : 두 숫자 a,b
//        출력 : a에서 b를 만들기 위해서 필요한 연산의 수 --> int
int solve(int a, int b) {
  int u, d;
  int child[3], dist[3];
// a부터 3개의 연산을 적용해서 값들을 생성 > graph를 이용해서 관리 > queue를 이용해서 관리
//  queue<int> myq;
// new > queue에 node의 값과 함께 distance를 저장 > 2개의 값을 저장 > pair
// myq2의 원소 : (값, 거리)
// 값 > pair.first
// 거리 > pair.second
  queue<pair<int, int> > myq2; // node값과 distance
//  myq.push(a);
  myq2.push(make_pair(a, 0));


  while (!myq2.empty()) {
    // 1. queue에서 원소 하나를 추출 --> u
//    u = myq.front(); // queue의  front 연산은 맨 앞에 있는 원소를 읽어옴. 제거는 안함
//    myq.pop(); // queue의 맨 앞의 원소를 제거
    u = myq2.front().first; // vertex의 값
    d = myq2.front().second; // vertex의 distance
    // 2. u의 3개의 child node를 생성:
    //    child[0] = u * 2;
    //    child[1] = u * 3;
    //    child[2] = u * 5;
    child[0] = u * 2;
    child[1] = u * 3;
    child[2] = u * 5;

    dist[0] = d + 1;
    dist[1] = d + 1;
    dist[2] = d + 1;
    // 3. 모든 child에 대해서 그 값이 b보다 작으면 queue에 넣어서 수행
    for(int i = 0; i < 3; i++) {
      if(child[i] == b) {
        printf("ok\n");
        return dist[i];
      }
      if(child[i] > b) continue;

      myq2.push(make_pair(child[i], dist[i]));
    }
    printf("not ok\n");
    return -1;
  }

}

// 4. main 함수
int main() {
  FILE *fp;
  fopen("test17_input.txt", "r+t");

  int tc;
  int a, b;
  int sol, ans;

  fscanf (fp, "%d", &tc);
  for(int i = 0; i < tc; i++) {
  // 읽기
    fscanf(fp, "%d%d", &a, &b);
    fscanf (fp, "%d", &ans);

    printf ("%d %d\n", a, b);
    printf("%d\n", ans);
  // solve() 호출
  sol - solve(a, b);
  // 출력
  if (sol == ans) {
    printf("correct\n");
  } else {
    printf("wrong\n");
  }

  }

  fclose(fp);
  return 0;
}