# COMSC210
# Description: Lab1: Add Two Integers
# Language: ASM
# Date: 1/28/2023 
# Location: RWU
# Author: Joshua Farias

.data

message:	.asciiz "Adding Two Integers"

.text

la $a0, message # load address of message into $a0
li $v0, 4 # load 4 into $v0 for syscall(4) Print String
syscall

li $t1, 3 # load the integer 3 into register $t1
li $t2, 4 # load the integer 4 into register $t2

add $t1,$t2,$t1 # add the two integers and store the result in $t1
