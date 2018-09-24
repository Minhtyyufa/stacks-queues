Minh-Thai Nguyen
Made in March 2018

  This program was written for Data Structures and Algorithms 1. At it's core, this program implements the basic data structures of stacks and queues. The program interprets commands from a file and outputs the results into another file. These commands include creating a new stack or queue of integer, double, or string type, pushing onto a stack or queue, and popping from a stack or queue. The explicit details are listed below the example.

Formatting of the Input File:
  
  The input file must contain one command per line. To be valid, a command must follow a very specific format. The command must consist of two or three words, depending on the type of command, separated by single spaces. The line must have no leading whitespace before the first word or trailing whitespace after the last word. For the purposes of this assignment, a "word" is defined to be a sequence of letters and digits, except for words representing values of integers or doubles, which might also contain a single negative sign, and/or, in the case of doubles, a single decimal point. All commands will end with a single Unix-style newline character.

  The first word of each command must be "create", "push", or "pop" (all lowercase letters). The second word must be a valid name for a stack or a queue. The first character of every name must be either "i", "d", or "s" (all lowercase), standing for integer, double, or string; this represents the data type that is stored in the particular stack or queue. The rest of the name must consist of only letters and digits. Both uppercase and lowercase letters are allowed, as the program is case sensitive.
  
  If the first word is "create", there must be a third word that will be either "stack" or "queue" (all lowercase letters). This represents the type of list being created. No two lists may have the same name. However, two lists storing different data types (e.g., one list storing integers and another storing strings) may have the same name other than the first characters (in this case, 'i' or 's'). There cannot be a stack and a queue of the same data type that share the same name.

  If the first word is "push", there must be a third word representing a value to be pushed onto the stack or queue. This value must match the appropriate type corresponding to the specified stack or queue, and it must fit into a single variable; if the value is a string, it must be a single word, as defined above (containing only letters and digits).
  
  If the first word is "pop", there must not be a third word. The second word should be the name of the desired stack or queue that the user would like to pop from. This name, however, does not need to be valid. If this is case, the message "ERROR: This name does not exist!"
  
Functionality and Errors:

  This program reads and processes the commands in the text file. After each command is read, the program outputs the string "PROCESSING COMMAND: " followed by the text of the command and then a single Unix-style newline character. All output should be written to the specified output file.

  If the command is a "create" command, and the name of the stack or queue that is specified has already been created (whether it was created as a stack or a queue), the program will output the string "ERROR: This name already exists!". If the name is new, the stack or queue should be created, and no additional output will be written.
  
  If the command is a push command, and the specified name does not exist, the program will output the string "ERROR: This name does not exist!" If the stack or queue does exist, the push operation will be applied, and no additional output will be written.
  
  If the command is a pop command, and the specified name does not exist, the program will output the string "ERROR: This name does not exist!" using the same casing as is displayed here. If the stack or queue does exist, but it is empty, the program will output the string "ERROR: This list is empty!" If the stack or queue does exist and is not empty, the pop operation will be applied, and the program will output "Value popped: ", followed by the value that is popped from the stack or queue.  In this program, a "pop" is assumed to both remove and return a value from the stack or queue.
  
Example

Input file:
create i1 queue
create i1 queue

create i1 stack

create i2 stack

create s99 stack

push i1 50

push i1 100

push i2 -50

push i2 100

push s99 Hello

push s99 World

pop i2

pop s99

push s99 planet

pop i2

push i2 150

Output file:

PROCESSING COMMAND: create i1 queue

PROCESSING COMMAND: create i1 queue

ERROR: This name already exists!

PROCESSING COMMAND: create i1 stack

ERROR: This name already exists!

PROCESSING COMMAND: create i2 stack

PROCESSING COMMAND: create s99 stack

PROCESSING COMMAND: push i1 50

PROCESSING COMMAND: push i1 100

PROCESSING COMMAND: push i2 -50

PROCESSING COMMAND: push i2 100

PROCESSING COMMAND: push s99 Hello

PROCESSING COMMAND: push s99 World

PROCESSING COMMAND: pop i2

Value popped: 100

PROCESSING COMMAND: pop s99

Value popped: World

PROCESSING COMMAND: push s99 planet

PROCESSING COMMAND: pop i2

Value popped: -50

PROCESSING COMMAND: push i2 150




  

  
  
  
  
