cmake_minimum_required(VERSION 3.10)

# set the project name
project(SynchronizedQueue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# add the executable
add_executable(SynchronizedQueue 
               main.cpp 
			   "${PROJECT_SOURCE_DIR}/src/logger.cpp" 
			   "${PROJECT_SOURCE_DIR}/src/log_queue.cpp"
			   "${PROJECT_SOURCE_DIR}/src/log_consumer.cpp"
			   )

target_include_directories(SynchronizedQueue PRIVATE
                           "${PROJECT_SOURCE_DIR}/include"
			 )

target_link_libraries(SynchronizedQueue Threads::Threads)

