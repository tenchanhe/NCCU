import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import Box2D

# 創建物理世界
world = Box2D.b2World(gravity=(0, -10), doSleep=True)

# 地面高度和圓形半徑
y_ground = 0.0
radius = 1.0

# 創建圓形物體
body_def = Box2D.b2BodyDef()
body_def.type = Box2D.b2_dynamicBody
body_def.position.Set(-9, 10)  # 修改初始位置
body = world.CreateBody(body_def)

shape = Box2D.b2CircleShape()
shape.radius = radius
fixture_def = Box2D.b2FixtureDef()
fixture_def.shape = shape
fixture_def.density = 1
fixture_def.friction = 0.3
fixture_def.restitution = 0.8
body.CreateFixture(fixture_def)

# 創建地面物體
ground = world.CreateStaticBody(
    position=(0, y_ground),
    shapes=Box2D.b2PolygonShape(box=(50, 1))
)

# 畫圖
fig, ax = plt.subplots()

# 圓形
circle, = ax.plot([], [], 'o', markerfacecolor='none', lw=2)
circle.set_markersize(20)

# 地面
ground_line, = ax.plot([], [], '-', lw=2)


def init():
    ax.set_xlim(-10, 10)
    ax.set_ylim(-1, 15)
    ground_line.set_data([], [])
    circle.set_data([], [])
    return ground_line, circle


def update(frame):
    world.Step(1 / 60, 6, 2)

    pos = body.position
    circle.set_data([pos.x], [pos.y])

    ground_shape = ground.fixtures[0].shape
    ground_vertices = np.array([ground.transform * v for v in ground_shape.vertices])
    ground_line.set_data(ground_vertices[:, 0], ground_vertices[:, 1])

    if body.position.y < y_ground + radius:
        # 碰到地面，反彈
        vel = body.linearVelocity
        body.linearVelocity = (-vel.x, -vel.y)  # 修改 x 方向速度反向

    return ground_line, circle

ani = animation.FuncAnimation(fig, update, frames=600, init_func=init, blit=True, interval=1000/60, repeat=True)
plt.show()
