#!/bin/bash

./convert
./convert not_a_literal
./convert 50 hey

./convert 10
./convert 0
./convert a
./convert 4.323423
./convert 34.4342f
./convert -4
./convert -343.423
./convert -inff
./convert +inff
./convert nanf
./convert -inf
./convert +inf
./convert nan
