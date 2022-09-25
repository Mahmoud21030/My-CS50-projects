from cs50 import get_string

string = get_string("Text: ")

w = 1 # w =1
s = 0
l=0
for letter in string: # getting l,s
    if (letter == " "):
        w += 1
    if (letter == "!" or letter == "."): # number of sentences
        s += 1
    if(letter.isalpha()):
        l+=1


L = l/w *100
S = s/w *100
eq =int(0.0588 * L - 0.296 * S - 15.8)

if(eq<1):
    print("Before Grade 1")
if(eq>16):
    print("Grade 16+")
else:
    print("Grade "+str(eq))

