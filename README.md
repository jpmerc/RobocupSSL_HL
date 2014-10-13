Robocup Ulaval
===========
This is the repository of the high-level programming team of the Laval University's Robocup project.


#Installation
These installation instructions have been tested and work on Ubuntu 14, Mint 17, Mint Debian.
###Dependencies
```sh
sudo apt-get install git build-essential cmake libqt4-dev libqt4-opengl-dev libgl1-mesa-dev libglu1-mesa-dev protobuf-compiler libprotobuf-dev libode-dev libboost1.54-all-dev libgtkmm-2.4-dev
```

###VarTypes
```sh
cd /tmp
wget http://vartypes.googlecode.com/files/vartypes-0.7.tar.gz
tar xfz vartypes-0.7.tar.gz
cd vartypes-0.7
mkdir build && cd build
cmake ..
make 
sudo make install
```

###GrSim
```sh
cd /path/to/your/projects/folder/
git clone https://github.com/mani-monaj/grSim.git
cd grSim
mkdir build && cd build
cmake ..
make
```

###SSL Refbox
```sh
cd /path/to/your/projects/folder/
git clone https://github.com/Hawk777/ssl-refbox.git
cd ssl-refbox
make
```

###RobocupUlaval SoccerGame
```sh
cd /path/to/your/projects/folder/
git clone https://github.com/RoboCupULaval/RobocupSSL_HL.git
cd RobocupSSL_HL
./compile.sh
mkdir build && cd build
cmake ..
make
```

#Usage
First, you have to start the referee so the soccer game can listen to its command :

```sh
cd /path/to/your/ssl-refbox/installation/
./sslrefbox -C single.conf
```

Then, start the simulator :

```sh
cd /path/to/your/grSim/installation/
cd bin
./grsim
```

Finally, launch the soccer game :

```sh
cd /path/to/your/soccerGame/installation/
cd build
./robocupulaval_cli
```

You should now be able to control the game with the referee.