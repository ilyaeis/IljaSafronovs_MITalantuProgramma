num = int(input("Enter the number: "))

sum = 0
for i in range(7, num+1, 1):
    if i % 7 == 0:
        sum += i

print(f"Sum of num from 1 to {num} divisible by 7 is {sum}")