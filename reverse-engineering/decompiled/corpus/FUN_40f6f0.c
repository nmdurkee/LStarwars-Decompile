/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40f6f0; label: FUN_0040f6f0
 */

float10 FUN_0040f6f0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  float local_50;
  float *local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  
  local_50 = 0.0;
  iVar2 = 0;
  if (*(int *)(unaff_ESI + 0x400) < 1) {
    return (float10)0.0;
  }
  local_48 = (float *)(unaff_ESI + 0x414);
  do {
    FUN_0040eff0();
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      FUN_0040eff0();
      fVar3 = (float10)FUN_005c0240((local_38 - local_28) * (local_38 - local_28) +
                                    (local_40 - local_30) * (local_40 - local_30) +
                                    (local_3c - local_2c) * (local_3c - local_2c));
      local_30 = local_40;
      local_2c = local_3c;
      local_28 = local_38;
      local_50 = (float)(fVar3 + (float10)local_50);
    } while (iVar1 < 10);
    *local_48 = local_50;
    local_48 = local_48 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < *(int *)(unaff_ESI + 0x400));
  return (float10)local_50;
}

