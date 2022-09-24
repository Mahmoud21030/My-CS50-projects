from cs50 import get_float
from math import floor

change = get_float("Change owed: ")

quarter = int(change / 25.0)

dime = int((quarter % 25) /10.0)

penn