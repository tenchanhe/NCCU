import matplotlib.pyplot as plt
import numpy as np
import time
import Box2D

# create the world
gravity = Box2D.b2Vec2(0, -10)  # define gravity
world = Box2D.b2World(gravity)

# create the ground
ground = world.CreateBody(position=(0, 0))
ground.CreateEdgeFixture(vertices=[(-10, 0), (10, 0)], density=0, friction=0.1)

# create the ball
body = world.CreateDynamicBody(position=(0, 10), angle=0)
shape = Box2D.b2CircleShape(radius=0.1)
fixture = body.CreateFixture(shape=shape, density=1, friction=0.1)

# set up the plot
fig, ax = plt.subplots()
ax.axis('off')
ax.set_aspect('equal')
ax.set_xlim(-10, 10)
ax.set_ylim(-10, 10)

# create the ground line
ground_line = plt.Line2D((-10, 10), (0, 0), linewidth=2)
ax.add_artist(ground_line)

# create the ball
circle = plt.Circle((0, 10), radius=1.0, fill=False)
ax.add_artist(circle)

# simulate the world and update the plot
timestep = 1 / 60  # time between updates
n_steps = 1000  # number of updates
for i in range(n_steps):
	world.Step(timestep, 6, 2)
	x, y = body.position
	circle.set_center((x, y))
	fig.canvas.draw()
	plt.pause(0.01)

plt.show()
