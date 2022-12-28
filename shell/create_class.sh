#!/bin/bash

# Check if the class name was provided
if [ $# -eq 0 ]
then
  echo "Error: No class name provided"
  exit 1
fi

if [ ! -d inc/ ] || [ ! -d src/ ]
then
  echo "Can't find direcotries inc/ src/"
  base_dir_inc=./
  base_dir_src=./
else
  base_dir_inc=inc/
  base_dir_src=src/
fi

# Get the class name
class_name=$1

class_name_upper=${class_name^^}

# Create the .hpp file
echo "Creating $class_name.hpp file..."
cat > $base_dir_inc$class_name.hpp << FILE
#ifndef ${class_name_upper}_HPP
#define ${class_name_upper}_HPP

class $class_name {
 public:
  $class_name();
  ~$class_name();

 private:
};

#endif  // ${class_name_upper}_HPP
FILE

# Create the .cpp file
echo "Creating $class_name.cpp file..."
cat > $base_dir_src$class_name.cpp << NAME
#include "$class_name.hpp"

$class_name::$class_name() {}

$class_name::~$class_name() {}
NAME

echo "Done!"
