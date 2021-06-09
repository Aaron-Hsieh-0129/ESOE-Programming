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

t_SS_complex_firstname_sch = np.array([[39, 473, 28822, 3.19256e6, 3.59856e8], [22, 400, 27385, 2.71432e6, 2.91682e8], 
								       [23, 346, 29663, 2.99206e6, 3.00498e8], [32, 280, 28524, 2.84871e6, 2.96806e8]])

t_IS_int = np.array([[17, 36, 3054, 162459, 1.73707e7], [17, 17, 53, 149, 1175],
					 [16, 58, 3915, 312440, 3.4378e7], [28, 32, 451, 30674, 3.19244e6]])

t_IS_real = np.array([[19, 49, 1822, 126423, 1.32787e7], [23, 24, 55, 131, 1051], 
					  [24, 44, 2683, 310634, 2.65058e7], [24, 25, 401, 30778, 3.07517e6]])

t_IS_complex_firstname = np.array([[52, 68, 4081, 405407, 3.32375e7], [24, 24, 57, 340, 2102], 
										  [21, 80, 7664, 652074, 6.67964e7], [38, 28, 518, 42380, 3.11602e6]])

t_IS_complex_ID = np.array([[25, 45, 1734, 156201, 1.54527e7], [14, 14, 23, 111, 1139],
							[15, 44, 2455, 264103, 3.35932e7], [38, 28, 518, 42380, 3.11602e6]])

t_IS_complex_firstname_sch = np.array([[30, 284, 19990, 1.90129e6, 2.42986e8], [24, 38, 238, 1166, 6798], 
								       [27, 454, 29204, 3.17222e6, 3.63329e8], [38, 75, 3225, 329503, 3.52122e7]])

t_BS_int = np.array([[18, 72, 5782, 535801, 6.10171e7], [17, 35, 1193, 107270, 9.27655e6], 
					 [19, 136, 8992, 727372, 7.61722e7], [12, 42, 2586, 180253, 1.80812e7]])

t_BS_real = np.array([[12, 67, 4331, 531715, 4.63692e7], [15, 33, 1776, 125942, 1.22772e7], 
					  [17, 95, 6166, 543719, 5.40412e7], [12, 44, 1911, 216123, 1.95889e7]])

t_BS_complex_firstname = np.array([[14, 150, 10893, 1.13653e6, 1.02553e8], [12, 71, 8650, 781515, 6.6411e7], 
								   [17, 138, 11978, 1.18076e6, 1.08782e8], [20, 107, 9759, 835916, 7.730036e7]])

t_BS_complex_ID = np.array([[22, 61, 4468, 442764, 5.45434e7], [12, 21, 909, 83051, 1.37438e7], 
							[12, 78, 6950, 590514, 6.8553e7], [15, 56, 1677, 161558, 2.15969e7]])

t_BS_complex_firstname_sch = np.array([[27, 432, 43109, 4.57632e6, 4.40493e8], [32, 356, 33505, 3.52993e6, 2.97675e8], 
								       [43, 387, 32627, 3.38832e6, 3.58876e8], [33, 407, 34613, 3.21803e6, 3.44655e8]])

t_HS_int = np.array([[27, 97, 1699, 20075, 291515], [33, 106, 2324, 31416, 342507], 
					 [21, 153, 2106, 25792, 309319], [35, 102, 1345, 23191, 249108]])

t_HS_real = np.array([[25, 123, 1278, 19348, 234286], [23, 118, 1410, 20352, 240800], 
					  [20, 95, 1179, 19383, 224586], [22, 154, 1345, 25688, 244492]])

t_HS_complex_firstname = np.array([[24, 108, 1574, 24496, 298772], [36, 208, 2677, 33810, 392693], 
								   [28, 155, 2098, 30987, 267920], [25, 199, 2599, 30855, 269409]])

t_HS_complex_ID = np.array([[32, 142, 1807, 28980, 240889], [28, 156, 2134, 30386, 375888], 
							[31, 146, 1770, 24040, 242120], [20, 154, 1698, 26760, 256647]])

t_HS_complex_firstname_sch = np.array([[31, 183, 2213, 32291, 435843], [26, 163, 4043, 51471, 408593], 
								       [32, 140, 3359, 32832, 588542], [35, 247, 3565, 43498, 585321]])

t_QS_int = np.array([[0, 0, 0, 10000, 50000], [0, 0, 10000, 770000, 5.516e7], 
					 [0, 0, 10000, 550000, 3.552e7], [0, 0, 0, 10000, 50000]])

