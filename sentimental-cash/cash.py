from cs50 import get_float
from math import floor

change = 0
# taking the valid input
while (change < 1):
    try:
        change = 100*get_float("Change owed: ")
    except ValueError:
        print("invalid input")

quarter = int(change / 25.0)  # getting quarter
change = change - quarter * 25

dime = int(change / 10.0)  # dimes
change = change - dime * 10

nickels = int(change/5)
pennies = change - nickels*5  # pennies is the rest

print(int(quarter + dime + nickels + pennies))  # sum of them all

