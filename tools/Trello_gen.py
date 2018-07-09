id_list = []

while True:
    ID = input()
    if ID=="0":
        break;
    else:
        id_list.append(ID)

print("[C++]")
for ID in id_list:
    URL = "https://github.com/shizhonghao/leetcode/blob/master/" + ID + ".cpp"
    print(ID + ":"+ URL)

while True:
    pass
