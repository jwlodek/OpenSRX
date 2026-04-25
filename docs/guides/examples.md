# Examples {#examples}

The repository ships with example programs under the `examples/` directory.

## VersionInfo

Prints the compile-time version of the OpenSRX library:

```bash
./build/examples/opensrx_example
```

This program demonstrates usage of the OpenSRX::GetVersion template function.

## Simulator

A Python-based scanner simulator is provided for development and testing:

```bash
python scripts/simulator.py
```

This opens a TCP server that emulates a subset of the SR-X protocol, allowing
you to run examples and tests without physical hardware.
