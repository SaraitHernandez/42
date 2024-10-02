#!/bin/bash

find . \( -path "./mlx" -prune \) -o \( -name "*.c" -o -name "*.h" \) -print | xargs norminette
