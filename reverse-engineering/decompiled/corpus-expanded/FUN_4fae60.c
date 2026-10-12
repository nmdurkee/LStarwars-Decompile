/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fae60; label: FUN_004fae60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fae60(void)

{
  if (DAT_0297dc08 == 1) {
    FUN_004fadd0(DAT_0297dc1c);
  }
  else {
    DAT_0297dc20 = DAT_0297dc08 + -2;
    if (DAT_0297dc20 == 0) {
      DAT_0297dc08 = DAT_0297dc20;
      DAT_0297dc14 = DAT_0297dc0c;
      return;
    }
  }
  DAT_0297dc20 = 0;
  return;
}

