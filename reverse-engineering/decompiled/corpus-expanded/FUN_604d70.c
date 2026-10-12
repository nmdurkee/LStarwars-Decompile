/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604d70; label: FUN_00604d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00604d70(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    return *(int *)(in_ECX + 4);
  }
  return in_ECX + 4;
}

