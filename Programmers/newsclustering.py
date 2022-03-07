import math

def solution(str1, str2):
    answer = 0
    
    st1 = []
    st2 = []   
                
    st1 = makeset(str1)
    st2 = makeset(str2)
    
    st1_c = st1.copy()
    st2_c = st2.copy()
    
    gyo = []
    for a in st1:
        if a in st2_c:
            gyo.append(a)
            st1_c.remove(a)
            st2_c.remove(a)
            
    hap = gyo + st1_c + st2_c
    
    if gyo == [] and hap == []:
        return 65536
    else:
        answer = math.floor(len(gyo)/len(hap)*65536)
    
    return answer


def makeset(s):
    s = s.upper()
    arr = []
    
    for i in range(len(s)-1):
        if s[i:i+2].isalpha():
            arr.append(s[i]+s[i+1])
               
    return arr