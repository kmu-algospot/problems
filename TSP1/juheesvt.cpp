//
// Created by juheeSVT on 2020-01-05.
//

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

const int MAX = 8;

int n; //도시의 수

double dist[MAX][MAX]; //두 도시간의 거리를 저장하는 배열

//path:지금까지 만든 경로
//visited: 각 도시의 방문 여부
//currentLength: 지금까지 만든 경로의 길이
//나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환
double shortestPath(int n, vector<int> &path, vector<bool> &visited, double currentLength) {

    //기저 사례:모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
    if (path.size() == n)
        return currentLength;

    double result = numeric_limits<double>::max(); // double형 변수가 표현 가능한 가장 큰 값으로 초기화

    //다음 방문할 도시를 전부 시도
    for (int next = 0; next < n; next++) {
        if (visited[next])      // 방문했으면 넘어가긔 ~
            continue;

        int here = path.back(); // 지금까지의 마지막 경로
        path.push_back(next);   // 경로에 next 추가
        visited[next] = true;   // next 방문 체크

        //나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다

        double candidate = shortestPath(n, path, visited, currentLength + dist[here][next]);

        result = min(result, candidate);

        visited[next] = false;

        path.pop_back();

    }
    return result;
}

int main(void) {

    int testCase;
    double result;

    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        cin >> n;

        //거리 입력
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> dist[j][k];
            }
        }

        double answer = numeric_limits<double>::max();

        for (int j = 0; j < n; j++) {
            vector<int> path(1, j);         //j번째 도시에서 출발
            vector<bool> visited(n, false);
            visited[j] = true;              //출발했으므로 방문
            result = shortestPath(n, path, visited, 0.0000000000);

            if (answer > result) {//기존보다 크면 덮어쓰지 않는다
                answer = result;
            }
        }
        printf("%.10f\n", answer);
    }
    return 0;
}
