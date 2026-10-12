/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65f810; label: FUN_0065f810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f810(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  iVar2 = DAT_029629c8;
  _DAT_00810a9c = *(undefined4 *)(param_2 + 0x54);
  if (*(float *)(param_2 + 0x54) < _DAT_00810a98) {
    _DAT_00810a98 = *(float *)(param_2 + 0x54);
    fVar1 = *(float *)(param_2 + 0x54);
    *(float *)(DAT_029629c8 + 0x54) = fVar1;
    *(float *)(iVar2 + 0x50) = (fVar1 - *(float *)(iVar2 + 0x58)) / *(float *)(iVar2 + 0x5c);
  }
  return;
}

