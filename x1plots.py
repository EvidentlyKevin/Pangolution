import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read the CSV file
data = pd.read_csv('pangolin_data.csv')

# Plotting
plt.figure(figsize=(10, 6))

for region in range(1, 5):
    region_data = data[data['Region'] == region]
    # Plot the original data with transparency
    plt.plot(region_data['Generation'], region_data['PopulationSize'], label=f'Region {region}', alpha=0.5)

    # Calculate and plot the line of best fit
    # z = np.polyfit(region_data['Generation'], region_data['PopulationSize'], 1)
    # p = np.poly1d(z)
    # plt.plot(region_data['Generation'], p(region_data['Generation']), linewidth=3)

plt.xlabel('Generation #')
plt.ylabel('Population Size')
plt.title('Population Growth by Region')
plt.legend()
plt.grid(True)
# plt.yscale('log')
# plt.xscale('log')
plt.show()
