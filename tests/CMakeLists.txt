
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

project(rin_tests)

add_executable(${PROJECT_NAME}
	test_demo.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/../src/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/../vendor/tests/"
)

enable_testing()
add_test(
    NAME rin_tests
    COMMAND ${PROJECT_NAME}
)
