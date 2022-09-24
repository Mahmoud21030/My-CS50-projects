def main():
    build(4,4)


def build(number,loop):
    if number == 1:
        return
    print("-" * (number-1), end="")
    print("#"*(loop-number+1))
    build(number-1,loop)

if __name__=="__main__":
    main()