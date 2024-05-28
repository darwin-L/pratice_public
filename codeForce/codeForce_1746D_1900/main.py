'''
Author:darwin.lang
Date:2022-11-16 22:05:34
LastEditors:darwin.lang
LastEditTime:2022-11-16 22:40:06
Description:
'''
# Url: https://codeforces.com/problemset/problem/1746/D

import sys, threading

runtime = input()
while runtime > 0:
  runtime -= 1

class treeNode:
    def __init__(self):
        self.child = list()
        self.lable = 0

def DFS(v,k,boolean):
    ret = v.lable * k
    ret2 = v.lable * (k+1)
    child_size = len(v.child)
    if child_size == 0:
        if boolean:
            return [ret,ret2]
        else:
            return [ret ,0]
    if child_size == 1:
        tmp = DFS(v.child[0],k,boolean)
        if boolean:
            return [ret + tmp[0], ret2 + tmp[1]]
        else:
            return [ret + tmp[0], 0]
    k1 = int(k/child_size)
    remind = k - k1*child_size
    if remind == 0 and not boolean:
        for child in v.child:
            tmp = DFS(child,k1,False)
            ret += tmp[0]
        return [ret,0]
    tmp_list = []
    for child in v.child:
        tmp= DFS(child,k1,True)
        ret += tmp[0]
        ret2 += tmp[0]
        dif = tmp[1] - tmp[0]
        tmp_list.append(dif)
    tmp_list.sort()
    tmp_list.reverse()
    i = 0
    while i < remind:
        ret += tmp_list[i]
        ret2 += tmp_list[i]
        i += 1
    if boolean :
        ret2 += tmp_list[remind]
        return [ret,ret2]
    else:
        return [ret,0]

def DFS_Helper():
    t = int(input())
    for iter in range(t):
        line1 = input().split(" ")
        line2 = input().split(" ")
        line3 = input().split(" ")
        n = int(line1[0])
        k = int(line1[1])
        arr_s = [int(x) for x in line3]
        node_list = [treeNode() for i in range(0,n)]
        i = 2
        for x in line2:
            tmp = int(x)
            node_list[tmp-1].child.append(node_list[i-1])
            i += 1
        i = 0
        for s in arr_s:
            node_list[i].lable = s
            i += 1
        root = node_list[0]
        try:
            print(DFS(root, k,False)[0])
        except Exception as e:
            print(e)
    exit()

sys.setrecursionlimit(3*(10**5))
threading.stack_size(10**8)
t1 = threading.Thread(target=DFS_Helper)
t1.start()