/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745de0; label: FUN_00745de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745de0(int param_1,int param_2,int param_3,void *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = param_1 * 0x5c;
  if (*(int *)(*(int *)(in_ECX + 0x7918c) + 0xb80) != 4) {
    if ((*(int *)(&DAT_0082b1e8 + iVar4) != 0) || (iVar1 = FUN_00741610(), iVar1 == 0)) {
      if (*(int *)(&DAT_0082b1d8 + iVar4) < 5) {
        _memcpy((void *)(iVar4 + 0x82b1ec),param_4,*(int *)(&DAT_0082b1d8 + iVar4) << 4);
      }
      else {
        FUN_00741610();
      }
    }
    if ((((*(int *)(&DAT_0082b1e8 + iVar4) == 0) || (*(int *)(&DAT_0082b1e8 + iVar4) == 2)) &&
        (iVar4 = FUN_00741610(), iVar4 != 0)) &&
       (iVar4 = FUN_00741610(), -1 < *(short *)(iVar4 + 0x1c + param_1 * 0xc))) {
      uVar2 = FUN_00741610(param_1,param_2,param_3,param_4);
      FUN_007440e0(uVar2);
      return;
    }
    return;
  }
  uVar3 = (&DAT_0082b1e0)[param_1 * 0x17] & 3;
  if (uVar3 == 1) {
    FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_4,
                 *(int *)(&DAT_0082b1dc + iVar4) * param_3);
    return;
  }
  if (uVar3 != 2) {
    if (uVar3 != 3) {
      return;
    }
    FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_4,
                 *(int *)(&DAT_0082b1dc + iVar4) * param_3);
    FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_4,
                 *(int *)(&DAT_0082b1dc + iVar4) * param_3);
    return;
  }
  FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_4,
               *(int *)(&DAT_0082b1dc + iVar4) * param_3);
  return;
}

