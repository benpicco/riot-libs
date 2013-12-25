#!/bin/bash
find -name '*.c' -exec sed -i 's/\ malloc(/\ print_malloc(/g' {} \;
find -name '*.c' -exec sed -i 's/\ calloc(/\ print_calloc(/g' {} \;
find -name '*.c' -exec sed -i 's/\ realloc(/\ print_realloc(/g' {} \;
find -name '*.c' -exec sed -i 's/\ free(/\ print_free(/g' {} \;
