# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  mat2.cpp
  rectangle.cpp
  vec2.cpp
  circle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  rectangle.cpp
  circle.cpp
  window.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

add_executable(aufgabe_2_und_3
aufgabe_2_und_3.cpp
)

add_executable(beispielprogramm
beispielprogramm.cpp)

add_executable(aufgabe_4
glew.c
aufgabe_4.cpp
vec2.cpp
mat2.cpp
circle.cpp
window.cpp
)
target_link_libraries(aufgabe_4
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})
