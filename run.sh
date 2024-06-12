rm bin -fr
cmake . -B bin
cmake --build bin
./bin/todolist