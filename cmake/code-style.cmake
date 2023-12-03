# Find clang-format
find_program(CLANG_FORMAT "clang-format")
if(NOT CLANG_FORMAT)
    message(STATUS "clang-format not found (No style related targets)")
    return()
else()
    message(STATUS "Found clang-format: ${CLANG_FORMAT}")
endif()

# Custom target for checking for styling mistakes
add_custom_target(style
    COMMAND ${CMAKE_COMMAND} -E echo "Checking code style..."
    COMMAND ${CMAKE_COMMAND} -E echo "========================="
    COMMAND ${CLANG_FORMAT} -style=file -n -Werror ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-format"
    VERBATIM
)

# Custom target for fixing styling mistakes
add_custom_target(fix
    COMMAND ${CMAKE_COMMAND} -E echo "Fixing code style..."
    COMMAND ${CMAKE_COMMAND} -E echo "========================="
    COMMAND ${CLANG_FORMAT} -style=file -i ${SOURCES} ${HEADERS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-format to fix formatting"
    VERBATIM
)
