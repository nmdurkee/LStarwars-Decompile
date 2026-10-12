/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6af2a0; label: FUN_006af2a0
 */

void FUN_006af2a0(int *param_1,int param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  
  iVar11 = (int)(param_2 + (param_2 >> 0x1f & 3U)) >> 2;
  pvVar1 = _malloc(iVar11 * 4);
  pvVar2 = _malloc((iVar11 + param_2) * 4);
  fVar12 = (float10)FUN_006e9040();
  fVar13 = (float10)FUN_006e9040();
  FUN_006eafc0((double)((float10)(double)fVar12 / fVar13 + (float10)0.5));
  iVar3 = FUN_006e6b90();
  param_1[3] = (int)pvVar1;
  iVar9 = 0;
  param_1[1] = iVar3;
  *param_1 = param_2;
  param_1[2] = (int)pvVar2;
  if (0 < iVar11) {
    pfVar7 = (float *)((int)pvVar2 + (param_2 >> 1) * 4);
    do {
      fVar12 = (float10)FUN_006ebcb0();
      *(float *)((int)pvVar2 + iVar9 * 8) = (float)fVar12;
      fVar12 = (float10)FUN_006e8e80();
      *(float *)((int)pvVar2 + iVar9 * 8 + 4) = (float)-fVar12;
      fVar12 = (float10)FUN_006ebcb0();
      *pfVar7 = (float)fVar12;
      fVar12 = (float10)FUN_006e8e80();
      pfVar7[1] = (float)fVar12;
      iVar9 = iVar9 + 1;
      pfVar7 = pfVar7 + 2;
    } while (iVar9 < iVar11);
  }
  iVar9 = (int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3;
  if (0 < iVar9) {
    pfVar7 = (float *)((int)pvVar2 + param_2 * 4);
    iVar11 = iVar9;
    do {
      fVar12 = (float10)FUN_006ebcb0();
      *pfVar7 = (float)(fVar12 * (float10)0.5);
      fVar12 = (float10)FUN_006e8e80();
      iVar11 = iVar11 + -1;
      pfVar7[1] = (float)(fVar12 * (float10)-0.5);
      pfVar7 = pfVar7 + 2;
    } while (iVar11 != 0);
  }
  uVar10 = 1 << ((char)iVar3 - 2U & 0x1f);
  uVar6 = 0;
  if (0 < iVar9) {
    do {
      uVar8 = 0;
      bVar5 = 0;
      uVar4 = uVar10;
      while (uVar4 != 0) {
        if ((uVar6 & uVar4) != 0) {
          uVar8 = uVar8 | 1 << (bVar5 & 0x1f);
        }
        bVar5 = bVar5 + 1;
        uVar4 = (int)uVar10 >> (bVar5 & 0x1f);
      }
      *(uint *)((int)pvVar1 + uVar6 * 8) = (~uVar8 & (1 << ((char)iVar3 - 1U & 0x1f)) - 1U) - 1;
      *(uint *)((int)pvVar1 + uVar6 * 8 + 4) = uVar8;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < iVar9);
  }
  param_1[4] = (int)(4.0 / (float)param_2);
  return;
}

