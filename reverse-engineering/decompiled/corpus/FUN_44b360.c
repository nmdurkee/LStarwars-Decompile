/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x44b360; label: FUN_0044b360
 */

undefined4
FUN_0044b360(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  int local_4;
  
  local_8 = 0.0;
  iVar3 = 0;
  iVar2 = 0;
  local_4 = 0;
  if (((param_6 != 0) && (DAT_0095df4c != 0)) && (0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"value=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"increment=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"decrement=");
            if (iVar1 == 0) goto LAB_0044b434;
            fVar4 = (float10)FUN_005147c0(param_2,iVar1 + 10);
            iVar2 = -1;
          }
          else {
            fVar4 = (float10)FUN_005147c0(param_2,iVar1 + 10);
            iVar2 = 1;
          }
        }
        else {
          fVar4 = (float10)FUN_005147c0(param_2,iVar1 + 6);
        }
        local_8 = (float)fVar4;
      }
      else {
        local_4 = iVar1 + 5;
      }
LAB_0044b434:
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5);
    if ((local_4 != 0) && (iVar3 = FUN_005aac00(DAT_0095df4c,local_4,0), iVar3 != 0)) {
      if (iVar2 == -1) {
        *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) - local_8;
      }
      else {
        if (iVar2 == 0) {
          *(float *)(iVar3 + 0x28) = local_8;
          return 1;
        }
        if (iVar2 == 1) {
          *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + local_8;
          return 1;
        }
      }
    }
  }
  return 1;
}

