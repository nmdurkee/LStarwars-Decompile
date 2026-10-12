/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54df70; label: FUN_0054df70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054df70(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x1e) & 2) != 0) && ((*(byte *)(iVar1 + 0x1e) & 1) != 0)) {
    if (param_2 == 1) {
      iVar1 = FUN_0054d410(iVar1,0,0);
    }
    else {
      if (param_2 != 2) {
        return 1;
      }
      iVar1 = FUN_0054d410(iVar1,0,0);
    }
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

