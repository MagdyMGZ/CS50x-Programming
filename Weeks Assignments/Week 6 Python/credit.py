"""
Credit
CS50 Problem Set 6
Checks if credit card number is valid using Luhn's Algorithm and which
company the credit card belongs to
"""
from cs50 import get_int


def main():
    # Prompts user for card number
    card = get_int("Number: ")

    # If card is valid, then check the card company
    if valid_card(card):
        card_company(card)
    # Card not valid
    else:
        print("INVALID")


def valid_card(num):
    # Calculates sum according to Luhn's Algorithm
    sum = 0
    for i, c in enumerate(reversed(str(num))):
        if i % 2 == 0:
            sum += int(c)
        else:
            for j in str(int(c) * 2):
                sum += int(j)

    # Checks if sum is divisible by 10
    if sum % 10 == 0:
        return True
    else:
        return False


def card_company(card):
    # Removes all the digits from card number except first 2
    num = int(str(card)[0:2])

    # Check for conditions of all companies
    if (num is 34 or num is 37) and len(str(card)) is 15:
        print("AMEX")
    elif num > 50 and num < 56 and len(str(card)) is 16:
        print("MASTERCARD")
    elif num >= 40 and num < 50 and (len(str(card)) is 13 or len(str(card)) is
                                     16):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()