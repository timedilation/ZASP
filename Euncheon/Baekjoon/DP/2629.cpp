#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int num_of_weights, num_of_marbles;
    int weights[30];
    bool measurable[15001] = {0, };

    scanf("%d", &num_of_weights);
    for (int i = 0; i < num_of_weights; i++) {
        scanf("%d", &weights[i]);
    }
    sort(weights, weights + num_of_weights);

    for (int i = 0; i < num_of_weights; i++) {
        bool visited[15001] = {0, };
        for (int j = 1; j <= 15000; j++) {
            if (measurable[j] && not visited[j]) {
                int added = j + weights[i];
                if (added <= 15000 && not measurable[added]) {
                    measurable[added] = true;
                    visited[added] = true;
                }

                int subtracted = j - weights[i];
                if (subtracted > 0 && not measurable[subtracted]) {
                    measurable[subtracted] = true;
                    visited[subtracted] = true;
                }   

                int subtracted2 = weights[i] - j;
                if (subtracted2 > 0 && not measurable[subtracted2]) {
                    measurable[subtracted2] = true;
                    visited[subtracted2] = true;
                }  
            }

            else if (j == weights[i]) {
                measurable[j] = true;
                visited[j] = true;
            }
        }
        
        // printf("m: ");
        // for (int i = 0; i < 30; i++) {
        //     printf("%d", measurable[i]);
        // }
        // printf("\n");
        // printf("v: ");
        // for (int i = 0; i < 30; i++) {
        //     printf("%d", visited[i]);
        // }
        // printf("\n");
    }



    scanf("%d", &num_of_marbles);
    for (int i = 0; i < num_of_marbles; i++) {
        int marble;
        scanf("%d", &marble);
        if (marble > 15000) {
            printf("N ");
            continue;
        }
        else {
            char c = measurable[marble] ? 'Y' : 'N';
            printf("%c ", c);
        }
    }


    return 0;
}