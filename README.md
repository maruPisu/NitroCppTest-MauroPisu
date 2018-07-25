# Rectangle intersection for Nitro
## Dependencies
### rapidjson
Make sure you have rapidjson installed on your machine.

SUSE users can use zypper
```
sudo zypper in rapidjson
```
Debian users can use apt
```
sudo apt-get install rapidjson
```
Mac Users can use brew
```
brew install rapidjson

```
### boost
Make sure you have boost installed in your machine
## Build & Run
Once the project is cloned, I suggest to `cd` in the main folder. 

From there create the build directory and `cd` into it
```
mkdir build && cd build
```
then run the cmake on the parent directory
```
cmake ..
```
if no errors were thrown, you can make the project
```
make
```

if you want you can run the tests with the command
```
make test
```

at this point you should be able to run the program with the command
```
./intersection <filename>
```
