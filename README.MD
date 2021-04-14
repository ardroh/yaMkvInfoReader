# Yet Another MKV Info Reader 

**Work in progress**

Software will provide basic information about the MKV file such as:
* length,
* streams,
* codecs.

## Getting Started

TBD

### Prerequisites

Requirements for the software and other tools to build, test and push
- cmake >= 3.16,
- compiler supporting c++17,
- boost,
- google test,
- google mock,
- libav.

### Building

Clone the repository and navigate to the folder. Run:

```sh
$ cmake --build . --target all
```

## Running the tests

Navigate to the repository folder:
```sh
$ cmake --build . --target yaMkvInfoReader_tests
```

## License

The project is covered by with the MIT license.