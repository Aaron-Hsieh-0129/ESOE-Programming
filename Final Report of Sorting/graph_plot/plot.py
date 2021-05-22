import numpy as np
import matplotlib.pyplot as plt


class PlotMethod2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def plot2D(self, title=None, xlabel=None, ylabel=None, xticks=None, yticks=None, xlim=None, ylim=None,
               fontsize=12, savename=None, grid=True, figsize=None, legend=None, xscale="linear", yscale="linear", show=True, canvas=True):
        plt.figure(figsize=figsize) if canvas else 0
        plt.plot(self.x, self.y)
        plt.grid(grid)
        plt.title(title, fontsize=fontsize) if title is not None else 0
        plt.xlabel(xlabel) if xlabel is not None else 0
        plt.ylabel(ylabel) if ylabel is not None else 0
        plt.xlim(xlim) if xlim is not None else 0
        plt.ylim(ylim) if ylim is not None else 0
        plt.xticks(xticks[0], xticks[1]) if xticks is not None else 0
        plt.yticks(yticks[0], yticks[1]) if yticks is not None else 0
        plt.xscale(xscale)
        plt.yscale(yscale)
        plt.legend(legend) if legend is not None else 0
        plt.savefig(savename) if savename is not None else 0
        plt.show() if show else 0


input_size = np.array([10, 100, 1000, 10000, 1000000])
# data (random, increasing, decreasing, semi)
t_SS_int = np.array([[21, 39, 1321, 144261, 1.29948e7], [12, 26, 1514, 126814, 1.33068e7], 
					 [18, 39, 1828, 150814, 1.2135e7], [12, 28, 2530, 119872, 1.22951e7]])

t_SS_real = np.array([[11, 32, 1824, 131235, 1.30521e7], [14, 36, 1343, 114141, 1.21141e7], 
					  [14, 31, 1327, 114411, 1.27306e7], [13, 35, 2164, 122168, 1.29052e7]])

t_SS_complex_firstname = np.array([[34, 81, 6420, 547907, 5.20697e7], [18, 75, 6142, 447060, 4.60558e7], 
								   [40, 71, 5954, 703238, 5.89773e7], [20, 68, 5747, 405521, 4.7578e7]])

t_SS_complex_ID = np.array([[13, 31, 1327, 106553, 1.60433e7], [13, 23, 1150, 137457, 1.41425e7], 
							[9, 21, 882, 108421, 1.41116e7], [12, 28, 1019, 115381, 1.62056e7]])

t_IS_int = np.array([[17, 36, 3054, 162459, 1.73707e7], [17, 17, 53, 149, 1175],
					 [16, 58, 3915, 312440, 3.4378e7], [28, 32, 451, 30674, 3.19244e6]])

t_IS_real = np.array([[19, 49, 1822, 126423, 1.32787e7], [23, 24, 55, 131, 1051], 
					  [24, 44, 2683, 310634, 2.65058e7], [24, 25, 401, 30778, 3.07517e6]])

t_IS_complex_firstname = np.array([[52, 68, 4081, 405407, 3.32375e7], [24, 24, 57, 340, 2102], 
										  [21, 80, 7664, 652074, 6.67964e7], [38, 28, 518, 42380, 3.11602e6]])

t_IS_complex_ID = np.array([[25, 45, 1734, 156201, 1.54527e7], [14, 14, 23, 111, 1139],
							[15, 44, 2455, 264103, 3.35932e7], [38, 28, 518, 42380, 3.11602e6]])

t_BS_int = np.array([[18, 72, 5782, 535801, 6.10171e7], [17, 35, 1193, 107270, 9.27655e6], 
					 [19, 136, 8992, 727372, 7.61722e7], [12, 42, 2586, 180253, 1.80812e7]])

t_BS_real = np.array([[12, 67, 4331, 531715, 4.63692e7], [15, 33, 1776, 125942, 1.22772e7], 
					  [17, 95, 6166, 543719, 5.40412e7], [12, 44, 1911, 216123, 1.95889e7]])

t_BS_complex_firstname = np.array([[14, 150, 10893, 1.13653e6, 1.02553e8], [12, 71, 8650, 781515, 6.6411e7], 
								   [17, 138, 11978, 1.18076e6, 1.08782e8], [20, 107, 9759, 835916, 7.730036e7]])

t_BS_complex_ID = np.array([[22, 61, 4468, 442764, 5.45434e7], [12, 21, 909, 83051, 1.37438e7], 
							[12, 78, 6950, 590514, 6.8553e7], [15, 56, 1677, 161558, 2.15969e7]])



# constructor
# int
SS_int_random = PlotMethod2D(input_size, t_SS_int[0])
IS_int_random = PlotMethod2D(input_size, t_IS_int[0])
BS_int_random = PlotMethod2D(input_size, t_BS_int[0])

SS_int_increasing = PlotMethod2D(input_size, t_SS_int[1])
IS_int_increasing = PlotMethod2D(input_size, t_IS_int[1])
BS_int_increasing = PlotMethod2D(input_size, t_BS_int[1])

SS_int_decreasing = PlotMethod2D(input_size, t_SS_int[2])
IS_int_decreasing = PlotMethod2D(input_size, t_IS_int[2])
BS_int_decreasing = PlotMethod2D(input_size, t_BS_int[2])

