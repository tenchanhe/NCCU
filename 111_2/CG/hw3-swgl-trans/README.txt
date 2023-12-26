[Note in ubuntu]

sudo apt update
sudo apt install build-essential cmake xorg-dev libfreetype6-dev
sudo apt install mesa-common-dev libgl1-mesa-dev libglu1-mesa-dev

[if no glfw glew glut]
sudo apt install libglfw3-dev libglew-dev freeglut3-dev

[if no glm]
sudo apt install libglm-dev

[build using cmake]
mkdir build
cd build
cmake ..
make

