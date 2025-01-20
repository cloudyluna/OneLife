#!/bin/sh

find . -iname '*.h' -o -iname '*.cpp' | xargs clang-format -style=file:.clang-format -i
