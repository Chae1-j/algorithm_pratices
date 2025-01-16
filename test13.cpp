// 1. library
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// 2. 자료구조
// graph & visit & sol
vector<int> graph[100001];
int visit[100001];
int sol[100001];
int n;
int ans[100001];

// 3. solve 함수
void solve() {

}
// 4. main 함수 : 입력, solve() 호출, 출력
int main() {
  FILE* fp;
  fopen_s(&fp, "test13_input.txt", "r+t");

  int tc;// number of test case
  fscanf_s(fp, "%d", &tc);
  for (int i = 0; i < tc; i++) {
    // 입력 : 초기화, n (vertex의 수) & (n-1)개의 edge
    // 초기화
    for(int j = 0; j < 100001; j++) {
      graph[j].empty(); // empty는 vector의 값을 초기화하는 함수

      //n 입력
      fscanf_s(fp, "%d", &n);

      for(int j = 0; j < n-1; j++) {
        fscanf_s(fp, "%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
      }

    }

    // solve() 호출

    // 출력
  }
  fclose(fp);
  return 0;
}

