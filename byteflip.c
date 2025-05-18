#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LINE 256

// Swap endianness: converts big-endian to little-endian (or vice versa)
uint16_t swap_endian(uint16_t val)
{
  return (val >> 8) | (val << 8);
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <input_big.tbl> <output_little.tbl>\n", argv[0]);
    return 1;
  }

  FILE *fin = fopen(argv[1], "r");
  if (!fin)
  {
    perror("Error opening input file");
    return 1;
  }

  FILE *fout = fopen(argv[2], "w");
  if (!fout)
  {
    perror("Error creating output file");
    fclose(fin);
    return 1;
  }

  char line[MAX_LINE];
  while (fgets(line, sizeof(line), fin))
  {
    // Skip comments and invalid lines
    if (line[0] == '#' || line[0] == '\n' || strchr(line, '=') == NULL)
    {
      fputs(line, fout);
      continue;
    }

    // Split line into key and value
    char *eq = strchr(line, '=');
    *eq = '\0';
    uint16_t be_val = (uint16_t)strtol(line, NULL, 16);
    uint16_t le_val = swap_endian(be_val);
    char *val = eq + 1;
    val[strcspn(val, "\r\n")] = '\0';

    // Write swapped key and original value
    fprintf(fout, "%04X=%s\n", le_val, val);
  }

  fclose(fin);
  fclose(fout);

  printf("Conversion completed. Output saved to: %s\n", argv[2]);
  return 0;
}