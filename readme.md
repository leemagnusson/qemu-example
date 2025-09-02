install
```
sudo apt install qemu-user
```

build arm gcc from source
```
sudo apt update
$(sed -n '/sudo apt install/,/```/ { /```/d; p }' README.md | tr -d '\')
```

```
mkdir -p gcc/src
cd gcc/src
git clone https://git.gitlab.arm.com/tooling/gnu-devtools-for-arm.git
cd gnu-devtools-for-arm
python3 extras/source-fetch.py checkout --shallow --src-dir=.. spc/trunk.spc
cd ../gcc
./contrib/download_prerequisites  --force --directory=..
cd ..
$(grep libexpat.git gnu-devtools-for-arm/README.md)
cd ..
ln -s src/gnu-devtools-for-arm/build-gnu-toolchain.shd
```

```
./build-gnu-toolchain.sh --target=arm-none-eabi --with-arch=armv7e-m+fp --disable-multilib -- --config-flags-gcc=--with-float=hard start
```
