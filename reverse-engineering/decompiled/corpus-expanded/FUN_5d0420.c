/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0420; label: FUN_005d0420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d0420(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    return *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + 0x48);
  }
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc4), iVar1 == -1)
      ) || (iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

