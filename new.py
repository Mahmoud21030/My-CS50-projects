def main():
    from cs50 import get_string
    creditcard = get_string("Number: ")
    valid = str(validity(creditcard, True))
    print(valid)
    if (int(valid) % 10) == 0:
        type = cardtype(creditcard)
        print(type)
  #  else:
      #  print ("INVALID")


def validity(userinput, islast):
    # list = [int(num) for num in userinput]
    sum = 0
    counter = 0
    for i in reversed(userinput):
        if islast:
            sum += int(i)
            islast = False
        else:
            holder = int(i) * 2
            if str(holder)[0] != str(holder):
                holder = (holder % 10) + (holder // 10)
            sum += holder
            islast = True
    return sum


def cardtype(credit):
    print(len(credit))
    print(credit[0])
    print(credit[1])
    if len(credit) == 15 and credit[0] == 3 and (credit[1] == 7 or credit[1] == 4):
        return "AMEX"
    elif len(credit) == 16 and credit[0] == 5 and credit[1] <= 5:
        return "MASTERCARD"
    elif credit[0] == '4' and len(credit) == 13:
        return "VISA"
    elif credit[0] == 4 or len(credit) == 16:
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()
