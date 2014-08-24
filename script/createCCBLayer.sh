#!/bin/sh
# ----------------------------------------
# Generate a sub class of CCBLayer
#	The layer that using CocosBuilder
#
# Usage: <folder> <Class Name>>
#
# Main Output Folder
# Projects/Dg/Classes/
#
# Example: 
# Input: 
# >createCCBLayer.sh UnitTest Test2CCBLayer
#	
# Output:
# > Projects/Dg/Classes/UnitTest/Test2CBBLayer.h created
# > Projects/Dg/Classes/UnitTest/Test2CBBLayer.cpp created
#
# Author: kenlee
# ----------------------------------------
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Manage the command arguments
# Checking argument
if ([ $# -ne 2 ])
then
echo "Usage: $0 [Folder] [Class Name]"
exit 0
fi

FOLDER_NAME=$1
CLASS_NAME=$2


# Output Setting 
ROOT_DIR=$SCRIPT_DIR/..
SRC_ROOT_DIR=$ROOT_DIR/Classes/
#SRC_ROOT_DIR=$SCRIPT_DIR/test/ 	# For testing

# Testing Dir
#TEST_SRC_DIR=$SCRIPT_DIR/test		

# Template Setting
TEMPLATE_NAME=ccblayer
TEMPLATE_H=$SCRIPT_DIR/template/$TEMPLATE_NAME.h.template
TEMPLATE_CPP=$SCRIPT_DIR/template/$TEMPLATE_NAME.cpp.template



# Define the output location
OUTPUT_CPP=$SRC_ROOT_DIR/$FOLDER_NAME/$CLASS_NAME.cpp
OUTPUT_H=$SRC_ROOT_DIR/$FOLDER_NAME/$CLASS_NAME.h

# Tell the information
echo "TEMPLATE:"
echo "  Header : $TEMPLATE_H"
echo "  Source : $TEMPLATE_CPP"
echo "OUTPUT:"
echo "  Header : $OUTPUT_H"
echo "  Source : $OUTPUT_CPP"

#exit;

# Note: will be execute below

# check if the out file exist
if [ -f $OUTPUT_CPP ];
then
echo "Source '$OUTPUT_CPP' already exists'"
exit
fi

if [ -f $OUTPUT_H ];
then
echo "Header '$OUTPUT_H' already exists'"
exit
fi

# Create the source root
mkdir -p $SRC_ROOT_DIR


# Create the cpp
echo "Create cpp '$OUTPUT_CPP'"
sed -e "s/\#ClassName\#/$CLASS_NAME/g" $TEMPLATE_CPP > $OUTPUT_CPP

echo "Create header '$OUTPUT_H'"
sed -e "s/\#ClassName\#/$CLASS_NAME/g" $TEMPLATE_H > $OUTPUT_H



