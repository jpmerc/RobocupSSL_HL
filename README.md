#Robocup Ulaval
##High-Level Programming Team - Complete Game

###Simulation
To download and compile grSim (robocup compatible Simulator) go to this link:
https://github.com/mani-monaj/grSim

###Referee
To download and compile refbox (robocup compatible referee input) go to this link:
https://github.com/Hawk777/ssl-refbox
#Running Referee:
```sh
$ ./sslrefbox -C single.conf
```
user manual : http://robocupssl.cpe.ku.ac.th/referee:start

##Compilation

###Dependencies
```sh
$ sudo apt-get install git cmake
```
install protobuf:
https://code.google.com/p/protobuf/downloads/list

If your not on Ubuntu 14 install boost :
```sh
$ wget -O boost_1_54_0.tar.gz http://sourceforge.net/projects/boost/files/boost/1.54.0/boost_1_54_0.tar.gz/download
$ tar xzvf boost_1_54_0.tar.gz
$ cd boost_1_54_0/
$ wget https://dl.dropbox.com/u/88131281/install_boost.sh
```
In install_boost.sh, at the line : "sudo ./b2 --with=all -j $n install"
change $n with the number of core of your machine

```sh
$ chmod +x install_boost.sh
$ ./install_boost.sh
```

###Build
To build the project go in the folder
```sh
$ ./compile.sh
```

If you use QtCreator, simply open the project with the CmakeList and build
else
```sh
$ make
```
