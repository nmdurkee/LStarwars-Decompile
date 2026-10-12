/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x6740c0; label: FUN_006740c0
 */

undefined4 FUN_006740c0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_ECX;
  float10 fVar6;
  
  iVar4 = param_1 * 0xc;
  if ((*(float *)(iVar4 + 0x104 + DAT_0292186c) < -*(float *)(DAT_0292186c + 0x50)) ||
     (*(float *)(DAT_0292186c + 0x4c) + *(float *)(DAT_0292186c + 0x50) <
      *(float *)(iVar4 + 0x104 + DAT_0292186c))) {
    return 0;
  }
  iVar5 = (param_1 * 3 + 0x3f) * 4;
  fVar1 = *(float *)(iVar4 + 0x100 + DAT_0292186c);
  fVar1 = fVar1 * fVar1 + *(float *)(iVar5 + DAT_0292186c) * *(float *)(iVar5 + DAT_0292186c);
  if (fVar1 <= *(float *)(DAT_0292186c + 0x54)) {
    fVar6 = (float10)FUN_005c0240(*(float *)(DAT_0292186c + 0x54) - fVar1);
    iVar3 = DAT_0292186c;
    fVar2 = *(float *)(iVar4 + 0x104 + DAT_0292186c) - (float)fVar6;
    if ((fVar2 < 0.0) || (*(float *)(DAT_0292186c + 0x4c) < fVar2)) {
      fVar2 = *(float *)(iVar4 + 0x104 + DAT_0292186c);
      fVar1 = fVar2 * fVar2 + fVar1;
      if (fVar1 < *(float *)(DAT_0292186c + 0x54)) {
        fVar6 = (float10)FUN_005c0240(fVar1);
        fVar1 = (float)fVar6 - *(float *)(DAT_0292186c + 0x50);
        if ((fVar1 < *(float *)(DAT_0292186c + 0x98)) &&
           (iVar3 = *(int *)(DAT_0292186c + 0x94),
           0.0 < (*(float *)(DAT_0292186c + 0x78) - *(float *)(iVar3 + 0x20 + iVar4)) *
                 *(float *)(iVar3 + 0x50) +
                 (*(float *)(DAT_0292186c + 0x74) - *(float *)(iVar3 + 0x1c + iVar4)) *
                 *(float *)(iVar3 + 0x4c) +
                 (*(float *)(DAT_0292186c + 0x70) - *(float *)(iVar3 + (param_1 * 3 + 6) * 4)) *
                 *(float *)(iVar3 + 0x48))) {
          *(float *)(DAT_0292186c + 0x98) = fVar1;
          fVar6 = (float10)FUN_0064fde0(0x3f800000,(float)fVar6);
          fVar1 = (float)fVar6;
          *(undefined1 *)(extraout_ECX + 0x88) = 0x13;
          *(float *)(extraout_ECX + 0xa8) = fVar1 * -*(float *)(iVar5 + extraout_ECX);
          *(float *)(extraout_ECX + 0xac) = -*(float *)(iVar4 + 0x100 + extraout_ECX) * fVar1;
          *(float *)(extraout_ECX + 0xb0) = -*(float *)(iVar4 + 0x104 + extraout_ECX) * fVar1;
          return 1;
        }
      }
    }
    else {
      fVar2 = fVar2 / *(float *)(DAT_0292186c + 0x4c);
      if (fVar2 < *(float *)(DAT_0292186c + 0x98)) {
        *(float *)(DAT_0292186c + 0x98) = fVar2;
        *(undefined1 *)(iVar3 + 0x88) = 3;
        *(float *)(iVar3 + 0xa8) = -*(float *)(iVar5 + iVar3);
        *(float *)(iVar3 + 0xac) = -*(float *)(iVar4 + 0x100 + iVar3);
        *(float *)(iVar3 + 0xb0) = -(float)fVar6;
        return 1;
      }
    }
  }
  return 0;
}

