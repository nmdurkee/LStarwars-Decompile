/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x5545a0; label: FUN_005545a0
 */

int FUN_005545a0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar5 = 0;
    if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0') {
      iVar3 = 0;
      do {
        iVar4 = *(int *)(param_1 + 0x46e0) + iVar3;
        if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0xac) & 1) != 0)) {
          uVar1 = FUN_005cfa50(iVar4 + 0x50,param_2);
          iVar2 = FUN_004f20f0(uVar1);
          if (iVar2 == 0) {
            return iVar4;
          }
        }
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 0x304;
      } while (iVar5 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
    }
    return 0;
  }
  return 0;
}

