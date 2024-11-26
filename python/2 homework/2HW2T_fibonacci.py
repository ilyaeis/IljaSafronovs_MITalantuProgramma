def fibo(f1, f2, index):
    if index == 0: return f1
    else:
        index -= 1 
        return fibo(f2, f1+f2, index)

if __name__ == "__main__":
    try: 
        input_num = int(input("Enter the index of fibo num you wawnt to get (starting from 0): ")) 
        print(f"The fibo number with this index is {fibo(0, 1, input_num)}!")
    except: 
        print("wrong input")
