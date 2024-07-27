CLAVAJS_INSTALL_DIR=$HOME/Clava-JS

# install dependencies
sudo apt install nodejs npm openjdk-21-jdk curl git
# + install gradle 8.9

# ensure node 18 is installed
if command -v nvm >/dev/null 2>&1; then
    echo "nvm is installed"
else
    curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
    export NVM_DIR="$HOME/.nvm"
    [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
    [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"
fi
nvm install 18

# create install directory from scratch
rm -rf $CLAVAJS_INSTALL_DIR
mkdir -p $CLAVAJS_INSTALL_DIR
cd $CLAVAJS_INSTALL_DIR

# create package.json
PACKAGE_JSON='{
  "name": "myPackage",
  "type": "module",
  "workspaces": [
    "clava/Clava-JS",
    "lara-framework/Lara-JS"
  ]
}'
echo "$PACKAGE_JSON" > ./package.json

# clone repositories and build
git clone https://github.com/specs-feup/clava
git clone https://github.com/specs-feup/lara-framework
git clone https://github.com/specs-feup/specs-java-libs
cd clava
git checkout feature/clava-js
cd ..
cd lara-framework
git checkout feature/lara-js
cd ..
npm i
npm run build -w lara-framework/Lara-JS 
npm run build -w clava/Clava-JS

# install clava-js globally
cd clava/Clava-JS
npm install -g
npm list -g --depth=0 | grep clava-js
# run "npm link clava-js" on any project that requires clava-js before running "npm install"

# build clava weaver
cd $CLAVAJS_INSTALL_DIR
cd clava/ClavaWeaver
gradle installDist
cd ../Clava-JS
ln -s ../ClavaWeaver/build/install/ClavaWeaver java-binaries

# give execute permissions to clava-js
clava_js_path=$(whereis -b clava-js | awk '{print $2}')
sudo chmod +x "$clava_js_path"

# verify installation
clava-js --help

