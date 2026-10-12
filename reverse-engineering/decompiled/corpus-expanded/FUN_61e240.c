/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61e240; label: FUN_0061e240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061e240(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  float10 fVar4;
  double local_20c;
  undefined1 local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20c;
  FUN_005d0e80();
  iVar1 = FUN_006e6b90();
  fVar4 = (float10)FUN_005d0e80(DAT_02912b38);
  local_20c = (double)(fVar4 * (float10)0.125);
  FUN_005d0eb0(DAT_02912b38);
  uVar2 = FUN_006e6b90();
  bVar3 = DAT_02912eb8 == 0;
  local_20c = (double)CONCAT44(local_20c._4_4_,uVar2);
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (bVar3) {
    FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,(iVar1 >> 3) * 8,
                 *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                 (&DAT_02900c70)[DAT_02912e90]);
    if (DAT_02912eb8 == 0) {
      FUN_005d0fb0();
      if (DAT_02912eb8 == 0) {
        FUN_005d1060(DAT_02912b38,
                     *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4));
      }
    }
  }
  FUN_004f1f10(local_204,*(undefined4 *)(param_2 + 0x24));
  FUN_004f1e80(local_204,*(undefined4 *)(param_2 + 100));
  FUN_00618310(DAT_02912b38,local_20c._0_4_ + param_4 * 8,local_204,
               (double)*(float *)(param_2 + 0x54));
  __security_check_cookie(local_4 ^ (uint)&local_20c);
  return;
}

