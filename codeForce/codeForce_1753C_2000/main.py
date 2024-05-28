'''
Author:darwin.lang
Date:2022-11-16 21:23:22
LastEditors:darwin.lang
LastEditTime:2022-11-16 21:31:00
Description:
'''
# Url: https://codeforces.com/problemset/problem/1753/C

# invr — For taking space separated integer variable inputs.
def invr() -> list:
    return(list(map(int,input().split())))

P = 998244353
def modular_solver(a, P):
  return pow(a, (P-2), P) % P

# still fail test3 time limit
def qpow(n,m) -> int:
  res = 1
  base = n
  while m != 0:
    if(m & 1 == 1):
      res *= base % P
    base *= base % P
    m = m >> 1
  return res

def problem():
  n = int(input())
  sequence = invr()
  count_zero = n - sum(sequence)
  # 計算有多少個1在前面, 題目要解的是 [0 ... 1]
  least_swap_count = sum(sequence[:count_zero])

  # C(n,2)
  numerator = n*(n-1)//2
  i = 1
  expect_individual:list = []
  
  # 每一次成功的交換操作後, 有效的交換次數會以n-1的平方數量減少
  while i <= least_swap_count:
    expect_individual.append(modular_solver(pow((i), 2), P) % P)
    i += 1 
  expect = (numerator % P)*sum(expect_individual) % P
  return expect
  
t = int(input())
for _ in range(t):
  ans = problem()
  print(ans)