/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654ef0; label: FUN_00654ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00654ef0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  DAT_00810960 = DAT_00810960 + -1;
  if (DAT_00810960 < 1) {
    iVar3 = (&DAT_0292fd30)[DAT_029620bc];
    DAT_00810960 = 6;
    iVar2 = DAT_029620bc;
    while (iVar3 == 0) {
      iVar2 = iVar2 + 1;
      if (4 < iVar2) {
        iVar2 = 0;
      }
      if (iVar2 == DAT_029620bc) break;
      iVar3 = (&DAT_0292fd30)[iVar2];
    }
    DAT_029620bc = iVar2;
    piVar1 = &DAT_0292fd30 + DAT_029620bc;
    iVar3 = *piVar1;
    if (iVar3 != 0) {
      while (iVar2 = *(int *)(iVar3 + 0x5c), iVar2 != 0) {
        if ((*(ushort *)(iVar3 + 0x60) < *(ushort *)(iVar2 + 0x60)) ||
           ((*(ushort *)(iVar3 + 0x60) == *(ushort *)(iVar2 + 0x60) &&
            (*(char *)(*(int *)(iVar2 + 4) + 0x2e) < *(char *)(*(int *)(iVar3 + 4) + 0x2e))))) {
          if (iVar2 == 0) {
            DAT_00810960 = 6;
            return;
          }
          FUN_00654ea0(iVar2,piVar1);
          FUN_00654e00(iVar2,piVar1);
          return;
        }
        iVar3 = iVar2;
        if (iVar2 == 0) {
          return;
        }
      }
    }
  }
  return;
}

