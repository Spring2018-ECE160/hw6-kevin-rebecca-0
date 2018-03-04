## Question 2

(K&R Exercise 5-14 & 5-15) Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.

Also, add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.

Compile Steps:
    
    gcc q3.c

Output:

    ./a.exe < test1.txt
    Input:
    Hello there!
    123456789
    This is a test.
    Do I work?
    987654321
    Hopefully! :D
    
    Output:
    123456789
    987654321
    Do I work?
    Hello there!
    Hopefully! :D
    This is a test.
    
    
    ./a.exe < test1.txt -n
    Input:
    Hello there!
    123456789
    This is a test.
    Do I work?
    987654321
    Hopefully! :D
    
    Output:
    This is a test.
    Do I work?
    Hopefully! :D
    Hello there!
    123456789
    987654321
    
    
    ./a.exe < test1.txt -r
    Input:
    Hello there!
    123456789
    This is a test.
    Do I work?
    987654321
    Hopefully! :D
    
    Output:
    This is a test.
    Hopefully! :D
    Hello there!
    Do I work?
    987654321
    123456789
    
    
    ./a.exe < test2.txt -f
    Input:
    hello there!
    123456789
    This is a test.
    Do I work?
    987654321
    Hopefully! :D
        
    Output:
    123456789
    987654321
    Do I work?
    hello there!
    Hopefully! :D
    This is a test.
