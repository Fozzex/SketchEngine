file(GLOB_RECURSE SKETCH_SOURCES Private/*.cpp Public/*.cpp)
file(GLOB_RECURSE SKETCH_HEADERS Private/*.h Public/*.h)

set(THIRDPARTY_DIR ${PROJECT_SOURCE_DIR}/${ENGINE_NAME}/ThirdParty)

add_library(${ENGINE_NAME} SHARED ${SKETCH_HEADERS} ${SKETCH_SOURCES})

target_include_directories(${ENGINE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/${ENGINE_NAME})
target_include_directories(${ENGINE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${ENGINE_NAME}/Public)

# Defines
target_compile_definitions(${ENGINE_NAME} PRIVATE SKETCH_DLL)
target_compile_definitions(${ENGINE_NAME} PUBLIC "$<$<CONFIG:DEBUG>:SKETCH_DEBUG>")

if (WIN32)
	target_compile_definitions(${ENGINE_NAME} PUBLIC SKETCH_PLATFORM_WINDOWS)
elseif (UNIX)
	target_compile_definitions(${ENGINE_NAME} PUBLIC SKETCH_PLATFORM_UNIX)

	if (APPLE)
		target_compile_definitions(${ENGINE_NAME} PUBLIC SKETCH_PLATFORM_APPLE)
	else()
		target_compile_definitions(${ENGINE_NAME} PUBLIC SKETCH_PLATFORM_LINUX)
	endif()
endif()

# Link GLFW
add_subdirectory(ThirdParty/GLFW)
target_link_libraries(${ENGINE_NAME} glfw)

set_target_properties(${ENGINE_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	CXX_STANDARD 17
)
