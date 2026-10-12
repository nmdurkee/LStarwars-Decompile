/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590980; label: FUN_00590980
 */

void FUN_00590980(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 != (int *)0x0) && ((short)param_4[1] != 0)) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = FUN_004f1ff0(*param_4 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*param_4 + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x7c;
    } while (iVar2 < (int)(uint)*(ushort *)(param_4 + 1));
  }
  return;
}

