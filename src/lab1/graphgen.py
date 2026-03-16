import matplotlib.pyplot as plt

threads = list(range(1, 21))
times = [
    125.0, 66.0, 47.0, 37.0, 31.0, 27.0, 24.5, 22.8, 21.5, 20.6, 
    19.9, 19.3, 19.1, 19.2, 19.1, 19.3, 19.2, 19.4, 19.3, 19.5
]

plt.figure(figsize=(10, 6), facecolor='white')

plt.plot(threads, times, marker='o', linestyle='-', color='#125d81', markersize=6, linewidth=1.5)

text_color = '#595959'
plt.title('Czas mnożenia macierzy w zależności od liczby wątków', fontsize=14, fontweight='bold', color=text_color, pad=15)
plt.xlabel('Liczba wątków', fontsize=14, fontweight='bold', color=text_color, labelpad=10)
plt.ylabel('Czas wykonania [s]', fontsize=14, fontweight='bold', color=text_color, labelpad=10)

plt.grid(True, color='#d9d9d9', linestyle='-', linewidth=0.5)
plt.xlim(0, 20.5)
plt.ylim(0, 140)
plt.xticks(range(0, 21, 2))

ax = plt.gca()
for spine in ax.spines.values():
    spine.set_edgecolor('#cccccc')
ax.tick_params(axis='both', colors=text_color, labelsize=10, bottom=False, left=False)

plt.tight_layout()
plt.show()