SS_int_semi = PlotMethod2D(input_size, t_SS_int[3])
IS_int_semi = PlotMethod2D(input_size, t_IS_int[3])
BS_int_semi = PlotMethod2D(input_size, t_BS_int[3])

# real
SS_real_random = PlotMethod2D(input_size, t_SS_real[0])
IS_real_random = PlotMethod2D(input_size, t_IS_real[0])
BS_real_random = PlotMethod2D(input_size, t_BS_real[0])

SS_real_increasing = PlotMethod2D(input_size, t_SS_real[1])
IS_real_increasing = PlotMethod2D(input_size, t_IS_real[1])
BS_real_increasing = PlotMethod2D(input_size, t_BS_real[1])

SS_real_decreasing = PlotMethod2D(input_size, t_SS_real[2])
IS_real_decreasing = PlotMethod2D(input_size, t_IS_real[2])
BS_real_decreasing = PlotMethod2D(input_size, t_BS_real[2])

SS_real_semi = PlotMethod2D(input_size, t_SS_real[3])
IS_real_semi = PlotMethod2D(input_size, t_IS_real[3])
BS_real_smei = PlotMethod2D(input_size, t_BS_real[3])

# complex firstname
SS_complex_firstname_random = PlotMethod2D(input_size, t_SS_complex_firstname[0])
IS_complex_firstname_random = PlotMethod2D(input_size, t_IS_complex_firstname[0])
BS_complex_firstname_random = PlotMethod2D(input_size, t_BS_complex_firstname[0])

SS_complex_firstname_increasing = PlotMethod2D(input_size, t_SS_complex_firstname[1])
IS_complex_firstname_increasing = PlotMethod2D(input_size, t_IS_complex_firstname[1])
BS_complex_firstname_increasing = PlotMethod2D(input_size, t_BS_complex_firstname[1])

SS_complex_firstname_decreasing = PlotMethod2D(input_size, t_SS_complex_firstname[2])
IS_complex_firstname_decreasing = PlotMethod2D(input_size, t_IS_complex_firstname[2])
BS_complex_firstname_decreasing = PlotMethod2D(input_size, t_BS_complex_firstname[2])

SS_complex_firstname_semi = PlotMethod2D(input_size, t_SS_complex_firstname[3])
IS_complex_firstname_semi = PlotMethod2D(input_size, t_IS_complex_firstname[3])
BS_complex_firstname_smei = PlotMethod2D(input_size, t_BS_complex_firstname[3])


# complex ID
SS_complex_ID_random = PlotMethod2D(input_size, t_SS_complex_ID[0])
IS_complex_ID_random = PlotMethod2D(input_size, t_IS_complex_ID[0])
BS_complex_ID_random = PlotMethod2D(input_size, t_BS_complex_ID[0])

SS_complex_ID_increasing = PlotMethod2D(input_size, t_SS_complex_ID[1])
IS_complex_ID_increasing = PlotMethod2D(input_size, t_IS_complex_ID[1])
BS_complex_ID_increasing = PlotMethod2D(input_size, t_BS_complex_ID[1])

SS_complex_ID_decreasing = PlotMethod2D(input_size, t_SS_complex_ID[2])
IS_complex_ID_decreasing = PlotMethod2D(input_size, t_IS_complex_ID[2])
BS_complex_ID_decreasing = PlotMethod2D(input_size, t_BS_complex_ID[2])

SS_complex_ID_semi = PlotMethod2D(input_size, t_SS_complex_ID[3])
IS_complex_ID_semi = PlotMethod2D(input_size, t_IS_complex_ID[3])
BS_complex_ID_smei = PlotMethod2D(input_size, t_BS_complex_ID[3])



# plot Input Size v.s. Execution Time (random int)
SS_int_random.plot2D(show=False, xscale="log", yscale="log")
IS_int_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_random.plot2D(title="Input Size v.s. Execution time (Random Ordered Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  		 show=True, legend=["SS_int", "IS_int", "BS_int"], xscale="log", yscale="log", canvas=False, savename="Input Size v.s. Execution time (Random Ordered Int).png")


# plot Input Order v.s. Execution Time (int)
# SS
SS_int_random.plot2D(show=False, xscale="log", yscale="log")
SS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_int_semi.plot2D(title="Input Order v.s. Execution time (Selection Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Selection Sort, Int).png")

# IS
IS_int_random.plot2D(show=False, xscale="log", yscale="log")
IS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_int_semi.plot2D(title="Input Order v.s. Execution time (Insertion Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Insertion Sort, Int).png")


# BS
BS_int_random.plot2D(show=False, xscale="log", yscale="log")
BS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_semi.plot2D(title="Input Order v.s. Execution time (Bubble Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Bubble Sort, Int).png")


# plot Size of Value Set v.s. Execution Time (random)
# SS
SS_int_random.plot2D(show=False, xscale="log", yscale="log")
SS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Selection Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Selection Sort, Int).png")


# IS
IS_int_random.plot2D(show=False, xscale="log", yscale="log")
IS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Insertion Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Insertion Sort, Int).png")


# BS
BS_int_random.plot2D(show=False, xscale="log", yscale="log")
BS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Bubble Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Bubble Sort, Int).png")















