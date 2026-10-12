/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604c50; label: FUN_00604c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00604c50(int param_1,byte param_2)

{
  byte bVar1;
  
  if (((int)(uint)param_2 < *(int *)(param_1 + 0x188)) &&
     (bVar1 = *(byte *)((uint)param_2 + *(int *)(param_1 + 0x18c)), bVar1 != 0xff)) {
    return (uint)bVar1 * 0x50 + *(int *)(param_1 + 0x184);
  }
  return 0;
}

