set(CPACK_PACKAGE_NAME "kaitai_struct_qt_runtime")
set(CPACK_PACKAGE_VERSION "0.1")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Kaitai Struct Qt Runtime")
set(CPACK_PACKAGE_DESCRIPTION "Kaitai Struct Qt Runtime")

if(CPACK_GENERATOR MATCHES "DEB")
    # Создание DEB пакета

    set(VERBOSE_LOGGING FALSE)

    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")

    if (${QT_VERSION_MAJOR} STREQUAL "5")
        set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt${QT_VERSION_MAJOR}core${QT_VERSION_MAJOR}a")
    else()
        if (${QT_VERSION_MAJOR} STREQUAL "6")
            set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt${QT_VERSION_MAJOR}core${QT_VERSION_MAJOR}")
        endif()
    endif()

    set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
    include(CPack)
endif(CPACK_GENERATOR MATCHES "DEB")
