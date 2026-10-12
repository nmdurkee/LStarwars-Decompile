/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be630; label: FUN_005be630
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005be630(float param_1,float param_2)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  
  if ((float10)param_1 == (float10)0) {
    return (float10)0;
  }
  iVar2 = 0;
  if (DAT_008066c4 != 0) {
    DAT_008066c4 = 0;
    DAT_0095e548 = 0x7f7fffff;
    DAT_0095e54c = 0x7f7fffff;
    _DAT_0095e550 = 0x7f7fffff;
    _DAT_0095e554 = 0x7f7fffff;
    _DAT_0095e558 = 0x7f7fffff;
    _DAT_0095e55c = 0x7f7fffff;
    _DAT_0095e560 = 0x7f7fffff;
    _DAT_0095e564 = 0x7f7fffff;
    _DAT_0095e568 = 0x7f7fffff;
    _DAT_0095e56c = 0x7f7fffff;
    _DAT_0095e570 = 0x7f7fffff;
    _DAT_0095e574 = 0x7f7fffff;
    _DAT_0095e578 = 0x7f7fffff;
    _DAT_0095e57c = 0x7f7fffff;
    _DAT_0095e580 = 0x7f7fffff;
    _DAT_0095e584 = 0x7f7fffff;
    _DAT_0095e588 = 0x7f7fffff;
    _DAT_0095e58c = 0x7f7fffff;
    _DAT_0095e590 = 0x7f7fffff;
    _DAT_0095e594 = 0x7f7fffff;
    _DAT_0095e598 = 0x7f7fffff;
    _DAT_0095e59c = 0x7f7fffff;
    _DAT_0095e5a0 = 0x7f7fffff;
    _DAT_0095e5a4 = 0x7f7fffff;
    _DAT_0095e5a8 = 0x7f7fffff;
    _DAT_0095e5ac = 0x7f7fffff;
    _DAT_0095e5b0 = 0x7f7fffff;
    _DAT_0095e5b4 = 0x7f7fffff;
    _DAT_0095e5b8 = 0x7f7fffff;
    _DAT_0095e5bc = 0x7f7fffff;
    _DAT_0095e5c0 = 0x7f7fffff;
    _DAT_0095e5c4 = 0x7f7fffff;
  }
  while (((float10)param_1 != (float10)(float)(&DAT_0095e548)[iVar2] ||
         (param_2 != (float)(&DAT_0095e440)[iVar2]))) {
    iVar2 = iVar2 + 1;
    if (0x1f < iVar2) {
      FUN_006e9040();
      fVar3 = (float10)FUN_006e8fac();
      (&DAT_0095e548)[DAT_0095e644] = param_1;
      uVar1 = DAT_0095e644 + 1;
      *(float *)(&DAT_0095e43c + uVar1 * 4) = param_2;
      *(float *)(&DAT_0095e4bc + uVar1 * 4) = (float)fVar3;
      DAT_0095e644 = uVar1 & 0x1f;
      return (float10)(float)fVar3;
    }
  }
  return (float10)*(float *)(iVar2 * 4 + 0x95e4c0);
}

