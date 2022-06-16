import networkx as nx
import matplotlib.pyplot as plt

d = {}
color = []
f = open('node300.txt')
for idx, line in enumerate(f.readlines()):
    x, y, z = line.strip("\n").split()
    x = float(x)
    y = float(y)
    d[idx] = (x, y)
    if z == 'country':
        color.append('blue')
    else:
        color.append('yellow')
f.close()

g = open('edge300.txt')
e = []
for line in g.readlines():
    x,y = line.strip("\n").split()
    x = int(x)
    y = int(y)
    e.append((x,y))
g.close()

G1 = nx.Graph()
G1.add_nodes_from(d.keys())
G1.add_edges_from(e)
plt.figure(figsize=(9,15))
nx.draw(G1,d,node_color=color,with_labels=True)
plt.show()
