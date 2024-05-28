'''
Author:darwin.lang
Date:2022-10-31 20:25:01
LastEditors:darwin.lang
LastEditTime:2022-10-31 22:08:27
Description:
'''
# problem url: https://codeforces.com/problemset/problem/1754/B

from math import floor
import sys
input = sys.stdin.readline

# 對一個數列, 找一個最大的, 取最小(兩個數值的差額)
def main():
  answer_string:list = []
  line_count = inp()
  while(line_count):
    temp_answer:list = []
    number_of_len = inp()
    if(number_of_len % 2 == 0):
      list_1 = []
      list_2 = []
      difference = int(number_of_len / 2)
      for i in range(0,int(number_of_len / 2)):
        list_1.append(i + 1)
        list_2.append(i+1 + difference)
      # print(list_1)
      # print(list_2)
      for idx, x in enumerate(list_1):
        idx+=1
        temp_answer.append(list_1[-idx:][0])
        temp_answer.append(list_2[-idx:][0])
    else:
      list_1 = []
      list_2 = []
      difference = floor(number_of_len / 2)
      for i in range(0, int(number_of_len / 2) + 1):
        list_1.append(i + 1)
        list_2.append(i+1 + difference)
    
      list_2 = list_2[1:]
      for idx, x in enumerate(list_1):
          idx+=1
          temp_answer.append(list_1[-idx:][0])
          temp_answer.append(list_2[-idx:][0])
      temp_answer.pop()
    answer_string.append(temp_answer)

    line_count -= 1
  output(answer_string)
  
def inp(): 
    return(int(input()))
def output(answer_string: list):
  for value in answer_string:
    print(" ".join(str(ele) for ele in value ))
main()