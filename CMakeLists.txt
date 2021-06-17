CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(driver
src/search_factory.cpp
src/BookRepository.cpp
src/Book.cpp
src/Date.cpp
src/BookItem.cpp
src/LibraryCatalog.cpp
src/SearchAND.cpp
src/SearchContains.cpp
src/SearchOR.cpp
src/main.cpp
)

ADD_EXECUTABLE(bookRepoTest
  src/BookRepositoryTest.cpp
src/BookRepository.cpp
src/Book.cpp
src/Date.cpp
src/BookItem.cpp
src/LibraryCatalog.cpp
)


ADD_EXECUTABLE(searchTest
    tests/searchTest.cpp
    src/BookRepository.cpp
    src/Book.cpp
    src/Date.cpp
    src/BookItem.cpp
    src/LibraryCatalog.cpp
    src/SearchAND.cpp
    src/SearchContains.cpp
    src/SearchOR.cpp
    src/search_factory.cpp
) 

ADD_EXECUTABLE(BoxTest
    tests/searchBoxTest.cpp
    src/BookRepository.cpp
    src/Book.cpp
    src/SearchAND.cpp
    src/SearchContains.cpp
    src/SearchOR.cpp
    src/BookRepository.cpp
    src/Book.cpp
    src/Date.cpp
    src/BookItem.cpp

)

ADD_EXECUTABLE(incrementTest 
	tests/incrementTest.cpp
	src/Date.cpp
)

ADD_EXECUTABLE(checkOutTest 
	tests/checkOutTests.cpp
	src/Book.cpp
	src/BookRepository.cpp
	src/Date.cpp
	src/BookItem.cpp

)	


TARGET_LINK_LIBRARIES(checkOutTest gtest)
TARGET_LINK_LIBRARIES(searchTest gtest)
TARGET_LINK_LIBRARIES(BoxTest gtest)
TARGET_LINK_LIBRARIES(incrementTest gtest)
TARGET_COMPILE_DEFINITIONS(checkOutTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(searchTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(BoxTest PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(incrementTest PRIVATE gtest_disable_pthreads=ON)

