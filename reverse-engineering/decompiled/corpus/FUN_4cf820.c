/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4cf820; label: FUN_004cf820
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cf820(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  
  uVar3 = *(uint *)(param_1 + 0x144);
  if ((uVar3 & 0x4000) == 0) {
    if ((uVar3 & 2) == 0) goto LAB_004cf87c;
    if ((0.0 < *(float *)(param_1 + 0x100)) && (*(float *)(param_1 + 0x100) < 1.0)) {
      FUN_00681f40("ThermalDet_Beep",param_1 + 0x30);
      *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 0x4000;
      return;
    }
  }
  if ((uVar3 & 2) != 0) {
    return;
  }
LAB_004cf87c:
  *(uint *)(param_1 + 0x144) = uVar3 & 0xfffdffff;
  FUN_0067a6d0();
  fVar4 = (float10)FUN_005506f0(0,param_1 + 0x30,0x40a00000,0xffffffff);
  fVar1 = (float)fVar4;
  if (fVar1 != 2e+06) {
    if (((fVar1 < *(float *)(param_1 + 0x34)) && (iVar2 = FUN_0067a600(), iVar2 + 1U < 0x12)) &&
       (((&DAT_008034cc)[iVar2 * 0xc] & 2) != 0)) {
      *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 0x20000;
      *(float *)(param_1 + 0x21c) = fVar1;
    }
    fVar1 = _DAT_02920d84;
    if ((_DAT_02920d84 != 2e+06) && (uVar3 = FUN_0067a670(), uVar3 < 0x11)) {
      if ((((*(uint *)(param_1 + 0x144) & 0x8000) == 0) &&
          (*(float *)(param_1 + 0xe0) + *(float *)(param_1 + 0x34) < fVar1)) &&
         (((((&DAT_0080364c)[uVar3 * 0xc] & 1) != 0 || (uVar3 == 1)) || (uVar3 == 9)))) {
        *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 0x8000;
      }
      if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1a4) && (PTR_DAT_008021b4[1] == '\x02')) {
        fVar4 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x80),0,0x40400000);
        *(float *)(param_1 + 0x80) = (float)fVar4;
        fVar4 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x88),0,0x40400000);
        *(float *)(param_1 + 0x88) = (float)fVar4;
        return;
      }
    }
  }
  return;
}

