# Evaluate-Earning-Report-Impacts
This project is a final team project in Financial Computing in NYU Tandon.
![](Evaluate-Earning-Report-Impacts/Picture1.png)

In this program, we:
1. Use liburl to retrieve historical price data for selected S&P 500 stocks and SPY 30 days before report releasing to 60 days after report releasing from Yahoo Finance and store into memory.
2. Divide all stocks into 3 groups - 'beat', 'meet' and 'miss' - by their eps performace
3. Calculate AAR(Average Abnormal Return) and CAAR(Cumulative AAR) for each group using bootstrapping
4. Use Excel Driver to show the CAAR from all 3 groups in one graph
5. Analysis CAAR behaviour after reports releasing.


