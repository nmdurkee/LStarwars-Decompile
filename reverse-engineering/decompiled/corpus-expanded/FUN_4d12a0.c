/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d12a0; label: FUN_004d12a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d12a0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int unaff_ESI;
  undefined4 uVar4;
  float10 fVar5;
  
  FUN_005b3800();
  fVar5 = (float10)FUN_005b39e0();
  fVar1 = (float)fVar5;
  *(float *)(unaff_ESI + 8) = fVar1;
  if (param_1 == 0) {
    fVar2 = 0.1;
  }
  else if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x10000000) == 0) {
    fVar2 = *(float *)(param_1 + 0x1dc);
  }
  else {
    fVar2 = *(float *)(param_1 + 0x1e0);
  }
  fVar3 = *(float *)(in_EAX + 0x40) - fVar2;
  if (fVar1 <= fVar3) {
    if (fVar2 <= fVar1) {
      uVar4 = 1;
    }
    else {
      *(float *)(unaff_ESI + 8) = fVar2;
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
    *(float *)(unaff_ESI + 8) = fVar3;
  }
  FUN_005b3830();
  FUN_005b37d0();
  return uVar4;
}

