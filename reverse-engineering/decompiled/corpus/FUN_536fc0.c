/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x536fc0; label: FUN_00536fc0
 */

undefined4
FUN_00536fc0(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 local_c [12];
  
  if ((((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) || (*(int *)(param_3 + 0x158) == 0)) ||
     (*(int *)(param_3 + 0x15c) == 0)) {
    return 1;
  }
  if (param_6 == 0) {
    iVar3 = *(int *)(param_2 + 0x6c);
    if (iVar3 != 0) {
      fVar4 = (float10)FUN_005b3cf0(param_3 + 0x14c,iVar3 + 4,local_c);
      if (*(float *)(iVar3 + 0x14) <= (float)fVar4) {
        FUN_0052fcb0(param_3,iVar3 + 4,0,param_2 + 0x84,2,*(undefined4 *)(param_3 + 0x180));
        return 0;
      }
    }
  }
  else {
    if (param_5 == 0) {
      return 0;
    }
    iVar3 = 1;
    if (1 < param_5) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar2 = (*DAT_009238b0)(param_4[iVar3],param_3 + 0x13f), iVar2 == 0)) {
          fVar4 = (float10)FUN_00514920(param_3,param_2,param_4[iVar3]);
          *(float *)(param_3 + 0x180) = (float)fVar4;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    iVar3 = FUN_0051ad80(param_1,*(undefined4 *)(param_3 + 0x158),*param_4);
    *(int *)(param_2 + 0x6c) = iVar3;
    if ((iVar3 != 0) && (*(char *)(iVar3 + 0x28) != '\0')) {
      iVar2 = *(int *)(*(int *)(param_3 + 0x158) + 0x7c);
      FUN_0051a7c0(param_3,*(undefined4 *)(param_3 + 0x158));
      iVar1 = **(int **)(iVar3 + 0x34);
      *(int *)(param_2 + 0x88) = iVar1;
      if ((uint)*(byte *)(iVar1 + 0x10) == (iVar3 - iVar2) / 0x5c) {
        *(undefined4 *)(param_2 + 0x94) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x94) = 0x3f800000;
      }
      *(ushort *)(param_2 + 0x92) = *(ushort *)(param_2 + 0x92) | 1;
      *(undefined4 *)(param_2 + 0x98) = 0;
      *(undefined1 *)(param_2 + 0x8c) = 0;
      FUN_0052fcb0(param_3,iVar3 + 4,0,param_2 + 0x84,2,*(undefined4 *)(param_3 + 0x180));
      return 0;
    }
  }
  return 1;
}