t_QS_real = np.array([[0, 0, 0, 0, 20000], [0, 0, 10000, 800000, 5.528e7], 
					  [0, 0, 10000, 530000, 3.331e7], [0, 0, 0, 10000, 50000]])

t_QS_complex_firstname = np.array([[0, 0, 0, 10000, 130000], [0, 0, 10000, 1.5e6, 1.3169e8], 
								   [0, 0, 20000, 520000, 3.416e7], [0, 0, 0, 10000, 170000]])

t_QS_complex_ID = np.array([[0, 0, 0, 0, 30000], [0, 0, 20000, 520000, 3.416e7], 
							[0, 0, 10000, 430000, 3.185e7], [0, 0, 0, 0, 60000]])

# constructor
# int
SS_int_random = PlotMethod2D(input_size, t_SS_int[0])
IS_int_random = PlotMethod2D(input_size, t_IS_int[0])
BS_int_random = PlotMethod2D(input_size, t_BS_int[0])
HS_int_random = PlotMethod2D(input_size, t_HS_int[0])
QS_int_random = PlotMethod2D(input_size, t_QS_int[0])

SS_int_increasing = PlotMethod2D(input_size, t_SS_int[1])
IS_int_increasing = PlotMethod2D(input_size, t_IS_int[1])
BS_int_increasing = PlotMethod2D(input_size, t_BS_int[1])
HS_int_increasing = PlotMethod2D(input_size, t_HS_int[1])
QS_int_increasing = PlotMethod2D(input_size, t_QS_int[1])

SS_int_decreasing = PlotMethod2D(input_size, t_SS_int[2])
IS_int_decreasing = PlotMethod2D(input_size, t_IS_int[2])
BS_int_decreasing = PlotMethod2D(input_size, t_BS_int[2])
HS_int_decreasing = PlotMethod2D(input_size, t_HS_int[2])
QS_int_decreasing = PlotMethod2D(input_size, t_QS_int[2])

SS_int_semi = PlotMethod2D(input_size, t_SS_int[3])
IS_int_semi = PlotMethod2D(input_size, t_IS_int[3])
BS_int_semi = PlotMethod2D(input_size, t_BS_int[3])
HS_int_semi = PlotMethod2D(input_size, t_HS_int[3])
QS_int_semi = PlotMethod2D(input_size, t_QS_int[3])

# real
SS_real_random = PlotMethod2D(input_size, t_SS_real[0])
IS_real_random = PlotMethod2D(input_size, t_IS_real[0])
BS_real_random = PlotMethod2D(input_size, t_BS_real[0])
HS_real_random = PlotMethod2D(input_size, t_HS_real[0])
QS_real_random = PlotMethod2D(input_size, t_QS_real[0])

SS_real_increasing = PlotMethod2D(input_size, t_SS_real[1])
IS_real_increasing = PlotMethod2D(input_size, t_IS_real[1])
BS_real_increasing = PlotMethod2D(input_size, t_BS_real[1])
HS_real_increasing = PlotMethod2D(input_size, t_HS_real[1])
QS_real_increasing = PlotMethod2D(input_size, t_QS_real[1])

SS_real_decreasing = PlotMethod2D(input_size, t_SS_real[2])
IS_real_decreasing = PlotMethod2D(input_size, t_IS_real[2])
BS_real_decreasing = PlotMethod2D(input_size, t_BS_real[2])
HS_real_decreasing = PlotMethod2D(input_size, t_HS_real[2])
QS_real_decreasing = PlotMethod2D(input_size, t_QS_real[2])

SS_real_semi = PlotMethod2D(input_size, t_SS_real[3])
IS_real_semi = PlotMethod2D(input_size, t_IS_real[3])
BS_real_smei = PlotMethod2D(input_size, t_BS_real[3])
HS_real_smei = PlotMethod2D(input_size, t_HS_real[3])
QS_real_smei = PlotMethod2D(input_size, t_QS_real[3])

# complex firstname
SS_complex_firstname_random = PlotMethod2D(input_size, t_SS_complex_firstname[0])
IS_complex_firstname_random = PlotMethod2D(input_size, t_IS_complex_firstname[0])
BS_complex_firstname_random = PlotMethod2D(input_size, t_BS_complex_firstname[0])
HS_complex_firstname_random = PlotMethod2D(input_size, t_HS_complex_firstname[0])
QS_complex_firstname_random = PlotMethod2D(input_size, t_QS_complex_firstname[0])

SS_complex_firstname_increasing = PlotMethod2D(input_size, t_SS_complex_firstname[1])
IS_complex_firstname_increasing = PlotMethod2D(input_size, t_IS_complex_firstname[1])
BS_complex_firstname_increasing = PlotMethod2D(input_size, t_BS_complex_firstname[1])
HS_complex_firstname_increasing = PlotMethod2D(input_size, t_HS_complex_firstname[1])
QS_complex_firstname_increasing = PlotMethod2D(input_size, t_QS_complex_firstname[1])

