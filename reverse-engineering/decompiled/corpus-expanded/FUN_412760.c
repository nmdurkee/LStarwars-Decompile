/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x412760; label: FUN_00412760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00412760(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *in_EAX;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  float *in_ECX;
  int unaff_ESI;
  float10 fVar13;
  char *pcVar14;
  
  pfVar1 = (float *)(unaff_ESI + 0x30);
  fVar2 = *in_ECX - *pfVar1;
  fVar3 = in_ECX[1] - *(float *)(unaff_ESI + 0x34);
  fVar4 = in_ECX[2] - *(float *)(unaff_ESI + 0x38);
  fVar5 = *in_EAX - *(float *)(unaff_ESI + 0x60);
  fVar6 = in_EAX[1] - *(float *)(unaff_ESI + 100);
  fVar7 = in_EAX[2] - *(float *)(unaff_ESI + 0x68);
  fVar9 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;
  fVar8 = fVar2 * fVar5 + fVar3 * fVar6 + fVar4 * fVar7;
  fVar8 = fVar8 + fVar8;
  fVar2 = (fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4) - _DAT_007f15d8;
  if (0.0 < fVar9) {
    fVar2 = fVar8 * fVar8 - fVar9 * 4.0 * fVar2;
    if (fVar2 < 0.0) {
      return 0;
    }
    fVar13 = (float10)FUN_005c0240(fVar2);
    fVar2 = (-fVar8 - (float)fVar13) / (fVar9 + fVar9);
    fVar4 = -_DAT_00925018;
    fVar3 = ((float)fVar13 - fVar8) / (fVar9 + fVar9);
    if (fVar4 < fVar3 == (fVar4 == fVar3)) {
      return 0;
    }
    if (fVar2 < 0.0 == (fVar2 == 0.0)) {
      return 0;
    }
    if (fVar2 < fVar4) {
      fVar2 = fVar4;
    }
    *in_ECX = *in_ECX + fVar5 * fVar2;
    in_ECX[1] = in_ECX[1] + fVar6 * fVar2;
    in_ECX[2] = in_ECX[2] + fVar2 * fVar7;
  }
  else if (0.0 < fVar2) {
    return 0;
  }
  if ((*(int *)(unaff_ESI + 0xd4) == 0) ||
     ((iVar10 = *(int *)(*(int *)(unaff_ESI + 0xd4) + 0x524), iVar10 != 0x55 && (iVar10 != 0x54))))
  {
    (**(code **)(PTR_PTR_008040bc + 0xc))(param_1);
    *(undefined1 *)(param_1 + 0x100) = 0;
    iVar10 = FUN_004126b0();
    if (iVar10 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = (-(uint)(*(short *)(unaff_ESI + 0xfe) != -299) & 500) + 500;
    }
    if (*(int *)(param_1 + 4) == 0) {
      iVar11 = -1;
    }
    else {
      iVar11 = (int)*(char *)(*(int *)(param_1 + 4) + 0x280);
    }
    uVar12 = FUN_0046c4f0(0,0,pfVar1,0,0x40000000,iVar11,0x3f800000,0x49f42400,0,1,1);
    FUN_0046d270(iVar10,uVar12);
    uVar12 = FUN_0064afd0("DogBits",pfVar1,1);
    FUN_0064b370(uVar12);
    fVar2 = *(float *)(unaff_ESI + 0x34) - DAT_0097371c;
    fVar3 = *(float *)(unaff_ESI + 0x38) - DAT_00973720;
    if (fVar3 * fVar3 + (*pfVar1 - DAT_00973718) * (*pfVar1 - DAT_00973718) + fVar2 * fVar2 <
        40000.0) {
      if (*(int *)(unaff_ESI + 0x10c) < 1) {
        pcVar14 = "Ep3_1_ExplosionXXL";
      }
      else if (*(short *)(unaff_ESI + 0xfe) == -299) {
        pcVar14 = "Dog_TriFighterHit";
      }
      else {
        if (1 < (int)*(short *)(unaff_ESI + 0xfe) + 0x12aU) goto LAB_00412a7d;
        pcVar14 = "Dog_DroidFighterHit";
      }
      FUN_00681f40(pcVar14,pfVar1);
    }
  }
LAB_00412a7d:
  *(int *)(unaff_ESI + 0x118) = *(int *)(unaff_ESI + 0x118) + 1;
  return 1;
}

