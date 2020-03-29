#include <iostream>

using namespace std;

int a[100005] = {0,}, s, n;

int main() {
    int x;


    scanf("%d %d", &n, &s);

    scanf("%d", &a[0]);

    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        a[i] = a[i - 1] + x;
    }

    int answer = 0;

    for (int i = 1; i <= n; ++i){
        if(s<=a[i-1]){
            answer = i;
            break;
        }
        for(int j = 0; j < n-i; ++j){
            if(s <= a[j+i]-a[j]){
                answer = i;
                break;
            }
        }
        if(answer != 0){
            break;
        }
    }

    printf("%d", answer);

    return 0;
}
