/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x40f5c0; label: FUN_0040f5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

