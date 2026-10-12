/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f87d0; label: FUN_005f87d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f87d0(void)

{
  undefined4 *in_EAX;
  
  DAT_00986ea0 = *in_EAX;
  DAT_00986ea4 = in_EAX[1];
  DAT_00986ea8 = in_EAX[2];
  DAT_00986eac = in_EAX[3];
  FUN_007412e0(0x38);
  return;
}

