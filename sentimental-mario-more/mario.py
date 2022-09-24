import sys


def main():
    Height = get_height()
    if(Height <1):
        print("Height must be higher than 0")
        sys.exit()
    else:
        buildp(Height, Height)


def buildp(number, loop):  # recursive func.
    if number == 0:
        return
    print(" " * (number-1), end="")  # the sape we want
    print("#"*(loop-number+1), end="")
    print("  ", end="")
    print("#"*(loop-number+1), end="")
    print(" " * (number-1))
    buildp(number-1, loop)

def get_height():
    while True:
        try:
            Height = int(input("Height: "))
            return Height
        except ValueError:
            print("Enter valid value")
 # running the main
if __name__ == "__main__":
    main()
