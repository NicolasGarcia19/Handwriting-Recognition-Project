# Programming Assignment 5: Handwriting Recognition Systems

## Before You Begin Checklist

- [x] Be able to connect to ECELinux with VS Code (see [tutorial](https://cornell-ece-docs.github.io/ece-tutorials/tut0-ecelinux/#3-remote-access-via-vs-code))
- [x] Set up ssh with GitHub (we did this in last week's discussion section)
- [ ] `git clone` your programming assignment repo to ecelinux
- [x] RECOMMENDED: Install [clangd extension](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) on the remote host
  - Clangd provides many useful error messages and auto-corrections
- [ ] Mark the test and build scripts as executable
  - `cd pa5-sys`
  - `chmod +x scripts/*.sh`
- [ ] Build the starter code
  - `./scripts/build.sh` (It should say 'Build Successful')

Now you are ready to begin!

## Building the Code

Make sure your working directory is `pa5-sys`. Then, execute the build script: `./build.sh`

## Evaluating the Code

Make sure to inspect the code in `/eval` and `/test`: there are some scattered todo items, like creating your own tests.