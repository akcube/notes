from matplotlib import pyplot as plt
import numpy as np
import seaborn as sns

original = np.loadtxt ('alternating_harmonic.txt')
rearr_less = np.loadtxt ('rearranged_0_3412312.txt')
rearr_more = np.loadtxt ('rearranged_2_8732.txt')
#t = np.arange(0, 1e6, 1)
sns.set_style("whitegrid")
blue, orange, green, red, purple, brown, pink, grey, yellow, cyan = sns.color_palette("muted", 10)

# red dashes, blue squares and green triangles
#plt.plot(t, est, 'r--', t, real, 'b--')
y1 = np.arange(start=0, stop=original.shape[0]);
plt.plot(y1, original, 'b-', color=blue, lw=2, label = "No rearrangements")
#ax = plt.subplot(111)
#ax.fill_between(y1, 0, original, alpha=.3)

y2 = np.arange(start=0, stop=rearr_less.shape[0]);
plt.plot(y2, rearr_less, 'r-', color=red, lw=2, label = "Rearranged to converge to 0.8932...")
#ax2 = plt.subplot(111);
#ax2.fill_between(y1, 0, original, alpha=.3)

y3 = np.arange(start=0, stop=rearr_more.shape[0]);
plt.plot(y3, rearr_more, 'g-', color=green, label = "Rearranged to converge to 0.5512...")

plt.xlabel('n')
plt.ylabel('Partial sum')
plt.title('Graph of sequence of partial sums as n tends to infinity')
# show a legend on the plot
plt.legend()
plt.show()