SS_complex_firstname_decreasing = PlotMethod2D(input_size, t_SS_complex_firstname[2])
IS_complex_firstname_decreasing = PlotMethod2D(input_size, t_IS_complex_firstname[2])
BS_complex_firstname_decreasing = PlotMethod2D(input_size, t_BS_complex_firstname[2])
HS_complex_firstname_decreasing = PlotMethod2D(input_size, t_HS_complex_firstname[2])
QS_complex_firstname_decreasing = PlotMethod2D(input_size, t_QS_complex_firstname[2])

SS_complex_firstname_semi = PlotMethod2D(input_size, t_SS_complex_firstname[3])
IS_complex_firstname_semi = PlotMethod2D(input_size, t_IS_complex_firstname[3])
BS_complex_firstname_semi = PlotMethod2D(input_size, t_BS_complex_firstname[3])
HS_complex_firstname_semi = PlotMethod2D(input_size, t_HS_complex_firstname[3])
QS_complex_firstname_semi = PlotMethod2D(input_size, t_QS_complex_firstname[3])


# complex firstname Sch
SS_complex_firstname_random_sch = PlotMethod2D(input_size, t_SS_complex_firstname_sch[0])
IS_complex_firstname_random_sch = PlotMethod2D(input_size, t_IS_complex_firstname_sch[0])
BS_complex_firstname_random_sch = PlotMethod2D(input_size, t_BS_complex_firstname_sch[0])
HS_complex_firstname_random_sch = PlotMethod2D(input_size, t_HS_complex_firstname_sch[0])

SS_complex_firstname_increasing_sch = PlotMethod2D(input_size, t_SS_complex_firstname_sch[1])
IS_complex_firstname_increasing_sch = PlotMethod2D(input_size, t_IS_complex_firstname_sch[1])
BS_complex_firstname_increasing_sch = PlotMethod2D(input_size, t_BS_complex_firstname_sch[1])
HS_complex_firstname_increasing_sch = PlotMethod2D(input_size, t_HS_complex_firstname_sch[1])

SS_complex_firstname_decreasing_sch = PlotMethod2D(input_size, t_SS_complex_firstname_sch[2])
IS_complex_firstname_decreasing_sch = PlotMethod2D(input_size, t_IS_complex_firstname_sch[2])
BS_complex_firstname_decreasing_sch = PlotMethod2D(input_size, t_BS_complex_firstname_sch[2])
HS_complex_firstname_decreasing_sch = PlotMethod2D(input_size, t_HS_complex_firstname_sch[2])

SS_complex_firstname_semi_sch = PlotMethod2D(input_size, t_SS_complex_firstname_sch[3])
IS_complex_firstname_semi_sch = PlotMethod2D(input_size, t_IS_complex_firstname_sch[3])
BS_complex_firstname_semi_sch = PlotMethod2D(input_size, t_BS_complex_firstname_sch[3])
HS_complex_firstname_semi_sch = PlotMethod2D(input_size, t_HS_complex_firstname_sch[3])

# complex ID
SS_complex_ID_random = PlotMethod2D(input_size, t_SS_complex_ID[0])
IS_complex_ID_random = PlotMethod2D(input_size, t_IS_complex_ID[0])
BS_complex_ID_random = PlotMethod2D(input_size, t_BS_complex_ID[0])
HS_complex_ID_random = PlotMethod2D(input_size, t_HS_complex_ID[0])
QS_complex_ID_random = PlotMethod2D(input_size, t_QS_complex_ID[0])

SS_complex_ID_increasing = PlotMethod2D(input_size, t_SS_complex_ID[1])
IS_complex_ID_increasing = PlotMethod2D(input_size, t_IS_complex_ID[1])
BS_complex_ID_increasing = PlotMethod2D(input_size, t_BS_complex_ID[1])
HS_complex_ID_increasing = PlotMethod2D(input_size, t_HS_complex_ID[1])
QS_complex_ID_increasing = PlotMethod2D(input_size, t_QS_complex_ID[1])

SS_complex_ID_decreasing = PlotMethod2D(input_size, t_SS_complex_ID[2])
IS_complex_ID_decreasing = PlotMethod2D(input_size, t_IS_complex_ID[2])
BS_complex_ID_decreasing = PlotMethod2D(input_size, t_BS_complex_ID[2])
HS_complex_ID_decreasing = PlotMethod2D(input_size, t_HS_complex_ID[2])
QS_complex_ID_decreasing = PlotMethod2D(input_size, t_QS_complex_ID[2])

