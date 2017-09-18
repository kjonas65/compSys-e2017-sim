# Compsys A2/A3 tools.

## Build

Use `make asm`, `make sim` or just `make`.

## Usage

The tools include an assembler `asm`, a simulator `sim`, and a trace-prettifier `trace`.

To assemble a program use the assembler as follows:

    ./asm input-file [output-file]

E.g.

    ./asm heapsort.x64 heapsort.x64.out

If you leave out `output-file` the assembler will print out a prettyfied dump of the generated code.

To simulate an assembled program use the simulator as follows:

    ./sim input-file [trace-file]

E.g.

    ./sim heapsort.x64.out heapsort.trace

The `trace-file` argument is optional. If given the simulator will generate a trace-file.

To prettify a trace-file use the trace-prettifier as follows:

    ./trace trace-file

E.g.

    ./trace heapsort.trace

## Source code layout

The source code is divided into seperate modules as follows:

  1) Files prefixed with `asm_` contains source code for the assembler.
  2) Files prefixed with `sim_` contains source code for the simulator.
  3) Files prefixed with `isa_` contains source code for the instruction set. (Used by by both the simulator and the assembler.)
  4) Files prefixed with `ano_` contains source code for the annoation library.
