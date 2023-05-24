# Programowanie i metody numeryczne
#
# Program generujący wykresy na podstawie danych zwracanych przez programy
# rozwiązujące równanie oscylatora harmonicznego.



import sys
import matplotlib.pyplot as plt


# Przygotowujemy niezbędne zmienne.

title = ""
res_t = []
res_x = []
res_v = []
res_exact = []
res_diff = []


# Odczytujemy dane z pliku, którego nazwa została podana jako argument wywołania programu.

filename = sys.argv[1]

with open(filename, encoding = "utf-8") as datafile:
    title = datafile.readline()
    
    for line in datafile:
        data = line.split()
        res_t.append(float(data[0]))
        res_x.append(float(data[1]))
        res_v.append(float(data[2]))
        res_exact.append(float(data[3]))
        res_diff.append(float(data[3]) - float(data[1]))


# Rysyjemy wyniki symylacji.

fig = plt.figure(constrained_layout = True)

fig.suptitle(title, fontsize = "xx-large")

subfigs = fig.subfigures(1, 2, wspace = 0.07)

subfigs[1].suptitle("Diagram fazowy na podstawie rozwiązania numerycznego")

axs = subfigs[0].subplots(2)
axs[0].plot(res_t, res_x, 'r-', label = "Rozwiązanie numeryczne")
axs[0].plot(res_t, res_exact, 'b-', label = "Rozwiązanie analityczne")
axs[0].set_title("Rozwiązania: analityczne (niebieski) i numeryczne (czerwony)")
axs[0].grid()

axs[1].plot(res_t, res_diff, 'g-')
axs[1].set_title("Różnica pomiędzy rozwiązaniem analitycznym a numerycznym")
axs[1].grid()

for ax in axs.flat:
    ax.set(xlabel = "$t$", ylabel = "$x$")

for ax in axs.flat:
    ax.label_outer()
    
axr = subfigs[1].subplots()
axr.plot(res_x, res_v)
axr.grid()
axr.set(xlabel = "$x$", ylabel = "$v$")

plt.show()