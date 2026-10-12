/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f8cb0; label: FUN_005f8cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8cb0(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*DAT_02854bc4 != 0) && ((param_1 & 0x100) != 0)) {
    uVar1 = 1;
  }
  if ((DAT_02854bc4[0x1c] != 0) && ((param_1 & 0x200) != 0)) {
    uVar1 = uVar1 | 6;
  }
  if (uVar1 != 0) {
    FUN_006e45e0(0,0,uVar1,
                 ((((int)param_2 >> 0x18) * 0x100 + (param_2 & 0xff)) * 0x100 +
                 (param_2 >> 8 & 0xff)) * 0x100 + ((int)param_2 >> 0x10 & 0xffU),0x3f800000,0);
  }
  return;
}

