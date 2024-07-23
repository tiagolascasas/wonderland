CLAVAJS_INSTALL_DIR=$HOME/Clava-JS

# install dependencies
sudo apt install nodejs npm default-jdk gradle curl git

# ensure node 18 is installed
if command -v nvm >/dev/null 2>&1; then
    echo "nvm is installed"
else
    curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
    export NVM_DIR="$HOME/.nvm" && [ -s "$NVM_DIR/nvm.sh" ]
fi
nvm install 18
node -v
npm -v

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
git clone https://github.com/specs-feup/specs-java-libs
git checkout java-updates
cd clava/ClavaWeaver
gradle installDist

