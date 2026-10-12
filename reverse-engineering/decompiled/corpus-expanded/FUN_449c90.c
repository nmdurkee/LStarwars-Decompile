/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449c90; label: FUN_00449c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00449c90(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0x144) != 0)) {
    puVar1 = (uint *)(*(int *)(param_3 + 0x144) + 0x50);
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  return 1;
}

