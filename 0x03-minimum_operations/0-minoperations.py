#!/usr/bin/python3
"""Module to solve the minimum operations problem.
"""


def minOperations(n):
    """Find the minimun operations to reach n using copy all and paste.

    Arguments:
        n (int): the desired num of characters.

    Returns:
        int:    the minimun number of operations to get that quantity
                of characters, which is the summatory of the prime
                factors of @n.
    """
    if n < 2:
        return 0
    factor = 2
    result = 0
    while n > 1:
        if n % factor == 0:
            n /= factor
            result += factor
        else:
            factor += 1
    return result
