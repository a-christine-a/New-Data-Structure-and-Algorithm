def get_gcd(num1, num2):
    print("Am about to find GCD but wait ...")
    while(num2 != 0):
        t = num1
        num1 = num2
        num2 = t % num2
    return num1

num1 = int(input("Enter a number : "))
num2 = int(input("Enter the second number : "))
print(f"GCD is {get_gcd(num1, num2)}")
