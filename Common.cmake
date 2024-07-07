if (STRING_ENCODING_TYPE STREQUAL "ICONV")
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_ICONV)
elseif (STRING_ENCODING_TYPE STREQUAL "WIN32API")
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_WIN32API)
elseif (STRING_ENCODING_TYPE STREQUAL "NONE")
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_NONE)
else()
    # User action requested
endif()

# Maximum warnings emission, treat all warnings as errors
#
# This method was taken from https://www.pragmaticlinux.com/2022/07/enable-compiler-warnings-with-cmake/
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
        -Wall -Wextra -Wpedantic -Werror
        # See <https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wstrict-aliasing_003dn>:
        #
        # > Level 1: (...) it has very few false negatives. However, it has many false positives.
        #
        # If we run into false positives in the future, we can increase the level, but let's
        # start with the most aggressive option to make sure we don't miss anything.
        -fstrict-aliasing -Wstrict-aliasing=1
    >
)
