cmake_minimum_required(VERSION 3.10)

project(playlist_app C)

# C-Standard festlegen
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include-Verzeichnis
include_directories(include)

# --------------------------------------------------
# Produktivcode als Library
# --------------------------------------------------

add_library(playlist
    src/playlist.c
)

# --------------------------------------------------
# Unit-Test-Executable
# --------------------------------------------------


# --------------------------------------------------
# CTest aktivieren
# --------------------------------------------------


# --------------------------------------------------
# Tests vor jedem Build erzwingen
# --------------------------------------------------

# Custom Target zum Ausführen der Tests

# --------------------------------------------------
#  Hauptprogramm
# --------------------------------------------------

# Executable definieren
add_executable(playlist_app
    main.c
    src/playlist.c
)

target_link_libraries(playlist_app
    playlist
)

# Hauptprogramm darf nur gebaut werden,
# wenn die Unit-Tests erfolgreich waren
