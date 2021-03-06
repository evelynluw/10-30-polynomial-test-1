## The Idea

QED Services International, Inc, was contracted by Whitewater Unified School District to write an Expression Calculator to help their students learn basic algebra through calculus. As in the project was quite large in its scope, QED Services International, Inc, has subcontracted you to finish writing a “proof of concept” program for them. Under a previous contract, you’ve written a class for them, called fraction, but due to an excessive amount work, they have had to subcontract this entire portion of the project to you.

As we know, an Algebraic Expression consists of at least one term, where a term consists of constants multiplied by a variable raised to a power. Constants and powers, per the contract QED Services International, Inc, signed with you can be  positive or negative fractions, positive or negative decimals, or positive or negative integers.

The goal of this project is for you to develop a "command line" Algebraic Expression calculator that will accept up to 26 arbitrarily long algebraic expressions composed of terms, as described above.

The program, named calculate, if started on the command line with no parameters, when ready for input, a prompt such as INPUT: or COMMAND: must be printed. After each successful operation, this prompt will re-appear asking for the next command. Naturally, if the user enters just the return key, then the program will terminate.
When the COMMAND: or INPUT: prompt appears, the user will have the following options:

1. They can enter one of the following commands: LET, EVAL, or PRINT.
   
	a. The command LET must be followed by a space, then a letter (A – Z), a space, then an equal sign (=), then by the algebraic expression the user wishes to assign to this letter. (e.g. LET F = 2X + 4. The result printed upon successful completion will be F = 2X + 4 in this example.

	b. The command EVAL must be followed by a space, then the letter representing a pre-stored algebraic expression, followed by the value within parentheses. (e.g. EVAL F(1/4) ) The program will then print F(1/4) = 4 1/2

	c. The command PRINT must be followed by a space then the letter representing a pre-stored algebraic expression (e.g PRINT F). The program will respond by printing F = 2X + 4, for example.

2. They can enter one of the following:

	a. An expression, such as F = G + H, where F, G, and H are all pre-stored algebraic expressions. Upon completion, the program will print F = 2X + 4, for example.

	b. An expression, such as F = G - H, where F, G, and H are all pre-stored algebraic expressions. Upon completion, the program will print F = 2X + 4, for example.

	c. An expression, such as F = G * H, where F, G, and H are all pre-stored algebraic expressions. Upon completion, the program will print F = 2X + 4, for example

	d. An expression, such as F = G’, where G’ is the derivative of G. As with the proceeding, the resultant algebraic expression will be printed.

	e. This is the same as the above, but with the ability to enter an arbitrary derivative (such as F = G’’’). As with the proceeding, the resultant algebraic expression will be printed.

3. They can enter LOAD followed by a file name. This will load up to 26 pre-defined, or saved earlier, algebraic expressions. (See below for additional when there are more than one parameter on the command line)

4. They can enter SAVE followed by a file name. This will save the contents of the 26 algebraic expressions to a file. As with all of the programs that you have done, the program must ensure that files are not accidentally overwritten and so forth. File names for these files must end in “.exp”

## Command Line Parameters:

When there is one parameter on the command line after the name of the program, it will load the file associated with that name. If there is no extension on the name given, the default extension of “.exp” must be added to the file name before opening the file. Conversely, if there is a /h or /? As the parameter, then a “help message” must be displayed to the user and the program terminates.

When there are two parameters on the command line after the name of the program, the first parameter must be the word EXECUTE or RECORD. The next parameter is a “script” file, which is composed of commands, as stated from the above section which deals with input from the command line. If the word EXECUTE is present, then the program must read the file and perform all of the statements within the file. If the word in RECORD, then the program must save to a file all of the commands that the user enters in via the command line. Script files must have an extension of “.spt”; and, as above, the “.spt” must be added if the user did not provide it.

If there are more than two parameters on the command line, then the program must “error out.” This means to notify the user that the program will be quitting and why it did so.

## Program Requirements

All values must be stored in a class called Fraction. This class must be able to handle all operations between decimals, fractions, and integers.
All data must be stored as a Fraction with all output given as a Fraction.
Only ONE input stream function in the main.cpp can be written for reading of input (whether it comes from a command line or a file). Thus, the input function must be passed a parameter telling it which stream is to be used for the reading of commands. 
If the commands are coming from a file, they must be echoed to the screen. If the user is entering them, they must not be echoed.
All strings used must be C++ strings.
Exceptions must be used accordingly. Such as when a file does not exist, divide by zero, invalid input, and so forth.
There must be a class called expression that will store the expressions entered. This class must have Fractions for each term of the expression. (Hint: dynamic arrays or vectors)
Terms of the expression must be stored in either a structure or a class (preferred).

## Hints

You can never forget anything learned in any CS course. Data storage sizes are very important, and mismatches can cause severe problems.
cplusplus.com is your friend.
“Divide and Concur” this program. First, jointly design the header files, then split up the coding. Then combine headers, the main, and so forth to make a working program.
Rules of the Test:

You may use any resource you wish, as long as it can be FULLY DOCUMENTED within your code.
You may work in teams of two and submit one test for the team.
You must be prepared to answer any question about your program when you demonstrate its functionality during lab.
Your program must, as discussed in class, conform to object oriented design constructs. (In short, this means that if a fraction needs to do something, all code for what needs to be done must be in the fraction class, its friends, and so forth)

## Extra Credits

- Addition of the ability to allow for function composition such as F = G(H), where G and H are algebraic expressions (50 points)
- Addition of the ability to allow for division of expressions, such as F = G/H (50 points)
- Addition of the ability to allow for operations such as F = (2X + 4)^3, without the use of the LET command (this implies that the LET command is depreciated and that the ability of raising an algebraic expression to a positive power is available) (100 points)
- Addition of the ability to solve for all of the zeros of the polynomial expression using Newton's Algorithm (100 points).
- Addition of the ability to do all of the above in multivariate form (x, y, z is the limit). (250 points)
- Addition of the ability to factor expressions. (100 points)

## Resources

http://www.repositorio.ufop.br/bitstream/123456789/4361/1/ARTIGO_ImplementingComputerAlgebra.pdf 

https://en.wikipedia.org/wiki/Computer_algebra#References

http://www.ukma.edu.ua/~yubod/teach/compalgebra/%5BJoel_S._Cohen%5D_Computer_algebra_and_symbolic_comp(BookFi.org).pdf
