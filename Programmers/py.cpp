//문자열 내 p와 y의 개수

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P')p++;
        else if (s[i] == 'y' || s[i] == 'Y')y++;
    }

    if (p != y)answer = false;

    return answer;
}