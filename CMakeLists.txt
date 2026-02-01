cmake_minimum_required(VERSION 4.1)
project(mini_db)

set(CMAKE_CXX_STANDARD 20)

add_executable(mini_db src/main.cpp
        src/db/Database.cpp
        src/db/Database.h
        src/storage/StorageEngine.cpp
        src/storage/StorageEngine.h
        src/db/Command.h
        src/storage/Index.h
        src/storage/SortedIndex.cpp
        src/storage/SortedIndex.h)
