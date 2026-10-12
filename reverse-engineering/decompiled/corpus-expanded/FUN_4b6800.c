/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b6800; label: FUN_004b6800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6800(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  float10 fVar5;
  float fVar6;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar1 == 0) || ((iVar1 != DAT_0087b014 && (iVar1 != DAT_0087af5c)))) {
    FUN_004b5120();
    return;
  }
  fVar5 = (float10)FUN_004ab790(param_1,0x41000000,0);
  FUN_004abac0(param_1,0,(float)fVar5);
  if (((DAT_0087af5c != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) &&
     (0.0 < *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28))) {
    fVar5 = (float10)FUN_004dbb60(PTR_DAT_00802c54);
    if (fVar5 < (float10)0.0 != (fVar5 == (float10)0.0)) {
      iVar1 = *(int *)(param_1 + 0xca4);
      FUN_0049ad90(param_1,*(uint *)(iVar1 + 8) & DAT_00802278,*(uint *)(iVar1 + 4) & DAT_00802278,
                   iVar1,0);
    }
  }
  FUN_0049c080(param_1);
  if ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0) {
    FUN_004ab4b0();
    FUN_004ab350();
  }
  else {
    *(undefined4 *)(param_1 + 0x1038) = 0;
  }
  iVar1 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar1 != 0) && ((iVar1 == DAT_0087b014 || ((iVar1 != 0 && (iVar1 == DAT_0087af5c)))))) {
    FUN_004ab1f0(param_1,0x3ccccccd,0x40400000,0);
  }
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    FUN_004a2070(0);
  }
  FUN_004ab620(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  iVar3 = (int)*(short *)(iVar1 + 0xe2);
  if (*(char *)(iVar1 + 0x116) == '\x14') {
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) goto LAB_004b6b57;
    if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) ||
       (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
      bVar4 = param_1 != DAT_0093d7f0;
      fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_007fc190 + (uint)bVar4 * 4),
                                    (*(float *)(param_1 + 0x228) /
                                    *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)) *
                                    0.35 + 0.65,_DAT_00925018);
      *(float *)(&DAT_007fc190 + (uint)bVar4 * 4) = (float)fVar5;
      FUN_00681ee0(iVar3,param_1 + 0x80,(float)fVar5);
      FUN_0056a5b0(PTR_DAT_00802c54,param_1);
      return;
    }
    fVar6 = (-ABS((float)(&DAT_029899a0)[*(ushort *)(*(int *)(param_1 + 0xca4) + 0x26) >> 1]) *
            (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) - 6.0)) / 96.0;
    if (1.1 <= _DAT_0087b888) {
      fVar6 = fVar6 + 2.0;
    }
    else {
      fVar6 = _DAT_0087b888 + 1.0 + fVar6;
    }
    uVar2 = (uint)(param_1 != DAT_0093d7f0);
    fVar6 = (fVar6 * 0.5 - *(float *)(&DAT_007fc190 + uVar2 * 4)) * _DAT_00925018 * 1.5 +
            *(float *)(&DAT_007fc190 + uVar2 * 4);
    *(float *)(&DAT_007fc190 + uVar2 * 4) = fVar6;
  }
  else {
    if (0.0 <= (*(float *)(param_1 + 0x88) - DAT_00973720) * DAT_00973710 +
               (*(float *)(param_1 + 0x80) - DAT_00973718) * DAT_00973708 +
               (*(float *)(param_1 + 0x84) - DAT_0097371c) * DAT_0097370c) {
      FUN_00681e90(iVar3,(float *)(param_1 + 0x80));
      FUN_0056a5b0(PTR_DAT_00802c54,param_1);
      return;
    }
    fVar6 = 0.7;
  }
  FUN_00681ee0(iVar3,param_1 + 0x80,fVar6);
LAB_004b6b57:
  FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  return;
}

