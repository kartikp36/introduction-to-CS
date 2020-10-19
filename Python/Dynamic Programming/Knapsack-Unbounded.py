# Function to return the maximum required value 
def knapSack(W, wt, val): 

	# maxratio will store the maximum value to weight 
	# ratio we can have for any item and 
	# maxindex will store the index of that element 
	n = len(val)
	maxratio = float('-inf')
	maxindex = 0 
	for i in range(n): 
		if ((val[i] / wt[i]) > maxratio): 
			maxratio = (val[i] / wt[i]) 
			maxindex = i 


	# The item with the maximum value to 
	# weight ratio will be put into 
	# the knapsack repeatedly until full 
	return (W * maxratio) 

val = [ 14, 27, 44, 19 ] 
wt = [ 6, 7, 9, 8 ] 
W = 50

print(knapSack(W, wt, val)) 
