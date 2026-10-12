/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x455ae0; label: FUN_00455ae0
 */

undefined4
FUN_00455ae0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_6 == 0) {
    return 1;
  }
  if (param_5 == 0) {
    return 1;
  }
  iVar3 = 0;
  if (param_5 < 1) {
    return 1;
  }
  do {
    iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&PTR_s_ORM_00786158_0x15_007584a8);
    if (iVar1 != 0) {
      FUN_005147c0(param_2,iVar1 + 4);
      uVar2 = FUN_006e6b90();
      FUN_0043d500(uVar2);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < param_5);
  return 1;
}

