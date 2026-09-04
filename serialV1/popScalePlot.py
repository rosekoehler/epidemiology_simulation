import re
import sys
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    print(f"Usage: {sys.argv[0]} <.out file>")
    sys.exit(1)

filename = sys.argv[1]
lines = open(filename).readlines()

sizes = []
times = []
current_size = None

for line in lines:
    line = line.strip()

    m = re.search(r"test (\d+)", line)
    if m:
        current_size = int(m.group(1))

    m = re.search(r"real\s+(\d+)m([\d.]+)s", line)
    if m:
        minutes = int(m.group(1))
        seconds = float(m.group(2))
        sizes.append(current_size)
        times.append(minutes * 60 + seconds)

plt.plot(sizes, times, marker='o')
plt.xlabel('Array size')
plt.ylabel('Real time (s)')
plt.title('Array Size vs Real Time')
plt.savefig("popScale_plot.png")
print("Saved poopScale_plot.png")
