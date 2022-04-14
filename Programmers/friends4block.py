# 프렌즈4블록

def find(m, n, game):
    visit = [[0]*m for _ in range(n)]
    
    for i in range(n-1):
        for j in range(m-1):
            if game[i][j] == game[i][j+1] and game[i][j] == game[i+1][j] and game[i][j]==game[i+1][j+1]:
                if game[i][j]!='0':
                    visit[i][j]=1
                    visit[i][j+1]=1
                    visit[i+1][j]=1
                    visit[i+1][j+1]=1
            
    count = 0
    for i in range(n):
        for j in range(m):
            if visit[i][j]==1:
                count += 1
                
    
    return visit, count
    

def solution(m, n, board):
    answer = 0
    
    game = []
    
    for i in range(n):
        arr = []
        for j in range(m):
            arr.append(board[j][i])
        game.append(arr)

    while True:
        visit, cnt = find(m,n,game)
        answer += cnt
        if cnt == 0:
            break
            
        for i in range(n):
            for j in range(m):
                if visit[i][j]==1:
                    game[i].pop(j)
                    game[i].insert(0, '0')

    
    return answer