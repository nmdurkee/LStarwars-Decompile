/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e760; label: FUN_0062e760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0062e760(int param_1,float param_2,float param_3,float param_4,int param_5,char *param_6
                    ,int param_7,float param_8)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  short in_AX;
  int unaff_EDI;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  iVar4 = in_AX * 4;
  iVar3 = *(int *)(iVar4 + *(int *)(unaff_EDI + 8));
  fVar1 = *(float *)(iVar3 + 0x18);
  fVar2 = *(float *)(iVar3 + 0x1c);
  if (0.0 < fVar2) {
    fVar2 = (param_4 / fVar2) * fVar1;
    fVar1 = *(float *)(*(int *)(*(int *)(unaff_EDI + 8) + iVar4) + 0x20);
    if (0.0 <= fVar2) {
      if ((fVar1 <= 0.0) || (fVar2 <= fVar1)) goto LAB_0062e806;
    }
    else if ((0.0 <= fVar1) || (fVar1 <= fVar2)) {
LAB_0062e806:
      fVar1 = fVar2;
    }
  }
  if (*param_6 == '\0') {
    param_3 = param_3 / 30.0;
  }
  else {
    param_3 = (param_3 * param_8) / -30.0;
  }
  param_2 = param_3 * fVar1 + param_2;
  fVar5 = (float10)FUN_005ca470(*(undefined4 *)(*(int *)(unaff_EDI + 0xc) + iVar4));
  if (0.0 <= param_3 * fVar1) {
    fVar6 = (float10)param_2;
    fVar7 = (float10)(float)fVar5;
    if (fVar6 <= fVar7) {
      return fVar6;
    }
    if ((*(byte *)(*(int *)(*(int *)(unaff_EDI + 8) + iVar4) + 4) & 2) == 0) goto LAB_0062e8ee;
    if ((float10)1 < fVar7) {
      if (fVar7 < fVar6) {
        do {
          fVar6 = (float10)(float)(fVar6 - (fVar7 - (float10)1.0));
        } while (fVar7 < fVar6);
      }
      goto LAB_0062e8c3;
    }
  }
  else {
    if (param_5 != 0) {
      *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 8;
    }
    fVar7 = (float10)1;
    fVar6 = (float10)param_2;
    if (fVar7 <= fVar6) {
      return fVar6;
    }
    if ((*(byte *)(*(int *)(*(int *)(unaff_EDI + 8) + iVar4) + 4) & 2) == 0) {
LAB_0062e8ee:
      if (param_5 != 0) {
        *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
      }
      return (float10)(float)fVar7;
    }
    fVar5 = (float10)(float)fVar5;
    if (fVar7 < fVar5) {
      do {
        fVar6 = (float10)(float)(fVar6 + (fVar5 - (float10)1.0));
      } while (fVar6 < fVar7);
      goto LAB_0062e8c3;
    }
  }
  fVar6 = (float10)1.0;
LAB_0062e8c3:
  if (param_5 != 0) {
    *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 2;
  }
  if (*param_6 == '\0') {
    if ((param_7 != 0) && ((*(byte *)(*(int *)(*(int *)(unaff_EDI + 8) + iVar4) + 4) & 0x80) != 0))
    {
      *param_6 = '\x01';
      return fVar6;
    }
  }
  else if (param_7 == 0) {
    *param_6 = '\0';
    return fVar6;
  }
  return fVar6;
}

