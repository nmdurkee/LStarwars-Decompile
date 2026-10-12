/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d2590; label: FUN_006d2590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d2590(void)

{
  undefined4 uVar1;
  
  if (DAT_0081fa94 != 0) {
    uVar1 = FUN_006d2450(DAT_0081fa94 + 8);
    return uVar1;
  }
  return 0;
}

