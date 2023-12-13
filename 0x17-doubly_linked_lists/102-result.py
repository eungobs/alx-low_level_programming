#!/usr/bin/bash/python3

def is_palindrome(n):
    return str(n) == str(n)[::-1]

def largest_palindrome_product():
    largest_palindrome = 0

    for i in range(999, 99, -1):
        for j in range(i, 99, -1):
            product = i * j
            if product < largest_palindrome:
                break
            if is_palindrome(product):
                largest_palindrome = product

    return largest_palindrome

result = largest_palindrome_product()

with open('102-result', 'w') as file:
    file.write(str(result))
