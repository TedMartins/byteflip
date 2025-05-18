# ByteFlip (TBL Endian Converter)

A small utility to convert `.tbl` mapping files from **big-endian** to **little-endian** (or vice versa) format.

Useful for retro game ROM hacking and translation tools, especially when dealing with text encoding on platforms like GBA that use little-endian byte ordering.

## 🔧 Features

- Reads a `.tbl` file with entries in the format `XXXX=VALUE`
- Converts the hexadecimal key from **big-endian** to **little-endian**
- Outputs a new `.tbl` file with updated key order, preserving values and comments

## 📦 Usage

### Compile

```bash
gcc -o byteflip byteflip.c
```

### Run

```bash
./byteflip input.tbl output.tbl
```

- ```input.tbl```: The source table using big-endian keys (e.g., 0480=カ)

- ```output.tbl```: The destination table using little-endian keys (e.g., 8004=カ)

## 🧪 Example

### Input: ```big.tbl```

```ini
0480=タ
0481=チ
0482=ツ
```

### Output: ```little.tbl```

```ini
8004=タ
8104=チ
8204=ツ
```
## 📁 Notes

- Lines starting with # or empty lines are preserved.

- Keys are assumed to be 4-digit hexadecimal values.

## 📜 License

MIT License

```vbnet
Copyright (c) 2025 Ted Martins (http://github.com/tedmartins)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```