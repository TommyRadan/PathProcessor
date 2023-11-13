# Look for Doxygen package
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/config.doxy
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else(DOXYGEN_FOUND)
    message(STATUS "Doxygen needs to be installed to generate the doxygen documentation")
endif(DOXYGEN_FOUND)
