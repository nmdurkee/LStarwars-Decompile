/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a320; label: FUN_0061a320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061a320(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  double local_10c;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  FUN_005d0e80(DAT_02912b38);
  iVar1 = FUN_006e6b90();
  iVar1 = iVar1 >> 3;
  fVar3 = (float10)FUN_005d0e80(DAT_02912b38);
  local_10c = (double)(fVar3 * (float10)0.125);
  FUN_005d0eb0(DAT_02912b38);
  uVar2 = FUN_006e6b90();
  local_10c = (double)CONCAT44(local_10c._4_4_,uVar2);
  if (*(short *)(param_2 + 0x54) == 0) {
    if (DAT_02912eb8 == 0) {
      FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar1 * 8,
                   *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                   (&DAT_02900c70)[DAT_02912e90]);
    }
    FUN_004f2740(local_104,*(undefined4 *)(param_2 + 0x50),param_2 + 0x58);
    if (DAT_02912eb8 == 0) {
      FUN_005d0fb0(DAT_02912b38);
      if (DAT_02912eb8 == 0) {
        FUN_005d1060(DAT_02912b38,
                     *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4));
      }
    }
    FUN_00618310(DAT_02912b38,local_10c._0_4_ + param_4 * 8,"%s %s",*(undefined4 *)(param_2 + 0x24),
                 local_104);
  }
  else {
    if (DAT_02912eb8 == 0) {
      FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar1 << 4,
                   *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                   (&DAT_02900c70)[DAT_02912e90]);
      if (DAT_02912eb8 == 0) {
        FUN_005d0fb0(DAT_02912b38);
        if (DAT_02912eb8 == 0) {
          FUN_005d1060(DAT_02912b38,
                       *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4));
        }
      }
    }
    FUN_00618310(DAT_02912b38,local_10c._0_4_ + param_4 * 8,*(undefined4 *)(param_2 + 0x24));
    FUN_00618310(DAT_02912b38,local_10c._0_4_ + (param_4 + iVar1) * 8,
                 *(undefined4 *)(param_2 + 0x50),param_2 + 0x58);
  }
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

