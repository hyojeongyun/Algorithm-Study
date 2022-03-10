def solution(s):
    answer = []
    
    tup = {}
    
    for i in range(len(s)):
        if i == 0 or i == len(s)-1:
            continue
        
        if s[i]=='{':
            arr = []
            num = ""
            for j in range(i+1, len(s)):
                if s[j]!='}' and s[j]!= ',':
                    num += s[j]
                elif s[j]== ',':
                    arr.append(int(num))
                    num = ""
                elif  s[j] =='}':
                    arr.append(int(num))
                    break;
            
            tup[len(arr)]=arr
            
    tup = sorted(tup.items())
    
    for i in range(0, len(tup)):
        for t in tup[i][1]:
            if t not in answer:
                answer.append(t)
            
    return answer