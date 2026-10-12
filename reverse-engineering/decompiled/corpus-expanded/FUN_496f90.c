/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496f90; label: FUN_00496f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496f90(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar2 = DAT_009553d4;
  iVar1 = DAT_0087b884;
  _DAT_0087b880 = 0;
  if (DAT_009553d4 == 0) {
    return;
  }
  iVar3 = 0;
  if (*(char *)(DAT_009553d4 + 0x1c) != '\0') {
    do {
      if (iVar3 == iVar1) {
        local_4 = 0x3f800000;
      }
      else {
        local_4 = 0;
      }
      iVar3 = iVar3 + 1;
      *(undefined4 *)(&DAT_0087b78c + iVar3 * 4) = local_4;
    } while (iVar3 < (int)(uint)*(byte *)(iVar2 + 0x1c));
  }
  FUN_00496eb0(1);
  return;
}

