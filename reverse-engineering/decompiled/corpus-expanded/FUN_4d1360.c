/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d1360; label: FUN_004d1360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d1360(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 uVar6;
  short sVar7;
  int unaff_EDI;
  float10 fVar8;
  float local_1c;
  undefined1 local_c [12];
  
  if ((*(float *)(*(int *)(unaff_EDI + 0xca4) + 0x28) <= 0.0) ||
     (*(short *)(unaff_EDI + 0x7aa) == 0x8f)) {
LAB_004d14f0:
    if (param_1 != 0) {
      return 1;
    }
    *(undefined2 *)(unaff_EDI + 0x7aa) = 0x88;
    return 1;
  }
  fVar2 = *(float *)(unaff_EDI + 0x754);
  fVar3 = *(float *)(unaff_EDI + 0x758);
  pfVar1 = (float *)(unaff_EDI + 0x754);
  fVar4 = *(float *)(unaff_EDI + 0x75c);
  uVar5 = (uint)*(ushort *)(*(int *)(unaff_EDI + 0x798) + 0x44);
  uVar6 = FUN_0054b3d0();
  fVar8 = (float10)FUN_00550180(uVar6,uVar5);
  if ((float)fVar8 <= DAT_029959a0) {
    if (-DAT_029959a0 <= (float)fVar8) goto LAB_004d14f0;
    local_1c = -1.0;
    if (param_1 == 0) {
      sVar7 = *(short *)(*(int *)(unaff_EDI + 0x798) + 0x44) + -0x8000;
      goto LAB_004d1402;
    }
  }
  else {
    local_1c = 1.0;
    if (param_1 == 0) {
      sVar7 = *(short *)(*(int *)(unaff_EDI + 0x798) + 0x44);
LAB_004d1402:
      *(short *)(unaff_EDI + 0x5a) = sVar7;
      *(undefined2 *)(unaff_EDI + 0x7aa) = 0x89;
      fVar8 = (float10)FUN_0062f1c0(*(undefined4 *)(unaff_EDI + 0x50),0x89);
      goto LAB_004d1456;
    }
  }
  fVar8 = (float10)0.6;
LAB_004d1456:
  FUN_005b3830(local_c,*(int *)(unaff_EDI + 0x798) + 0x34,(float)fVar8 * local_1c * _DAT_00925018);
  FUN_005b37d0(pfVar1,pfVar1,local_c);
  uVar6 = FUN_004d12a0();
  if ((((param_1 == 0) && (fVar2 == *pfVar1)) && (fVar3 == *(float *)(unaff_EDI + 0x758))) &&
     (fVar4 == *(float *)(unaff_EDI + 0x75c))) {
    *(undefined2 *)(unaff_EDI + 0x7aa) = 0x88;
    return uVar6;
  }
  return uVar6;
}

