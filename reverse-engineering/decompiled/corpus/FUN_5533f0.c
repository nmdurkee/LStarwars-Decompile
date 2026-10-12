/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x5533f0; label: FUN_005533f0
 */

void FUN_005533f0(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = CONCAT44(param_3,param_2);
  if ((param_4 != 0) && (DAT_00951154 == 0)) {
    iVar1 = FUN_0056e0f0(4);
    if (iVar1 != 0) {
      lVar3 = __allmul(param_2,param_3,2,0);
    }
    iVar1 = FUN_0056e0f0(8);
    if (iVar1 != 0) {
      lVar3 = __allmul(lVar3,4,0);
    }
    iVar1 = FUN_0056e0f0(0x10);
    if (iVar1 != 0) {
      lVar3 = __allmul(lVar3,6,0);
    }
    iVar1 = FUN_0056e0f0(0x20);
    if (iVar1 != 0) {
      lVar3 = __allmul(lVar3,8,0);
    }
    iVar1 = FUN_0056e0f0(0x40);
    if (iVar1 != 0) {
      lVar3 = __allmul(lVar3,10,0);
    }
  }
  uVar2 = (uint)(lVar3 + (ulonglong)*param_1);
  if (((int)(lVar3 + (ulonglong)*param_1 >> 0x20) != 0) || (4000000000 < uVar2)) {
    uVar2 = 4000000000;
  }
  *param_1 = uVar2;
  return;
}

