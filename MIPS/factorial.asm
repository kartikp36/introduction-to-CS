	.data
prompt:	.asciiz "Enter n: \n"
res_is:	.asciiz "Result is  "
n:	.word 0
result:	.word 0
i:	.word 0

	.text
main:	
	# 2 * 4 = 8 bytes local
 	addi $fp, $sp, 0
	addi $sp, $sp, -8
	
	#print prompt
	la $a0,prompt
	li $v0,4
	syscall
	
	# Initialize locals
	sw $0, -8($fp)
	sw $0, -4($fp)#result
	li $v0, 5
	syscall
	sw $v0, -8($fp) # n
	
	#push 4 bytes $sp
	addi $sp,$sp,-4
	# arg 1 = n
	lw $t0, -8($fp) # n
	addi $t0,$t0,1
	sw $t0, 0($sp) # arg 1
	jal factorial
	#remove args
	addi $sp, $sp, 4
	
	# Store return value in result.
	sw $v0, -4($fp) # result

	#print res_is
	la $a0, res_is
	li $v0,	4
	syscall
	# print Product
	addi $v0, $0, 1
	lw $a0, -4($fp)
	syscall
	li $v0, 10
	syscall
	
factorial:#Save $ra and $fp
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $fp, 0($sp)
	# Copy $sp to $fp
	addi $fp, $sp, 0
	
	# Allocate local variables
	# 2* 4 = 8 bytes.
	addi $sp, $sp, -8
	# Initialize locals.
	addi $t0, $0, 1
	sw $t0, -4($fp) # result
	li $t0,1
	sw $t0,-8($fp)#i-counter

loop:# Stop if !(e > 0)
	lw $t0, -8($fp)#i
	lw $t1, 8($fp)
	beq $t0, $t1, end
	
	# fac *= num
	lw $t2, -4($fp)
	lw $t0,-8($fp)
	mul $t5,$t0,$t2
	sw $t5, -4($fp)
	#increment i
	lw $t0, -8($fp)
	addi $t0, $t0, 1
	sw $t0, -8($fp)
	j loop
end:	# Return result in $v0
	lw $v0, -4($fp) # result
	#remove locals
	addi $sp, $sp, 8
	# Restore $fp and $ra
	lw $fp, 0($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	# Return to caller.
	jr $ra
	