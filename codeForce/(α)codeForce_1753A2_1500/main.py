from cmath import pi


class Node:
  def __init__(self, l:int, r:int):
      self.l = l
      self.r = r

# For taking integer inputs
def inp(): 
    return(int(input()))

# invr — For taking space separated integer variable inputs.
def invr() -> list:
    return(list(map(int,input().split())))

def main():
  line_count = inp()
  row_answer:list = []
  answer_count:list = []
  while(line_count):

    temp_row:list = []
    n = inp() 
    ele_of_row = invr()
    temp_row.extend(ele_of_row)
    temp_sum = sum(temp_row)
    operator_list: list =[0] *  len(temp_row)

    # 判斷這個變數需不需要往後面挪, 並且這個題面的range就是 2 |(1 + (-1))|
    for i in range(1, len(temp_row)):
      if(temp_sum > 0 and temp_row[i] == 1 ):
        operator_list[i - 1] = 1
        temp_sum -= 2
        i += 1
      if(temp_sum < 0 and temp_row[i] == -1):
        operator_list[i - 1] = 1
        temp_sum += 2
        i += 1
    # print("temp_sum2", temp_sum)
    if(temp_sum != 0):
      answer_count.append(-1)
      row_answer.append([])
      line_count -= 1
      continue;
    l, r, output_answer_count = 0, 0, 0
    
    # print('operator_list', operator_list)
    i = 0
    temp_row_answer:list = []
    while i < n:
      output_idx = i + 1
      l = output_idx
      r = output_idx
      # print('idx:', output_idx )
      
      if(operator_list[i]):
        while(i < n and operator_list[i]):
          r = output_idx + 1
          i += 2
        i -= 1
      i += 1
      # print('i:', i)
      temp_row_answer.append(Node(l,r))
      output_answer_count += 1
    # 將要輸出的東西打包, 並且照著題目的格式處理 
    row_answer.append(list(temp_row_answer))
    answer_count.append(output_answer_count)
    line_count -= 1

  idx_of_ouput = 0
  while idx_of_ouput < len(row_answer):
    print(answer_count[idx_of_ouput])
    for ele in row_answer[idx_of_ouput]:
      print(ele.l, " ", ele.r)
    idx_of_ouput += 1

main()
    
