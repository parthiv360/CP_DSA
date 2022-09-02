for i in range(0, int(input())):
    input()
    s = input()
    if s[0] == '9':
        print(10**len(s)+10**(len(s)-1)+11-int(s))
    else:
        print(10**len(s)-1-int(s))
