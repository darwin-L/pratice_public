'''
Author:darwin.lang
Date:2022-10-31 20:33:29
LastEditors:darwin.lang
LastEditTime:2022-10-31 20:35:17
Description:
'''
# For taking integer inputs
def inp(): 
    return(int(input()))
# inlt — For taking List inputs.
def inlt():
    return(list(map(int,input().split())))
    
# insr — For taking string inputs. Actually it returns a List of Characters, instead of a string
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
# invr — For taking space separated integer variable inputs.
def invr() -> list:
    return(list(map(int,input().split())))