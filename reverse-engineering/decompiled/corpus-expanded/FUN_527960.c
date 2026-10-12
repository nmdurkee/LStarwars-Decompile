/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527960; label: FUN_00527960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00527960(void)

{
  float fVar1;
  int iVar2;
  float *in_ECX;
  int unaff_ESI;
  float fVar3;
  float fVar4;
  float local_18 [3];
  float local_c [2];
  undefined4 local_4;
  
  if (*(float *)(unaff_ESI + 0x40) <= *(float *)(unaff_ESI + 0x44)) {
    fVar4 = *(float *)(unaff_ESI + 0x44);
  }
  else {
    fVar4 = *(float *)(unaff_ESI + 0x40);
  }
  local_18[0] = *in_ECX - *(float *)(unaff_ESI + 8);
  if (local_18[0] <= fVar4) {
    if ((local_18[0] < -fVar4) ||
       (local_18[2] = in_ECX[2] - *(float *)(unaff_ESI + 0x10), fVar4 < local_18[2])) {
      return 0;
    }
    if ((-fVar4 <= local_18[2]) &&
       (fVar3 = local_18[2] * local_18[2] + local_18[0] * local_18[0], fVar3 < fVar4 * fVar4)) {
      fVar4 = *(float *)(unaff_ESI + 0x44) / *(float *)(unaff_ESI + 0x40);
      local_18[1] = 0.0;
      FUN_005b3620(local_c,local_18,-*(int *)(unaff_ESI + 0x3c),fVar3,fVar4);
      iVar2 = FUN_005be2d0(local_c[0] * fVar4,local_4);
      fVar4 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * *(float *)(unaff_ESI + 0x40);
      fVar1 = (float)(&DAT_029899a0)[iVar2 + 0x4000 >> 1 & 0x7fff] * *(float *)(unaff_ESI + 0x44);
      if (fVar3 < fVar4 * fVar4 + fVar1 * fVar1) {
        return 1;
      }
    }
  }
  return 0;
}

