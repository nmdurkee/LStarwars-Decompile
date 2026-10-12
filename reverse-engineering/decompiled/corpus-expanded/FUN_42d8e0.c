/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42d8e0; label: FUN_0042d8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042d8e0(float param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  if ((param_1 == (float)DAT_008765e0) || (param_1 == (float)DAT_008765ec)) {
    param_1 = _DAT_007f5c74 - *(float *)(*(int *)((int)param_1 + 4) + 0x90);
    fVar1 = -(_DAT_007f5c74 - 1.0);
    if (param_1 < fVar1) {
      param_1 = fVar1;
    }
    param_1 = 1.0 - ABS(param_1) / (_DAT_007f5c74 - 1.0);
    fVar3 = (float10)FUN_005becc0(PTR_DAT_008021b4 + 0x11c,&DAT_007f5cf8,0);
    if ((float)fVar3 < _DAT_007f5d04) {
      param_1 = (1.0 - (float)fVar3 / _DAT_007f5d04) * param_1;
    }
    iVar2 = FUN_0054fa60(0,0,0);
    FUN_0054a910((float)iVar2 * 1.5259022e-05 * param_1);
    FUN_00549bb0(PTR_DAT_008021b4,param_1 + param_1,0x3dcccccd,0x3fa00000);
  }
  return;
}

