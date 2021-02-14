#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {
    int num_of_inst;
    int bitmask_set = 0;
    scanf("%d", &num_of_inst);

    while(num_of_inst--) {
        char inst[10];
        int x;
        scanf("%s", inst);
        if (strcmp(inst, "add") == 0) {
            scanf("%d", &x);
            int a = 1 << (x-1);
            bitmask_set |= a;
        }
        else if (strcmp(inst, "remove") == 0) {
            scanf("%d", &x);
            int a = 1 << (x-1);
            if ((bitmask_set & a) != 0)
                bitmask_set -= a;
        }
        else if (strcmp(inst, "check") == 0) {
            scanf("%d", &x);
            int a = 1 << (x-1);
            printf("%d\n", (a & bitmask_set) != 0);
        }
        else if (strcmp(inst, "toggle") == 0) {
            scanf("%d", &x);
            int a = 1 << (x-1);
            if ((bitmask_set & a) != 0) {
                bitmask_set -= a;
            }
            else {
                bitmask_set += a;
            }
        }
        else if (strcmp(inst, "all") == 0) {
            bitmask_set = 0x000fffff;
        }
        else if (strcmp(inst, "empty") == 0) {
            bitmask_set = 0;
        }
    }
    return 0;
}