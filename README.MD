# Yet Another MKV Info Reader 

**Work in progress**

Software will provide basic information about the MKV file such as:
* length,
* streams,
* codecs.

## Command args

* ```-f filename.mkv``` - matroska file name to check

## Running

Run the following:

```sh 
./yaMkvInfoReader_run -f sample_640x360.mkv
```

**Output**:

```
yetAnotherMkvInfoReader starting
Filename: sample_640x360.mkv
File size: 573066 bytes
Format name: Matroska / WebM
Duration: 13s
Number of streams: 1
Streams:
        0. Index: 0 Type: 0 Codec Id: 27
```

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