# 거리두기 확인하기

def social_distancing(place):
    for i in range(5):
        for j in range(5):
            if place[i][j]=='P':
                if i - 1 >=0 and place[i-1][j]=='P':
                    return False
                if j - 1 >=0 and place[i][j-1]=='P':
                    return False
                if i + 1 < 5 and place[i+1][j]=='P':
                    return False
                if j + 1 < 5 and place[i][j+1]=='P':
                    return False
                
                if i - 2 >=0 and place[i-2][j]=='P' and place[i-1][j]=='O':
                    return False
                if j - 2 >=0 and place[i][j-2]=='P' and place[i][j-1]=='O':
                    return False
                if i + 2 <5 and place[i+2][j]=='P' and place[i+1][j]=='O':
                    return False
                if j + 2 <5 and place[i][j+2]=='P' and place[i][j+1]=='O':
                    return False
                
                if i-1>=0 and j-1>=0 and place[i-1][j-1]=='P':
                    if place[i-1][j]=='O' or place[i][j-1]=='O':
                        return False
                if i-1>=0 and j+1<5 and place[i-1][j+1]=='P':
                    if place[i-1][j]=='O' or place[i][j+1]=='O':
                        return False
                if i+1<5 and j-1>=0 and place[i+1][j-1]=='P':
                    if place[i+1][j]=='O' or place[i][j-1]=='O':
                        return False
                if i+1<5 and j+1<5 and place[i+1][j+1]=='P':
                    if place[i+1][j]=='O' or place[i][j+1]=='O':
                        return False
    return True
                

def solution(places):
    answer = []
    
    for p in places:
        place = []
        for i in range(5):
            arr = []
            for j in range(5):
                arr.append(p[i][j])
            place.append(arr)
        
        if social_distancing(place)==True:
            answer.append(1)
        else:
            answer.append(0)
    
    return answer