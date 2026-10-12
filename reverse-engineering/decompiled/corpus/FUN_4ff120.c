/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff120; label: thunk_FUN_004fa610
 */

uint thunk_FUN_004fa610(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_0091ee90;
  iVar3 = DAT_0091ee88;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    DAT_0091ee90 = 0;
    if (DAT_0091ee88 != 0) {
      iVar2 = FUN_004f9aa0(DAT_0091ee88,param_1);
      if (-1 < iVar2) {
        DAT_0091ee90 = uVar1;
        return *(uint *)(*(int *)(iVar3 + 8) + 8 + iVar2 * 0x10);
      }
    }
    iVar3 = FUN_004fa3f0(param_1,0,iVar3,1);
    if (iVar3 != 0) {
      FUN_004f99e0(iVar3);
    }
    DAT_0091ee90 = uVar1;
    return (uint)(iVar3 != 0);
  }
  return 0;
}

