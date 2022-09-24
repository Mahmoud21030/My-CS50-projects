from cs50 import get_float
from math import floor

change = 100*get_float("Change owed: ")
if(change > 0):
    quarter = int(change / 25.0)
    change = change -quarter *25

    dime = int(change /10.0)
    change = change -dime *10

    nickels =int(change/5)
    pennies = change -nickels*5

    print(quarter + dime + nickels + pennies)



