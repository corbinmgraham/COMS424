# import numpy as np
# import matplotlib.pyplot as plt
# from numpy.polynomial import chebyshev

# # Define the range of x values
# x = np.linspace(-1, 1, 400)

# # Define the degree of Chebyshev polynomials to be plotted
# degree = 5

# # Generate and plot Chebyshev polynomials
# for i in range(degree + 1):
#     T_i = chebyshev.chebval(x, [0] * i + [1])  # Coefficients for T_i
#     plt.plot(x, T_i, label=f'T_{i}(x)')

# # Set plot labels and legend
# plt.xlabel('x')
# plt.ylabel('T_i(x)')
# plt.title(f'Chebyshev Polynomials of the First Kind (Degree {degree})')
# plt.legend(loc='upper left')

# # Show the plot
# plt.grid(True)
# plt.axhline(0, color='black', linewidth=0.5)
# plt.axvline(0, color='black', linewidth=0.5)
# plt.show()

# // int main() {
# // 	// create a new list
# // 	List* int_list = create_list();
	
# // 	// add some integers to the list
# // 	int x = 42;
# // 	add_to_list(int_list, (void*)&x);
# // 	int y = 13;
# // 	add_to_list(int_list, (void*)&y);
# // 	int z = 99;
# // 	add_to_list(int_list, (void*)&z);
	
# // 	// remove the integers from the list and print them
# // 	int* int_ptr = NULL;
# // 	while ((int_ptr = (int*)remove_from_list(int_list)) != NULL) {
# // 		printf("%d\n", *int_ptr);
# // 	}
	
# // 	// free the memory used by the list
# // 	free_list(int_list);
	
# // 	return 0;
# // }

import numpy as np
import matplotlib.pyplot as plt

# Define the Legendre polynomial (for a specific degree n)
def legendre_polynomial(x, n):
    return np.polynomial.legendre.Legendre.basis(n)(x)

# Define the range of x values
x = np.array([-1, 1, -0.5, 0.5, -0.25])  # Adjust the range as needed

# Compute and plot the Legendre series (sum of Legendre polynomials up to a degree)
degree = 5  # Example: Sum up to degree 5
legendre_series = np.zeros_like(x)

for n in range(degree + 1):
    legendre_series += legendre_polynomial(x, n)

# Display the Legendre series
plt.scatter(x, legendre_series, label=f'Legendre Series (Degree {degree})')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Legendre Series')
plt.legend()
plt.grid(True)
plt.show()
