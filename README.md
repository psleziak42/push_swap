# push_swap

Official description:
"_This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting._"

Given instructions:
<br>sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
<br>sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
<br>pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
<br>pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
<br>ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
<br>rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
<br>rr : ra and rb at the same time.
<br>rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
<br>rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
<br>rrr : rra and rrb at the same time

Methodology:
The main part of this project was use of _linked list_.
