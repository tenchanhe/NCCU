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

# -------------矩陣----------------
A = np.array([[1, 0], 
              [0, 1]])  
Q = np.array([[0, 0], 
              [0, 0]])
t = np.array([[0], 
              [0]])  
m = np.array([[0.5], 
              [1]])  

# --- constants ---
# Box2D deals with meters, but we want to display pixels,
# so define a conversion factor:
PPM = 20.0  # pixels per meter
TARGET_FPS = 60
TIME_STEP = 1.0 / TARGET_FPS
SCREEN_WIDTH, SCREEN_HEIGHT = 640, 480

# --- pygame setup ---
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
pygame.display.set_caption('Simple pygame example')
clock = pygame.time.Clock()

# --- pybox2d world setup ---
# Create the world
world = world(gravity=(0, -10), doSleep=True)

# And a static body to hold the ground shape
ground_body = world.CreateStaticBody(
    position=(0, 1),
    shapes=polygonShape(box=(50, 5)),
)

# Create a dynamic body
dynamic_body = world.CreateDynamicBody(position=(10, 15), angle=15)
ball_body = world.CreateDynamicBody(position=(5, 10), angle=0)

# And add a box fixture onto it (with a nonzero density, so it will move)
box = dynamic_body.CreatePolygonFixture(box=(2, 1), density=1, friction=0.3)
start_shape = (list(dynamic_body.fixtures[0].shape.vertices))

colors = {
    staticBody: (255, 255, 255, 255),
    dynamicBody: (127, 127, 127, 255),
}

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
    for body in (ground_body, dynamic_body):  # or: world.bodies
        # The body gives us the position and angle of its shapes
        for fixture in body.fixtures:

            # 如果物體是動態的套用矩陣變換
            if body.type == 2:
                # Apply transformation matrices A and Q to the vertices
                transformed_vertices = []
                print(start_shape)
                for v in start_shape:
                    x = v[0]
                    y = v[1]
                    x2 = v[0] ** 2
                    y2 = v[1] ** 2
                    xy = v[0] * v[1]

                    # Apply affine transformation A
                    transformed_point = [
                        A[0][0] * x + A[0][1] * y + Q[0][0] * x2 + Q[0][1] * y2 + m[0][0] * xy + t[0][0],
                        A[1][0] * x + A[1][1] * y + Q[1][0] * x2 + Q[1][1] * y2 + m[1][0] * xy + t[1][0],
                    ]
                    transformed_vertices.append(transformed_point)
                #轉換成tuple
                transformed_vertices = [(float(arr[0]), float(arr[1])) for arr in transformed_vertices]
                transformed_vertices = tuple(transformed_vertices)
                vertices = [(body.transform * v) * PPM for v in transformed_vertices]
                fixture.shape.vertices = transformed_vertices
                body.ResetMassData()
                print(fixture.shape.vertices)
                print(body.position)
                #body.position = (vertices[0]+vertices[1]+vertices[2]+vertices[3]) / PPM / 4
                print("------------------------------")
            else:
                shape = fixture.shape
                vertices = [(body.transform * v) * PPM for v in shape.vertices]
            #轉換 pygame 座標跟實際座標                
            vertices = [(v[0], SCREEN_HEIGHT - v[1]) for v in vertices]
            pygame.draw.polygon(screen, colors[body.type], vertices)

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
