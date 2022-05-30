//문제 : 불량 사용자

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int userN;
vector<int> find_id[10];
int visit[10];
int answer;
vector<string> ans;

void dfs(int x, int cnt) {
    if (cnt == n) {
        string str = "";
        for (int i = 0; i < userN; i++) {
            if (visit[i] == 1) str += to_string(i);
        }
        bool ok = true;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == str) {
                ok = false;
            }
        }
        if (ok) ans.push_back(str);

    }


    for (int j = 0; j < find_id[x].size(); j++) {
        if (visit[find_id[x][j]] == 0) {
            visit[find_id[x][j]] = 1;
            dfs(x + 1, cnt + 1);
            visit[find_id[x][j]] = 0;
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {

    n = banned_id.size();
    userN = user_id.size();

    for (int i = 0; i < banned_id.size(); i++) {
        string ban = banned_id[i];

        for (int j = 0; j < user_id.size(); j++) {
            string user = user_id[j];

            if (ban.size() == user.size()) {
                int cnt = 0;
                for (int k = 0; k < ban.size(); k++) {
                    if (ban[k] == user[k] || ban[k] == '*') {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }

                if (cnt == ban.size()) {
                    find_id[i].push_back(j);
                }
            }
        }
    }

    dfs(0, 0);

    answer = ans.size();

    return answer;
}