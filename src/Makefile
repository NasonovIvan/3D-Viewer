CC=						gcc
var=					$(shell pkg-config --cflags --libs check)
FLAGS=					-Wall -Wextra -std=c11 -Werror -std=c11 
CHECK_FLAGS=            -lcheck -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
GCOV_FLAGS=             -fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS1=           -lcheck -lm -lpthread

PATH_C=					Functions/
#PATH_O=					../datasets/
PATH_T=					Tests/
APP= 3dVFront/3dV/3dV.app/Contents/MacOS/3dV
MAIN=					../code-samples/main.c
TEST_FILE=		    	Tests/test.c
MAIN_O=					$(PATH_O)main.o

SRCS = $(PATH_C)*.c $(wildcard)
OBJST = $(SRCS:.c=.o)

SRCS_TEST = 			$(PATH_C)parser.c\
						$(PATH_C)affine.c\
					
FOO_O=					../datasets/*.o
NAME =					test
REPORT_NAME =			report
all: install
test: clean
	$(CC) $(SRCS_TEST) $(TEST_FILE) $(CHECK_FLAGS1) $(var) -o Tests/test 
	./Tests/test
install: 
	cd ./3dVFront/3dV/ && cmake . && $(MAKE)
	open $(APP)
run:
	open $(APP)
s21_3dV.a: $(OBJS)
	ar rc s21_3dV.a $(OBJS)
	ranlib s21_3dV.a
uninstall: clean
	rm -rf 3dVFront/3dV/3dV.app
	rm -rf 3dVFront/3dV/CMakeCache.txt
	rm -rf 3dVFront/build*
	rm -rf 3dVFront/3dV/CMakeFiles/
	rm -rf 3dVFront/3dV/Makefile
	rm -rf 3dVFront/3dV/3dV_autogen/
	rm -rf 3dVFront/3dV/cmake_install.cmake
	rm -rf 3dVFront/3dV/CMakeCache.txt.prev
	rm -rf $(HOME)/Desktop/3DViewer_v1.0.app
clean:
	rm -rf *.gc* *.a *.gz *.o *.out *.info $(PATH_T)*.info
	rm -rf *.dSYM $(PATH_T)*.dSYM $(PATH_C)*.out
	rm -rf ../datasets/test
	rm -rf doxygen/html
	rm -rf 3dVDir
	rm -rf 3dVArh.tar.gz
	rm -rf Tests/report
	rm -rf Tests/test
dvi:
	cd doxygen && ./doxygen Doxyfile && open html/index.html
dist: clean
	mkdir 3dVDir
	cp $(PATH_C)*.c 3dVDir
	cp $(PATH_C)*.h 3dVDir
	cp *.h 3dVDir
	cp ./3dVFront/3dV/CMakeLists.txt 3dVDir
	cp ./3dVFront/3dV/*.cpp 3dVDir
	cp ./3dVFront/3dV/*.ui 3dVDir
	cp Makefile 3dVDir
	tar -czf 3dVArh.tar.gz 3dVDir/
	# rm -rf 3dVDir
gcov_report: 
	$(CC) $(var) -o $(PATH_T)$(NAME) $(SRCS_TEST) $(PATH_T)test.c $(GCOV_FLAGS) $(CHECK_FLAGS1)
	./$(PATH_T)$(NAME)
	lcov -t "gcov_report" -o $(PATH_T)Tests.info -c -d .
	genhtml -o $(PATH_T)$(REPORT_NAME) $(PATH_T)Tests.info
	open $(PATH_T)report/index.html
	rm $(PATH_T)$(NAME)
	rm -rf *.gcno
	rm -rf *.gcda
check: uninstall
	cppcheck $(SRCS)
	cp ../materials/linters/.clang-format ../.clang-format
	clang-format  -n $(SRCS)
reinstall:
	make uninstall
	make install
