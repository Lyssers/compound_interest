# Calculate compound interest

1. Compile with `gcc compoundcalc.c -o compoundcalc.o`

2. Run with `./compoundcalc.o`

3. Enter the parameters as prompted.

I made this to learn-by-doing some basic input validation

So this should handle fairly free-form inputs as long as there are integers, e.g. 

```
└─$ ./compound.o

This program calculates compound interest.
Please Enter the following information omitting currency symbols.
Please Enter initial investment (principal): 10000$$

Please Enter (simple) interest rate: 5 percents

Please Enter frequency of interest payouts per year: only 1 time a year

Please Enter time in years: uhmmmmmmm, like 2 years I reckon?

Starting Balance: 10000.00:
Final Balance with Flat (Simple) Interest: 11000.00

Compound interest: 1025.00
Final Balance with Compound Interest: 11025.00

```
