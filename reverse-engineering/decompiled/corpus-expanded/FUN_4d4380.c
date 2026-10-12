/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d4380; label: FUN_004d4380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d4380(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (DAT_00881c30 != 0)) && (DAT_00881ae8 != 0)) {
    iVar3 = 0;
    if ('\0' < *(char *)(DAT_00881ae8 + 0x77e1)) {
      iVar4 = 0;
      do {
        uVar1 = FUN_005cfa50(iVar4 + 0x5000 + DAT_00881ae8);
        iVar2 = FUN_004f8b10(param_1,uVar1);
        if (iVar2 == 0) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar3 < *(char *)(DAT_00881ae8 + 0x77e1));
    }
    if (*(char *)(DAT_00881ae8 + 0x77e1) < '\x10') {
      iVar4 = FUN_005cf5b0(*(undefined4 *)(DAT_00881c30 + 0x13c),
                           DAT_00881ae8 + 0x5000 + *(char *)(DAT_00881ae8 + 0x77e1) * 0xc,param_1,1)
      ;
      iVar3 = DAT_00881ae8;
      if (iVar4 != 0) {
        *(char *)(DAT_00881ae8 + 0x77e1) = *(char *)(DAT_00881ae8 + 0x77e1) + '\x01';
        return *(char *)(iVar3 + 0x77e1) + -1;
      }
    }
  }
  return -1;
}

