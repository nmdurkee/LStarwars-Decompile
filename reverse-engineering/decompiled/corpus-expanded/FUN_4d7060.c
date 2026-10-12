/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d7060; label: FUN_004d7060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d7060(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_0055f450();
  if (((*(int *)(iVar1 + 300) == 0) || (*(int *)(iVar1 + 300) != DAT_00951364)) &&
     (*(int *)(iVar1 + 0x4688) != 0)) {
    iVar4 = 0;
    if (0 < *(int *)(iVar1 + 0x468c)) {
      iVar3 = *(int *)(iVar1 + 0x4688) + 0x10;
      do {
        if (((*(char *)(param_1 + 0x14) == '\0') && (DAT_00881c38 != 0)) &&
           ((*(byte *)(iVar3 + 0x58) & 0x40) != 0)) {
          iVar2 = FUN_0041a2e0(iVar3,0x40000000,0);
          if (iVar2 != 0) {
            return 1;
          }
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x7c;
      } while (iVar4 < *(int *)(iVar1 + 0x468c));
    }
    return 0;
  }
  return 0;
}

