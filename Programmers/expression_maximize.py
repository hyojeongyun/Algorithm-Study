from itertools import permutations

def cal(n1,n2,op):
    if op == '+':
        return n1+n2
    elif op == '*':
        return n1*n2
    elif op == '-':
        return n1-n2

def solution(expression):
    answer = 0
    pri = ['*', '+', '-']
    temp = 0
    num = []
    op = []
    priList = list(permutations(pri, 3))
    
    for e in expression:
        if e in pri:
            num.append(temp)
            op.append(e)
            temp = 0
        else:
            if temp != 0:
                temp *= 10
            temp += int(e)
            
    if temp != 0:
        num.append(temp)
    
    
    for p in priList:
        tempNum = num.copy()
        tempOp = op.copy()
        while True:
            find = False
            for i in range(len(tempOp)):
                if p[0] == tempOp[i]:
                    tempNum[i] = cal(tempNum[i], tempNum[i+1], tempOp[i])
                    tempNum.pop(i+1)
                    tempOp.pop(i)
                    find = True
                    break
            if find == False:
                break
        while True:
            find = False
            for i in range(len(tempOp)):
                if p[1] == tempOp[i]:
                    tempNum[i] = cal(tempNum[i], tempNum[i+1], tempOp[i])
                    tempNum.pop(i+1)
                    tempOp.pop(i)
                    find = True
                    break
            if find == False:
                break
        while True:
            find = False
            for i in range(len(tempOp)):
                if p[2] == tempOp[i]:
                    tempNum[i] = cal(tempNum[i], tempNum[i+1], tempOp[i])
                    tempNum.pop(i+1)
                    tempOp.pop(i)
                    find = True
                    break
            if find == False:
                break
        answer = max(answer, abs(tempNum[0]))

    
    return answer