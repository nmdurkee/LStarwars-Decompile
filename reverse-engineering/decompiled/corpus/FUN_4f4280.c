/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f4280; label: FUN_004f4280
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004f4280(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (1.0 <= param_1) {
    param_1 = 1.0;
  }
  iVar3 = 0;
  fVar1 = _DAT_008004f0;
  while (fVar1 < param_1) {
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    fVar1 = (float)(&DAT_008004f8)[iVar2];
  }
  return (float10)(float)(&DAT_008004f4)[iVar3 * 2];
}

