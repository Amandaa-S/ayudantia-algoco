Crear contenedor
docker build -t cpp-debugging-env .

Correr contenedor
docker run -it --ulimit nofile=4096:8192 cpp-debugging-env

Dentro del contenedor
    Prueba de gdb:
        make gdb_example
    Prueba de valgrind
        make valgrind_example
Fuera del contenedor
    Prueba de perf
        make perf_example
        make perf_fixed
        time perf/example
        time perf/fixed
    