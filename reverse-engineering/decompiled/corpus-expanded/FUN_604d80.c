/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604d80; label: FUN_00604d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00604d80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4) >> 3;
}