SS_complex_ID_semi = PlotMethod2D(input_size, t_SS_complex_ID[3])
IS_complex_ID_semi = PlotMethod2D(input_size, t_IS_complex_ID[3])
BS_complex_ID_smei = PlotMethod2D(input_size, t_BS_complex_ID[3])
HS_complex_ID_smei = PlotMethod2D(input_size, t_HS_complex_ID[3])
QS_complex_ID_smei = PlotMethod2D(input_size, t_QS_complex_ID[3])



# plot Input Size v.s. Execution Time (random int)
SS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
IS_int_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
HS_int_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
# QS_int_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_random.plot2D(title="Input Size v.s. Execution time (Random Ordered Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  		 show=True, legend=["SS_int", "IS_int", "HS_int", "QS_int", "BS_int"], xscale="log", yscale="log", canvas=False, savename="Input Size v.s. Execution time (Random Ordered Int).png")


# plot Input Order v.s. Execution Time (int)
# SS
SS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
SS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_int_semi.plot2D(title="Input Order v.s. Execution time (Selection Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Selection Sort, Int).png")

# IS
IS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
IS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_int_semi.plot2D(title="Input Order v.s. Execution time (Insertion Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Insertion Sort, Int).png")


# BS
BS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
BS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_int_semi.plot2D(title="Input Order v.s. Execution time (Bubble Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Bubble Sort, Int).png")

# HS
HS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
HS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
HS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
HS_int_semi.plot2D(title="Input Order v.s. Execution time (Heap Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Heap Sort, Int).png")

# QS
# QS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
# QS_int_increasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
# QS_int_decreasing.plot2D(canvas=False, show=False, xscale="log", yscale="log")
# QS_int_semi.plot2D(title="Input Order v.s. Execution time (Quick Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
# 			  	   show=True, legend=["Random", "Increasing", "Decreasing", "Semi"], xscale="log", yscale="log", canvas=False, savename="Input Order v.s. Execution time (Quick Sort, Int).png")


# plot Size of Value Set v.s. Execution Time (random)
# SS
SS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
SS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
SS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Selection Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Selection Sort, Int).png")


# IS
IS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
IS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
IS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Insertion Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Insertion Sort, Int).png")


# BS
BS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
BS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
BS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Bubble Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Bubble Sort, Int).png")


# HS
HS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
HS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
HS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Heap Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Heap Sort, Int).png")


# QS
# QS_int_random.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
# QS_real_random.plot2D(canvas=False, show=False, xscale="log", yscale="log")
# QS_complex_firstname_random.plot2D(title="Size of Value Set v.s. Execution time (Quick Sort, Int)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
# 			  	   show=True, legend=["Int", "real", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", canvas=False, savename="Size of Value Set v.s. Execution time (Quick Sort, Int).png")



# Schwartzian transform
# SS
SS_complex_firstname_random_sch.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
SS_complex_firstname_random.plot2D(title="With Schwarztian Transform v.s. Without Schwarztian Transform (Selection Sort, FirstName)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
									   show=True, legend=["With", "Without", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", 
									   canvas=False, savename="With Schwarztian Transform v.s. Without Schwarztian Transform (Selection Sort, FirstName).png")


IS_complex_firstname_random_sch.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
IS_complex_firstname_random.plot2D(title="With Schwarztian Transform v.s. Without Schwarztian Transform (Insertion Sort, FirstName)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
									   show=True, legend=["With", "Without", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", 
									   canvas=False, savename="With Schwarztian Transform v.s. Without Schwarztian Transform (Insertion Sort, FirstName).png")

BS_complex_firstname_random_sch.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
BS_complex_firstname_random.plot2D(title="With Schwarztian Transform v.s. Without Schwarztian Transform (Bubble Sort, FirstName)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
									   show=True, legend=["With", "Without", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", 
									   canvas=False, savename="With Schwarztian Transform v.s. Without Schwarztian Transform (Bubble Sort, FirstName).png")

BS_complex_firstname_random_sch.plot2D(show=False, xscale="log", yscale="log", figsize=(10, 8))
BS_complex_firstname_random.plot2D(title="With Schwarztian Transform v.s. Without Schwarztian Transform (Heap Sort, FirstName)", xlabel="Size (log scale)", ylabel="Time [$\mu$s] (log scale)", 
									   show=True, legend=["With", "Without", "self-defined (including 4 attributes)\n [sorted by string]"], xscale="log", yscale="log", 
									   canvas=False, savename="With Schwarztian Transform v.s. Without Schwarztian Transform (Heap Sort, FirstName).png")



