/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5af100; label: FUN_005af100
 */

void FUN_005af100(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (iVar1 = *(int *)(param_3 + 0x13c), iVar1 != 0)) &&
     (iVar2 = 0, 0 < *(int *)(iVar1 + 0x6c))) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar1 + 0x70) + iVar3;
      if (*(char *)(iVar1 + 0x1a) != '\0') {
        FUN_00559ee0(param_1,param_2,0,iVar1);
      }
      iVar1 = *(int *)(param_3 + 0x13c);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < *(int *)(iVar1 + 0x6c));
  }
  return;
}

