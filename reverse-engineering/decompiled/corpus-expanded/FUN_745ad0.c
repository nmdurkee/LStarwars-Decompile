/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745ad0; label: FUN_00745ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745ad0(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined1 local_40 [64];
  
  iVar4 = param_1 * 0x5c;
  if (*(int *)(*(int *)(in_ECX + 0x7918c) + 0xb80) == 4) {
    if (*(int *)(&DAT_0082b1dc + iVar4) == 4) {
      FUN_005b59a0(local_40,param_3);
      param_3 = local_40;
    }
    uVar3 = (&DAT_0082b1e0)[param_1 * 0x17] & 3;
    if (uVar3 == 1) {
      FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_3,
                   *(undefined4 *)(&DAT_0082b1dc + iVar4));
      return;
    }
    if (uVar3 == 2) {
      FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_3,
                   *(undefined4 *)(&DAT_0082b1dc + iVar4));
      return;
    }
    if (uVar3 == 3) {
      FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_3,
                   *(undefined4 *)(&DAT_0082b1dc + iVar4));
      FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17] + param_2,param_3,
                   *(undefined4 *)(&DAT_0082b1dc + iVar4));
      return;
    }
  }
  else {
    if ((*(int *)(&DAT_0082b1e8 + iVar4) != 0) || (iVar1 = FUN_00741610(), iVar1 == 0)) {
      if (*(int *)(&DAT_0082b1d8 + iVar4) < 5) {
        _memcpy((void *)(iVar4 + 0x82b1ec),param_3,*(int *)(&DAT_0082b1d8 + iVar4) << 4);
      }
      else {
        FUN_00741610();
      }
    }
    if ((((*(int *)(&DAT_0082b1e8 + iVar4) == 0) || (*(int *)(&DAT_0082b1e8 + iVar4) == 2)) &&
        (iVar4 = FUN_00741610(), iVar4 != 0)) &&
       (iVar4 = FUN_00741610(), -1 < *(short *)(iVar4 + 0x1c + param_1 * 0xc))) {
      uVar2 = FUN_00741610(param_1,param_2,1,param_3);
      FUN_00744060(uVar2);
    }
  }
  return;
}

