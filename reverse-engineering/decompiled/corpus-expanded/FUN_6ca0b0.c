/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6ca0b0; label: FUN_006ca0b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ca0b0(void)

{
  if (DAT_0081fad8 == 3) {
    DAT_0081fad8 = 4;
  }
  else {
    if (DAT_0081fad8 == 4) {
      DAT_0081fad8 = 5;
      FUN_006c8c20(5);
      return;
    }
    if (DAT_0081fad8 == 5) {
      DAT_0081fad8 = 3;
      FUN_006c8c20(3);
      return;
    }
  }
  FUN_006c8c20(DAT_0081fad8);
  return;
}

