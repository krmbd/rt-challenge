if(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of rt-challenge"
  )
endif()

# ---- Running ----
add_custom_target(
    run-exe
    COMMAND rt-exe
    DEPENDS rt-exe
    VERBATIM
    )

# ---- Testing ----
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

# ---- Linting ----
include(cmake/lint-targets.cmake)
