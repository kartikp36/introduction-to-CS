.data
prompt:	.asciiz "Enter Size: \n"
enter_num:.asciiz "Enter num: \n"
size:	.word 0
the_list:.word 0
i:	.word 0
prod:	.word 0

	.text
	# i = 0, product = 1
	sw $0, i
	li $t0,1
	sw $t0,prod
	#print prompt
	la $a0,prompt
	li $v0,4
	syscall
	#input size
	li $v0,5
	syscall
	sw $v0,size
	#allocate memory
	lw $t0,size
	mul $t0,$t0,4
	add $t0,$t0,4
	
	add $a0,$t0,$0
	li $v0,9
	syscall
	sw $v0,the_list
	sw $t1,($v0)
	
	#putting values to list
	sw $0, i
loop:	lw $t2, i
	lw $t3, size
	bge $t2,$t3,endloop
	
	lw $t4, the_list
	mul $t5,$t2,4
	add $t5,$t5,4
	add $t5, $t5, $t4

	#print enter_num
	la $a0,enter_num
	li $v0,4
	syscall
	
	li $v0,5
	syscall
	sw $v0,($t5)
	#skip if even
	lw $t5,($t5)
	rem $t6,$t5,2
	beq $t6, $0, skip
	# product *= list[i]
	lw $t2, prod
	mul $t9,$t5,$t2
	sw $t9,prod
	
skip: # i += 1
	lw $t2, i
	addi $t2, $t2, 1
	sw $t2, i
	j loop
endloop:# print Product
	addi $v0, $0, 1
	lw $a0, prod
	syscall
	li $v0, 10
	syscall
	
