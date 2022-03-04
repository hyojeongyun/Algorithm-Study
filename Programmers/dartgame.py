import math

def solution(dartResult):
    answer = 0

    idx = 0
    score = []
    cnt = 0

    for cnt in range(3):
        nowscore = 0
        num = int(dartResult[idx])
        idx += 1

        if dartResult[idx] == '0':
            num = 10
            idx += 1

        if dartResult[idx] == 'S':
            nowscore = math.pow(num, 1)
        elif dartResult[idx] == 'D':
            nowscore = math.pow(num, 2)
        elif dartResult[idx] == 'T':
            nowscore = math.pow(num, 3)

        if idx < len(dartResult) - 1:
            idx += 1

        if dartResult[idx] == '*':
            if cnt == 0:
                nowscore *= 2
            else:
                nowscore *= 2
                score[cnt - 1] *= 2
            idx += 1
        elif dartResult[idx] == '#':
            nowscore *= -1
            idx += 1

        score.append(nowscore)

    for s in score:
        answer += s

    print(int(answer))
    return answer