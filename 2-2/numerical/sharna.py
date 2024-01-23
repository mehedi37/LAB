def differenceTable(population):
    # make a 2d array
    # take difference
    r = []
    r.append(population)
    print(r)
    for i in range (1, len(population)):
        r_temp =[]
        for j in range (0, len(population)-i):
            delta = r[i-1][j+1] - r[i-1][j]
            r_temp.append(delta)
        r.append(r_temp)
        print(r)

    pass



def f_x(x):
    return x    # your eqn here
years = []
population = [123700000, 135255000,141162000,158297000,168912500]
differenceTable(population)