# ---------------------------------------------------------------------------
# Example application - a simple demo to get started
# ---------------------------------------------------------------------------
add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

# ---------------------------------------------------------------------------
# Raytracer application - the main program you will build in this assignment
# ---------------------------------------------------------------------------
add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
)
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

# ---------------------------------------------------------------------------
# Test executable - runs unit tests using doctest
# ---------------------------------------------------------------------------
add_executable(tests
  tests.cpp)

target_link_libraries(tests
  ${GLFW_LIBRARIES}
  ${FRAMEWORK_NAME}
)

# Register the test executable with ctest
add_test(NAME doctest COMMAND tests)
