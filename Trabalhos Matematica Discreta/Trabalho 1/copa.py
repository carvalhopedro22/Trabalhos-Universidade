def permutacoes(n):
    if len(n) == 1:
        return [n]
    permut = permutacoes(n[1:])
    letra1 = n[0]
    permuts = []
    for permut in permut:
        for i in range(len(permut)+1):
            perm = permut[:i] + letra1 + permut[i:]
            if perm not in permuts:
                permuts.append(perm)
    return permuts
def fat(k):
    if k == 0:
        return 1;
    else:
        return k*fat(k-1);
veti = []
vet1 = []
n = input()
N1 = int(input())
N2 = int(input())
NUM = N1 + N2
A = n[0]* N1
A += n[2]* N2
if N1!= 0 or N2!= 0:
    veti.append(permutacoes(A))
    num1 = fat(N1)
    num2 = fat(N2)
    N = fat(NUM)
    for i in range(int(N/(num1*num2))):
        vet1.append(veti[0][i])
    vet1.sort()
    for i in vet1:
        print(i)
else:
    print(0)