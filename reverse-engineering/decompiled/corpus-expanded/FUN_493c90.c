/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x493c90; label: FUN_00493c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00493c90(void)

{
  int unaff_ESI;
  
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  return *(undefined4 *)(&DAT_0297ad80 + unaff_ESI * 4);
}

