from cs50 import get_float

def main():
    change = 0
    while (change < 0.01):
        change = get_float("Change owed: ")
    change = int(change * 100)
    coins = calc_coins(change)
    print(coins)


def calc_coins(change):
    quarters = int(change / 25)
    change = change - (quarters * 25)
    dimes = int(change / 10)
    change = change - (dimes * 10)
    nickels = int(change / 5)
    change = change - (nickels * 5)
    pennies = int(change / 1)

    coins = quarters + dimes + nickels + pennies
    return coins


main()