This project has been created as part of the 42 curriculum.
use make to generate an executable, the executable takes in one or multiple parameters of unsorted numbers ex: "1 3 2" or 1 3 2, returns ERROR on stderr if different type is passed or id there are duplicates.
the programe sorts given numbers as if they are stacked one on top of the other where we can only use the one on top and the one on bottom for operations.
we have two stacks one empty in the begining and the other filled with the input.
we use the operation below to sort the first stack.

sa (swap a): Swap the first 2 elements at the top of stack a.

sb (swap b): Swap the first 2 elements at the top of stack b.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

pb (push b): Take the first element at the top of a and put it at the top of b.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.

the istructions will be printed each time the programe makes a move.
