#!/usr/bin/python3
from sys import (stdin, stdout)

total_size = 0

statuses = {
    "200": 0,
    "301": 0,
    "400": 0, "401": 0, "403": 0, "404": 0, "405": 0,
    "500": 0
}

lines = 0

try:
    for line in stdin:
        status, size = line.split(' ')[7:]
        total_size += int(size)
        statuses[status] += 1
        lines += 1
        if lines == 10:
            print('Total Size: {}'.format(total_size))
            for (code, count) in sorted(statuses.items()):
                if count > 0:
                    print('{}: {}'.format(code, count))
                lines = 0

finally:
    print('Total Size: {}'.format(total_size))
    for (code, count) in sorted(statuses.items()):
        if count > 0:
            print('{}: {}'.format(code, count))
