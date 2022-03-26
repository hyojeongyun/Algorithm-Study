//문제 - 멀쩡한 사각형

using namespace std;

int gcd(int w, int h) {
    int c;

    while (h != 0) {
        c = w % h;
        w = h;
        h = c;
    }
    return w;
}

long long solution(int w, int h) {
    long long answer = 0;

    int g = gcd(w, h);

    answer = (long long)w * (long long)h;
    answer -= w + h - g;

    return answer;
}