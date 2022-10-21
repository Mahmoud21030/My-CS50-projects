import sys


def main():
    Height = get_height()
    buildp(Height, Height)


def buildp(number, loop):  # recursive func.
    if number == 0:
        return
    print(" " * (number-1), end="")  # the sape we want
    print("#"*(loop-number+1), end="")
    print("  ", end="")
    print("#"*(loop-number+1))
    buildp(number-1, loop)

def get_height():
    while True:
        try:  # rejecting conditions
            Height = int(input("Height: "))
            if(Height > 0 and Height < 9):
                return Height
        except ValueError:
            print("Enter valid value")
 # running the main
if __name__ == "__main__":
    main()
