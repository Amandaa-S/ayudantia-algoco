gdb_example:
	g++ -g -o gdb/example gdb/example.cpp
	gdb ./gdb/example
valgrind_example:
	g++ -g -o valgrind/example valgrind/example.cpp
	valgrind --leak-check=full ./valgrind/example
perf_example:
	g++ -g -o perf/example perf/example.cpp
	perf record -o perf/perf.data ./perf/example
	perf report -i perf/perf.data

perf_fixed:
	g++ -g -o perf/fixed perf/fixed.cpp
	perf record -o perf/perf.data ./perf/fixed
	perf report -i perf/perf.data

