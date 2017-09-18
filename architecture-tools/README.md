# Compsys A2/A3 tools.

## Build

Use `make asm`, `make sim` or just `make`.

## Usage

The tools include an assembler `asm` and a simulator `sim`. To assemble a program use the assembler as follows:

    ./asm input-file [output-file]

E.g.

    ./asm test.x64 test.out

If you leave out `output-file` the assembler will print out a prettyfied dump of the generated code.

To simulate an assembled program use the simulator as follows:

    ./sim input-file [trace-file]

E.g.

    ./sim test.out

The `trace-file` argument is optional. If given the simulator will generate a trace-file.

## Source code layout

The source code is divided into seperate modules as follows:

  1) Files prefixed with `asm_` contains source code for the assembler.
  2) Files prefixed with `sim_` contains source code for the simulator.
  3) Files prefixed with `isa_` contains source code for the instruction set. (Used by by both the simulator and the assembler.)
  4) Files prefixed with `ano_` contains source code for the annoation library.
