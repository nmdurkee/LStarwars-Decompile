/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a81b0; label: FUN_005a81b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a81b0(int param_1)

{
  if (DAT_00805b3c != -1) {
    FUN_0068e890(DAT_00805b3c);
  }
  if (*(int *)(param_1 + 0x2a98) != -1) {
    FUN_0068e890(*(undefined1 *)(param_1 + 0x2a98));
  }
  FUN_00656e40(1);
  if (-1 < *(int *)(param_1 + 0x2aa0)) {
    FUN_0065a590();
    return;
  }
  return;
}

