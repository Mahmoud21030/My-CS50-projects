import sys


def main():
    Height = int(input("Height: "))
    buildp(Height, Height)


def buildp(number, loop):  # recursive func.
    if number == 0:
        return
    print(" " * (number-1), end="")  # the sape we want
    print("#"*(loop-number+1), end="")
    print(" ", end="")
    print("#"*(loop-number+1), end="")
    print(" " * (number-1))
    buildp(number-1, loop)

 # running the main
if __name__ == "__main__":
    main()
