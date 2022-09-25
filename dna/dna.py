import csv
import sys


def main():

    compare = []  # our database

    if len(sys.argv) != 3:  # check for commandline
        sys.exit("Usage: python dna.py data.csv sequence.txt")
        # getting files' names
    database = sys.argv[1]
    txtfile = sys.argv[2]

    with open(txtfile, "r") as s_file:
        sequence = s_file.read()

    with open(database, "r") as t_file:
        table = csv.DictReader(t_file)
        for data in table:
            compare.append(data)
    #print(compare["AGATC"])



    #  Find longest match of each STR in DNA sequence


    keys =list(compare[0].keys())[1:]
    results={}
    for i in keys:
        results[i]= longest_match(sequence,i)
        print(results)
    counter=0
    for j in range(len(compare)):
        for i in keys:
            if( int(compare[j][i]) == int(results[i])):
                counter+=1
                if(counter == len(keys)):
                    print(compare[j]["name"])
                    sys.exit();
    print("No match")


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
