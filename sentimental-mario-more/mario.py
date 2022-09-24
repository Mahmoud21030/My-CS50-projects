def main():
    build(4,4)


def build(number,loop):
    if number < 0:
        return
    print(" " * (number-1), end="")
    print("#"*(loop-number))


if __name__==__main__:
    main()