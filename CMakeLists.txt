cmake_minimum_required(VERSION 3.23)
project(Project0)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project0 main.cpp vec3.h ray.h hittable.h sphere.h hittable_list.h rtweekend.h camera.h material.h moving_sphere.h aabb.h bvh.h texture.h perlin.h ab_rect.h flip_face.h box.h translate.h rotate.h constant_medium.h isotropic.h)
