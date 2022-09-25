from cs50 import get_string

string = get_string("Text: ")

w = 1 # w =1
s = 0

for letter in string: # getting l,s
    if (letter == " "):
        w += 1
    if (letter == "!" or letter == "."): # number of sentences
        s += 1

l = len(string) #number of letters in string
L = l/100
S = s/100 *l
eq =0.0588 * L - 0.296 * S - 15.8

print(eq)

