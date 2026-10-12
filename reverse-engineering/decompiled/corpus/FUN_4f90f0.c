/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f90f0; label: FUN_004f90f0
 */

void FUN_004f90f0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int local_34;
  int local_30;
  float local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c [2];
  int local_14;
  double local_10;
  
  FUN_004ffb20(&local_28,&local_24);
  if (local_24 < 0) {
    FUN_004ef790();
  }
  local_10 = (double)param_1;
  if (0.0 < param_1) {
    do {
      FUN_004ffb20(&local_20,local_1c);
      iVar4 = local_1c[0];
      if (local_1c[0] < 0) {
        iVar4 = FUN_004ef790();
      }
      if (local_20 < local_28) {
        local_14 = (iVar4 - local_24) + -1;
      }
      else {
        local_14 = iVar4 - local_24;
      }
      iVar4 = local_20 - local_28;
      FUN_004ffb90(&local_30,&local_34);
      fVar3 = (float)iVar4;
      if (iVar4 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      fVar1 = (float)local_34;
      if (local_34 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      fVar2 = (float)local_30;
      if (local_30 < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_2c = ((fVar3 + (float)local_14 * 4.2949673e+09) / (fVar2 + fVar1 * 4.2949673e+09)) *
                 1000.0;
    } while (local_2c < (float)local_10);
  }
  return;
}

