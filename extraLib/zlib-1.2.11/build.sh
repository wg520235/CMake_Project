WORK_DIR=$(cd $(dirname $0); pwd)
export CC=gcc CXX=g++
#cd WORK_DIR
mkdir install_dir
./configure --prefix=$WORK_DIR/install_dir
make && make install