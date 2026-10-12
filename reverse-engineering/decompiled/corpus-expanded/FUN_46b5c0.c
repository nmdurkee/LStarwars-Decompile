/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46b5c0; label: FUN_0046b5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b5c0(void)

{
  if (DAT_0095122c != 0) {
    DAT_0095122c = 2;
  }
  _DAT_0087b948 = 0x40000000;
  FUN_00547930(0x26,0,0,0);
  FUN_0054a910(0x3f19999a,0,0,0);
  FUN_00549de0(PTR_DAT_008021b4,0xbe4ccccd,0,0);
  return;
}

