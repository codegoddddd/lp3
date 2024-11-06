# Implement  Gradient  Descent  Algorithm  to  find  the  local  minima  of  a 
# function.  For  example,  find  the  local  minima  of  the  function  y=(x+3)²  starting  from  the 
# point x=2.

# Define the function y=(x+3)^2
def function(x):
    return (x + 3)**2

# Calculate the derivative of the function
def derivative(x):
    return 2 * (x + 3)

# Initialize starting point and learning rate
x = 2
alpha = 0.1

# Set convergence criteria
iterations = 1000
tolerance = 1e-6

# Gradient Descent Algorithm
for i in range(iterations):
    gradient = derivative(x)
    new_x = x - alpha * gradient
    
    if abs(new_x - x) < tolerance:
        break
    
    x = new_x

# Print the local minima
print("Local minima at x =", x)
print("Minimum value of the function y =", function(x))
