import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import math

def NewtonInterpolation(years, population, target_year):        # forward method
    delta = []
    delta.append(population)
    for i in range(len(population)-1):
        delta.append([])
        for j in range(len(population)-i-1):
            delta[i+1].append(delta[i][j+1] - delta[i][j])
    # print the delta table
    # print("Delta table:")
    # for i in range(len(delta)):
    #     print(delta[i])

    '''
    we know,
        X = X0 + p * h
        p = (x - X0) / h
    '''
    p = (target_year - years[0]) / (years[1] - years[0])

    '''
    Yn(X) = Y0 + p * delta1 + p * (p-1) * delta2 / 2! + p * (p-1) * (p-2) * delta3 / 3! + ...
    '''

    target_population = population[0]
    static_p = p
    for i in range(1, len(delta)):
        target_population += p * delta[i][0] / math.factorial(i)    # forward method, so delta[i][0]
        p *= (static_p-i)

    return target_population

def raphson_func(x):
    function = x**3 - 2*x - 5
    derivative = 3*x**2 - 2
    return [function, derivative]

def newton_raphson(population, accuracy = 0.0001):
    Xn = population - raphson_func(population)[0] / raphson_func(population)[1]
    while abs(Xn - population) > accuracy:
        population = Xn
        if (raphson_func(population)[1] == 0):
            print("Error! - derivative zero for x = ", population)
            return None
        Xn = population - raphson_func(population)[0] / raphson_func(population)[1]
    return Xn



# def func(x, m, c):
#     return m*x + c

# def curve_fitting(years, population, target_year):      # straight line method
#     popt, _ = curve_fit(func, years, population)
#     predicted_population = func(target_year, *popt)
#     return predicted_population



def curve_fitting(years, population, target_year):      # straight line method
    n = len(years)
    sum_x = sum(years)
    sum_y = sum(population)
    sum_x_squared = sum([i**2 for i in years])
    sum_xy = sum([years[i]*population[i] for i in range(n)])

    m = (n*sum_xy - sum_x*sum_y) / (n*sum_x_squared - sum_x**2)
    c = (sum_y - m*sum_x) / n

    predicted_population = m*target_year + c
    return predicted_population

if __name__ == "__main__":
    data = pd.read_csv('c:\\Users\\mjmeh\\Documents\\Github\\LAB\\2-2\\numerical\\data.csv')

    years = data[data.columns[0]].tolist()
    population = data[data.columns[1]].tolist()

    last_year = int(data.iloc[-1, 0])

    # Next 10 years for prediction
    target_year_values = [last_year + i for i in range(1, 11)]

    # Calculate populations for Newton Interpolation and Curve Fitting
    target_population_newton = [NewtonInterpolation(years, population, year) for year in target_year_values]
    target_population_newton_raphson = [newton_raphson(pop) for pop in target_population_newton]
    target_population_curve_fit = [curve_fitting(years, population, year) for year in target_year_values]

    print("\nNewton Interpolation: ")
    for year, pop in zip(target_year_values, target_population_newton):     # makes a dictionary
        print("Population in", year, "(N.InterPol): ", pop)

    print("\nNewton Raphson: ")
    for year, pop in zip(target_year_values, target_population_newton_raphson):
        print("Population in", year, "(N.Raphson): ", pop)

    print("\nCurve Fitting: ")
    for year, pop in zip(target_year_values, target_population_curve_fit):
        print("Population in", year, "(CurveFit): ", pop)


    plt.rcParams.update({
        'lines.linewidth': 2,
        'lines.markersize': 5
    })

    plt.plot(target_year_values, target_population_newton, 'ro-', label='N.Interpolation')
    plt.plot(target_year_values, target_population_newton_raphson, 'go-', label='N.Raphson')
    plt.plot(target_year_values, target_population_curve_fit, 'bo-', label='Curve Fitting')

    plt.xlabel('Year')
    plt.ylabel('Population')
    plt.title('Population vs Year')
    plt.legend()
    plt.show()