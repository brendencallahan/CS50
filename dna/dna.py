import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("error incorrect arguments")
        return

    # Read database file into a variable
    with open(sys.argv[1], "r") as datafile:
        database = [{k: v for k, v in row.items()}
                    for row in csv.DictReader(datafile, skipinitialspace=True)]

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequencefile:
        sequence = sequencefile.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_dna = [*database[0]]
    del str_dna[0]
    sample = {}
    for i in range(len(str_dna)):
        longest = longest_match(sequence, str_dna[i])
        if longest != 0:
            sample[str_dna[i]] = longest
    print(sample)

    # TODO: Check database for matching profiles
    for i in range(len(database)):
        database[i]["counter"] = 0
        for key in sample:
            if (int(sample[key]) == int(database[i][key])):
                database[i]["counter"] += 1

    winner = None
    for i in range(len(database)):
        if database[i]["counter"] == len(sample):
            winner = database[i]["name"]
            print(winner)
            break

    if winner == None:
        print("No match")


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
