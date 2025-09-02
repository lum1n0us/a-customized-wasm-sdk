# Assumptions 💥🔥

In a project setup, it is assumed that the `this-wasm-sdk` directory should be placed next to the `wasi-sdk-24.0` directory. This ensures proper integration and compatibility between the two SDKs. ⚡🚀

```shell
<somewhere>
├── this-wasm-sdk
└── wasi-sdk-24.0-x86_64-linux
```

# How to Build and Run

```bash
$ pwd
<repo_root>/samples/say-hi

# config and build
$ cmake -S . -B build --toolchain ../../cmake/wasm32.cmake
$ cmake --build build

# run test
$ ctest --test-dir build
```

# A quick overview

``` shell
this-wasm-sdk/
├── bin
├── cmake
├── include
├── lib
└── samples
```

It is a customized Wasm SDK to bring extra headers based on wasi-sdk.

`bin` is the directory containing a standalone WAMR execution tools to run Wasm Apps.

`cmake` placed a toolchain file for Wasm modules.

`include` are the header files for the customized WASM SDK.

> [!TODO]
> `lib`

`samples` contains example applications using the customized WASM SDK.
