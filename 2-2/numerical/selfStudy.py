import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def curveGeneralEqn(x, *coefficients):
    # Assuming coefficients are in the form [a0, a1, a2, ...]
    return sum(a * x**i for i, a in enumerate(coefficients))

# Given x and y values
x_values = np.array([1, 2, 3, 4, 5])  # Replace with your actual x values
y_values = np.array([100, 150, 200, 250, 300])  # Replace with your actual y values

# Use a lambda function to dynamically estimate the size of parameters
params_function = lambda x: np.ones(len(x))

# Use curve_fit to fit the curve with a dynamically estimated initial guess
params, covariance = curve_fit(curveGeneralEqn, x_values, y_values, p0=params_function(x_values))

# Print the fitted parameters
print("Fitted Parameters:")
for i, param in enumerate(params):
    print(f"a{i} = {param}")

# Generate x values for the next 10 years
next_10_years = np.arange(x_values[-1] + 1, x_values[-1] + 11)

# Predict y values for the next 10 years using the fitted model
predicted_population = curveGeneralEqn(next_10_years, *params)

# Plot the original data and the extended curve
plt.scatter(x_values, y_values, label='Original Data')
plt.plot(x_values, curveGeneralEqn(x_values, *params), label='Fitted Curve', color='red')
plt.plot(next_10_years, predicted_population, label='Extended Curve', linestyle='--', color='green')
plt.xlabel('Year')
plt.ylabel('Population')
plt.legend()
plt.show()
