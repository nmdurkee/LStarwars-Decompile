/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7459a0; label: FUN_007459a0
 */

void FUN_007459a0(int param_1,undefined1 *param_2)

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
      FUN_005b59a0(local_40,param_2);
      param_2 = local_40;
    }
    uVar3 = (&DAT_0082b1e0)[param_1 * 0x17] & 3;
    if (uVar3 == 1) {
      FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17],param_2,*(undefined4 *)(&DAT_0082b1d8 + iVar4));
      return;
    }
    if (uVar3 == 2) {
      FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17],param_2,*(undefined4 *)(&DAT_0082b1d8 + iVar4));
      return;
    }
    if (uVar3 == 3) {
      FUN_006e5750((&DAT_0082b1e4)[param_1 * 0x17],param_2,*(undefined4 *)(&DAT_0082b1d8 + iVar4));
      FUN_006e52e0((&DAT_0082b1e4)[param_1 * 0x17],param_2,*(undefined4 *)(&DAT_0082b1d8 + iVar4));
      return;
    }
  }
  else {
    if ((*(int *)(&DAT_0082b1e8 + iVar4) != 0) || (iVar1 = FUN_00741610(), iVar1 == 0)) {
      if (*(int *)(&DAT_0082b1d8 + iVar4) < 5) {
        _memcpy((void *)(iVar4 + 0x82b1ec),param_2,*(int *)(&DAT_0082b1d8 + iVar4) << 4);
      }
      else {
        FUN_00741610();
      }
    }
    if ((((*(int *)(&DAT_0082b1e8 + iVar4) == 0) || (*(int *)(&DAT_0082b1e8 + iVar4) == 2)) &&
        (iVar4 = FUN_00741610(), iVar4 != 0)) &&
       (iVar4 = FUN_00741610(), -1 < *(short *)(iVar4 + 0x1c + param_1 * 0xc))) {
      uVar2 = FUN_00741610(param_1,0,1,param_2);
      FUN_00744060(uVar2);
    }
  }
  return;
}

