def factorial(n):
  """Calculates the factorial of a given number.

  Args:
    n: The number to calculate the factorial of.

  Returns:
    The factorial of the number.
  """

  if n == 0:
    return 1
  else:
    return n * factorial(n-1)

# Example usage:
factorial_result = factorial(5)
print(factorial_result)  # Output: 120
