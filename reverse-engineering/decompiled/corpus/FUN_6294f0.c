/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6294f0; label: FUN_006294f0
 */

void FUN_006294f0(undefined4 param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  uint *puVar4;
  float *pfVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_8;
  
  pfVar5 = DAT_02912e4c;
  iVar3 = DAT_029110ac;
  pfVar2 = DAT_02910c98;
  *DAT_02910c98 = *(float *)(DAT_029110ac + 0x60);
  puVar4 = DAT_02912130;
  *pfVar5 = *(float *)(iVar3 + 100);
  fVar1 = *(float *)(iVar3 + 0x68);
  *DAT_02900a60 = fVar1;
  if (puVar4 != (uint *)0x0) {
    local_8 = (int)(longlong)ROUND(*DAT_02912e48 * 255.0);
    uVar8 = local_8 << 8;
    local_8._0_1_ = (byte)(longlong)ROUND(fVar1 * 255.0);
    uVar6 = (uint)(byte)local_8;
    local_8._0_1_ = (byte)(longlong)ROUND(*pfVar5 * 255.0);
    uVar7 = (uint)(byte)local_8;
    local_8._0_1_ = (byte)(longlong)ROUND(*pfVar2 * 255.0);
    *puVar4 = ((uVar8 | uVar6) << 8 | uVar7) << 8 | (uint)(byte)local_8;
    FUN_006279f0(param_1);
    return;
  }
  FUN_006279f0(param_1);
  return;
}

