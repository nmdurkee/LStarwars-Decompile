/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623b70; label: FUN_00623b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00623b70(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  uint *puVar8;
  float *pfVar9;
  uint uVar10;
  float *extraout_ECX;
  uint uVar11;
  uint uVar12;
  undefined4 local_8;
  
  pfVar9 = DAT_02912e4c;
  pfVar6 = DAT_02910c98;
  fVar2 = _DAT_0080fafc;
  *DAT_02910c98 = _DAT_0080fafc;
  pfVar5 = DAT_02900a60;
  fVar3 = _DAT_0080fb00;
  *pfVar9 = _DAT_0080fb00;
  puVar8 = DAT_02912130;
  fVar4 = _DAT_0080fb04;
  *pfVar5 = _DAT_0080fb04;
  if (puVar8 != (uint *)0x0) {
    local_8 = (int)(longlong)ROUND(*DAT_02912e48 * 255.0);
    uVar12 = local_8 << 8;
    local_8._0_1_ = (byte)(longlong)ROUND(fVar4 * 255.0);
    uVar10 = (uint)(byte)local_8;
    local_8._0_1_ = (byte)(longlong)ROUND(*pfVar9 * 255.0);
    uVar11 = (uint)(byte)local_8;
    local_8._0_1_ = (byte)(longlong)ROUND(*pfVar6 * 255.0);
    *puVar8 = ((uVar12 | uVar10) << 8 | uVar11) << 8 | (uint)(byte)local_8;
  }
  iVar7 = DAT_029110ac;
  puVar1 = (undefined4 *)(DAT_029110ac + 0x5c);
  FUN_00618000(fVar2,fVar3,fVar4,puVar1);
  *(float *)(iVar7 + 0x4c) = *extraout_ECX / 360.0;
  *(undefined4 *)(iVar7 + 0x50) = *puVar1;
  return;
}

