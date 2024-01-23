def knapSack(W, wt, val, n):
    dp = [[0 for w in range(W+1)] for i in range(n+1)]
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif wt[i-1] <= w:
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]

    res = dp[n][W]
    print("Total value in Knapsack =", res)

    w = W
    selected_items = [0]*n
    for i in range(n, 0, -1):
        if res <= 0:
            break
        if res == dp[i - 1][w]:
            continue
        else:
            selected_items[i-1] = 1
            res = res - val[i - 1]
            w = w - wt[i - 1]

    print("Items: \t\t", *range(1, n+1))
    print("Weights: \t", *wt)
    print("Profits: \t", *val)
    print("Selected: \t", *selected_items)


if __name__ == '__main__':
    profit = [4, 3, 6, 5]
    weight = [3, 2, 5, 4]
    W = 5
    n = len(profit)
    knapSack(W, weight, profit, n)
