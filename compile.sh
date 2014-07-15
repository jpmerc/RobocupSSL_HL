#!/bin/sh
cd proto
rm -rf ../include/proto/pb; mkdir -p ../include/proto/pb
protoc --cpp_out=../include/proto/pb *.proto

