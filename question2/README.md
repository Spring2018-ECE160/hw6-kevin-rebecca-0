## Question 1
(K&R Exercise 5-13) Write the program <code>tail</code>, which prints the last n lines of its input. By default, n is 10, let us say, but it can be changed by an optional argument, so that <code> tail -n</code> prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Seciton 5.6, not in a two-dimensional array of fixed size.

Compile Steps: 

	gcc qqq2.c

Output:

	Running this:
	./a.exe < qqq2.c
	Yields this:
	
	void writelines(char *lineptr[], int nlines, int show_lines)
	{
        	int i;
        	while (nlines-- > 0)
        	if (nlines < show_lines)
                	printf("%s\n", *lineptr++);
        	else
        	        lineptr++;
	}

	Running this:
	./a.exe < qqq2.c -20
        Yields this: 
			{
                        	line[len-1] = '\0';
                        	strcpy(s, line);
                        	lineptr[nlines++] = s;
                        	s += len;
                        	total += len;
                	}
        	}
        	return nlines;
	}

	void writelines(char *lineptr[], int nlines, int show_lines)
	{
        	int i;
        	while (nlines-- > 0)
        	if (nlines < show_lines)
        	        printf("%s\n", *lineptr++);
        	else
        	        lineptr++;
	}
