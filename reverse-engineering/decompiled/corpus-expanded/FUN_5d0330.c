/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0330; label: FUN_005d0330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d0330(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0xc4);
      if ((iVar2 == -1) || (iVar2 == 0)) {
        return iVar1 + 0x40;
      }
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x40);
    if (*(int *)(iVar2 + 0x48) != 0) {
      return *(int *)(iVar2 + 0x48);
    }
  }
  return iVar2;
}

