import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import Box2D

# 创建Box2D世界
world = Box2D.b2World(gravity=(0, -10))

# 创建圆形刚体
circle = world.CreateDynamicBody(position=(0, 20), userData='circle')
circle_fixture = circle.CreateCircleFixture(radius=1)

# 创建地面刚体
ground = world.CreateStaticBody(position=(0, 0), userData='ground')
ground_fixture = ground.CreateEdgeFixture(vertices=[(-10, 0), (10, 0)])

# 创建弹性关节
joint = world.CreateRevoluteJoint(
    bodyA=circle, bodyB=ground,
    anchor=(0, 0), collideConnected=False,
    referenceAngle=0, lowerAngle=-np.pi/8, upperAngle=np.pi/8,
    maxMotorTorque=100, motorSpeed=-10, enableMotor=True
)

# 定义动画更新函数
def update(frame, circle):
    # 让Box2D世界模拟一步
    world.Step(1/60, 6, 2)

    # 获取圆形刚体的位置和旋转角度
    pos = circle.transform * circle_fixture.shape.pos
    angle = circle.angle

    # 清除之前的绘制
    plt.cla()

    # 绘制圆形
    circle_patch = plt.Circle(pos, 1, fill=False, edgecolor='black')
    plt.gca().add_patch(circle_patch)

    # 绘制地面
    ground_patch = plt.Line2D((-10, 10), (0, 0), color='black')
    plt.gca().add_line(ground_patch)

    # 设置坐标轴范围
    plt.xlim(-10, 10)
    plt.ylim(0, 20)

# 创建动画对象
animation = FuncAnimation(plt.gcf(), update, fargs=(circle,), interval=1/60*1000)

# 显示动画
plt.show()

