/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604cd0; label: FUN_00604cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00604cd0(int param_1)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(int *)(in_ECX + 4) == *(int *)(param_1 + 4));
}

