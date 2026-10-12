/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40f5c0; label: FUN_0040f5c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0040f5c0(void)

{
  float fVar1;
  int unaff_ESI;
  float10 fVar2;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  
  local_48 = 0.0;
  if (*(int *)(unaff_ESI + 0x400) != 0) {
    FUN_0040eff0();
    local_4c = 1.0;
    do {
      fVar1 = _DAT_007f15dc;
      if ((DAT_0087b014 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b014)) {
        fVar1 = _DAT_007f15e0;
      }
      local_4c = local_4c - fVar1;
      if (local_4c < 0.0) {
        local_4c = 0.0;
      }
      FUN_0040eff0();
      fVar2 = (float10)FUN_005c0240((local_38 - local_38) * (local_38 - local_38) +
                                    (local_40 - local_40) * (local_40 - local_40) +
                                    (local_3c - local_3c) * (local_3c - local_3c));
      local_48 = (float)(fVar2 + (float10)local_48);
    } while (0.0 < local_4c);
  }
  return (float10)local_48;
}

