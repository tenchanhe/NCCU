#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
An attempt at some simple, self-contained pygame-based examples.

Example 01

In short:
One static body: a big polygon to represent the ground
One dynamic body: a rotated big polygon
And some drawing code to get you going.

kne
"""
import pygame
from pygame.locals import (QUIT, KEYDOWN, K_ESCAPE)

import Box2D  # The main library
# Box2D.b2 maps Box2D.b2Vec2 to vec2 (and so on)
from Box2D.b2 import (world, polygonShape, staticBody, dynamicBody)
import numpy as np
import copy
import math
from math import sin, cos
def expand_rectangle(vertices, n):
	expanded_vertices = []
	for i in range(len(vertices)):
		current_vertex = vertices[i]
		next_vertex = vertices[(i + 1) % len(vertices)]

		delta_x = (next_vertex[0] - current_vertex[0]) / n
		delta_y = (next_vertex[1] - current_vertex[1]) / n

		for j in range(n):
			x = current_vertex[0] + j * delta_x
			y = current_vertex[1] + j * delta_y
			expanded_vertices.append((x, y))
	return expanded_vertices

def effect_on(x, y, A, Q, t, m):
	print(x, y)
	if y > k:
		y = 1.2 * k
	if x > k:
		x = 1.2 * k
	new_A = np.array([[1.0, 0.0], 
               		  [0.0, 1.0]])  
	new_Q = np.array([[0.0, 0.0], 
					  [0.0, 0.0]])
	new_t = np.array([[0.0], 
					  [0.0]])
	new_m = np.array([[0.0], 
					  [0.0]])  
	new_A[0][0] = new_A[0][0] + (A[0][0] - new_A[0][0]) * x / k
	new_A[0][1] = new_A[0][1] + (A[0][1] - new_A[0][1]) * x / k
	new_A[1][0] = new_A[1][0] + (A[1][0] - new_A[1][0]) * y / k
	new_A[1][1] = new_A[1][1] + (A[1][1] - new_A[1][1]) * y / k
	new_Q[0][0] = new_Q[0][0] + (Q[0][0] - new_Q[0][0]) * y / k
	new_Q[0][1] = new_Q[0][1] + (Q[0][1] - new_Q[0][1]) * x / k
	new_Q[1][0] = new_Q[1][0] + (Q[1][0] - new_Q[1][0]) * y / k
	new_Q[1][1] = new_Q[1][1] + (Q[1][1] - new_Q[1][1]) * y / k
	new_m[0][0] = new_m[0][0] + (m[0][0] - new_m[0][0]) * x / k
	new_m[1][0] = new_m[1][0] + (m[1][0] - new_m[1][0]) * y / k
	new_t[0][0] = new_t[0][0] + (t[0][0] - new_t[0][0]) * y / k
	new_t[1][0] = new_t[1][0] + (t[1][0] - new_t[1][0]) * x / k
	return (new_A, new_Q, new_t, new_m)
def get_speed(body, x, y):
	now_speed_x = body.linearVelocity.x
	speed_dis_x = math.sqrt(abs(now_speed_x**2 - x**2))
	now_speed_y = body.linearVelocity.y
	speed_dis_y = math.sqrt(abs(now_speed_y**2 - y**2))
	return [speed_dis_x, speed_dis_y, now_speed_x, now_speed_y]
# -------------矩陣----------------
k = 1.5

A1 = np.array([[1.0, 0.0], 
               [0.0, 1.0]])  
Q1 = np.array([[0.0, 0.0], 
               [0.0, 0.0]])
t1 = np.array([[0.0], 
               [0.0]])
m1 = np.array([[0.0], 
               [0.0]])  

A2 = np.array([[1.0, 0.0], 
               [0.0, 1.0]])  
Q2 = np.array([[0.0, 0.25], 
               [0.25, 0.0]])
t2 = np.array([[0.0], 
               [0.0]])  
m2 = np.array([[0.0], 
               [0.0]])  

A3 = np.array([[1.0, 0.0], 
               [0.0, 1.0]])  
Q3 = np.array([[0.0, 0.0], 
               [0.0, 0.0]])
t3 = np.array([[0.0], 
               [0.0]])  
m3 = np.array([[0.0], 
               [0.0]]) 

# --- constants ---
# Box2D deals with meters, but we want to display pixels,
# so define a conversion factor:
PPM = 20.0  # pixels per meter
TARGET_FPS = 60
TIME_STEP = 1.0 / TARGET_FPS
SCREEN_WIDTH, SCREEN_HEIGHT = 1280, 960

# --- pygame setup ---
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
pygame.display.set_caption('Simple pygame example')
clock = pygame.time.Clock()

# --- pybox2d world setup ---
# Create the world
world = world(gravity=(0, -5), doSleep=True)

# And a static body to hold the ground shape
ground_body = world.CreateStaticBody(
	position=(0, 1),
	shapes=polygonShape(box=(50, 5)),
)

# Create a dynamic body
rectangle_body = world.CreateDynamicBody(position=(10, 40), angle= math.radians(0))
velocity = (2.0, 0.0)  # 速度向量的方向和大小
point = rectangle_body.worldCenter
rectangle_body.ApplyLinearImpulse(velocity, point, wake=True)
# And add a box fixture onto it (with a nonzero density, so it will move)
box = rectangle_body.CreatePolygonFixture(box=(2, 2), density=1, friction=0.3)
start_shape = (list(rectangle_body.fixtures[0].shape.vertices))

# Create another dynamic body
rectangle_body2 = world.CreateDynamicBody(position=(20, 40), angle= math.radians(0))
velocity = (-2.0, 10.0)  # 速度向量的方向和大小
point = rectangle_body2.worldCenter
rectangle_body2.ApplyLinearImpulse(velocity, point, wake=True)
# And add a box fixture onto it (with a nonzero density, so it will move)
box = rectangle_body2.CreatePolygonFixture(box=(2, 2), density=1, friction=0.3)
start_shape = (list(rectangle_body2.fixtures[0].shape.vertices))



colors = {
	staticBody: (255, 255, 255, 255),
	dynamicBody: (127, 127, 127, 255),
}

last_speed_x = [0.0, 0.0]
last_speed_y = [0.0, 0.0]
flag = 2

# --- main game loop ---
running = True
while running:
	# Check the event queue
	for event in pygame.event.get():
		if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
			# The user closed the window or pressed escape
			running = False
	screen.fill((0, 0, 0, 0))
	# Draw the world
	for body in (ground_body, rectangle_body, rectangle_body2):  # or: world.bodies
		print(body)
		# The body gives us the position and angle of its shapes
		for fixture in body.fixtures:

			# 如果物體是動態的套用矩陣變換
			if body.type == 2:
				print(last_speed_x, last_speed_y)
				speed = get_speed(body, last_speed_x[flag], last_speed_y[flag])
				last_speed_x[flag] = speed[2]
				last_speed_y[flag] = speed[3]
				transformed_vertices = []
				extend_shape = expand_rectangle(start_shape, 4)
				outcome = effect_on(speed[0], speed[1], A2, Q2, t2, m2)
				A3 = outcome[0]
				Q3 = outcome[1]
				t3 = outcome[2]
				m3 = outcome[3]
				for v in extend_shape:
					x = v[0]
					y = v[1]
					x2 = v[0] ** 2
					y2 = v[1] ** 2
					xy = v[0] * v[1]
					# Apply affine transformation A
					transformed_point = [
						A3[0][0] * x + A3[0][1] * y + Q3[0][0] * x2 + Q3[0][1] * y2 + m3[0][0] * xy + t3[0][0],
						A3[1][0] * x + A3[1][1] * y + Q3[1][0] * x2 + Q3[1][1] * y2 + m3[1][0] * xy + t3[1][0],
					]
					transformed_vertices.append(transformed_point)
				#轉換成tuple
				transformed_vertices = [(float(arr[0]), float(arr[1])) for arr in transformed_vertices]
				transformed_vertices = tuple(transformed_vertices)
				vertices = [(body.transform * v) * PPM for v in transformed_vertices]
				fixture.shape.vertices = transformed_vertices
				body.ResetMassData()
			else:
				shape = fixture.shape
				vertices = [(body.transform * v) * PPM for v in shape.vertices]
			#轉換 pygame 座標跟實際座標				
			vertices = [(v[0], SCREEN_HEIGHT - v[1]) for v in vertices]
			pygame.draw.polygon(screen, colors[body.type], vertices)
			if flag == 2:
				flag = 0
			elif flag == 0:
				flag = 1
			else:
				flag = 2
	# Make Box2D simulate the physics of our world for one step.
	# Instruct the world to perform a single step of simulation. It is
	# generally best to keep the time step and iterations fixed.
	# See the manual (Section "Simulating the World") for further discussion
	# on these parameters and their implications.
	world.Step(TIME_STEP, 10, 10)

	# Flip the screen and try to keep at the target FPS
	pygame.display.flip()
	clock.tick(TARGET_FPS)

pygame.quit()
print('Done!')
