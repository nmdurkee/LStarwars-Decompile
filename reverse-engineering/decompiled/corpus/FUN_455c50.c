/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x455c50; label: FUN_00455c50
 */

undefined4
FUN_00455c50(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (param_6 == 0) {
    return 1;
  }
  iVar2 = 0;
  if (param_5 < 1) {
    return 1;
  }
  do {
    iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_007584b0);
    if (iVar1 != 0) {
      fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 5);
      FUN_0043d560((float)fVar3);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < param_5);
  return 1;
}

