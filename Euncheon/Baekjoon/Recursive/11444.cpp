// Fibonacci
#include <iostream>
#include <map>
#define DIV 1000000007
using namespace std;

long long fibo_small[100001] = {0, 1, };

long long find_nth_fibo(long long n, map<long long, long long> &fibo_big){
    // 도가뉴 항등식? 위키에서 봄
    // F_{m+n} = F_{m-1} * F_{n} + F_{m} * F_{n+1}
    // map을 dp 배열처럼 사용
    if (n < 10){
        return fibo_small[n];
    }
    auto iter = fibo_big.find(n);
    if (iter != fibo_big.end()){
        return iter->second;
    }
    long long a = n / 2;
    long long b = n - a;
    long long term1, term2, term3, term4;
    // printf("n: %lld, a: %lld, b: %lld\n", n, a, b);//erase
    if (a == b) {
        term1 = find_nth_fibo(a-1, fibo_big) % DIV;
        term2 = find_nth_fibo(a, fibo_big) % DIV;
        term3 = term2;
        term4 = (term1 + term2) % DIV;
    }
    else {
        // b = a + 1
        term1 = find_nth_fibo(a, fibo_big) % DIV;
        term2 = term1;
        term3 = find_nth_fibo(b, fibo_big) % DIV;
        term4 = term3;
    }
    long long result = (term1*term2 + term3*term4) % DIV;
    fibo_big.insert(pair<long long, long long>(n, result));
    return result;
}

int main(void) {
    for (int i = 2; i < 100001; i++){
        fibo_small[i] = (fibo_small[i-1] + fibo_small[i-2]) % DIV;
    }
    
    map<long long, long long> fibo_big_numbers;

    long long input;
    cin >> input;
    printf("%lld", find_nth_fibo(input, fibo_big_numbers));
    return 0;
}