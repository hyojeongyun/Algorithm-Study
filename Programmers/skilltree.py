def solution(skill, skill_trees):
    answer = 0
    
    for st in skill_trees:
        cnt = 0
        ok = True
        
        for s in st:
            if s in skill and skill[cnt] != s:
                ok = False
                break
            elif s in skill and skill[cnt] == s:
                cnt+=1
            
        if ok :
            answer+=1
    
    return answer