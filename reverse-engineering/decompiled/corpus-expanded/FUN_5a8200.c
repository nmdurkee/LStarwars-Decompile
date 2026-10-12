/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8200; label: FUN_005a8200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8200(int param_1)

{
  if (*(int *)(param_1 + 0x2aa0) != -1) {
    FUN_0065a5c0(*(int *)(param_1 + 0x2aa0));
  }
  if (*(int *)(param_1 + 0x2a98) != -1) {
    FUN_0068e900(*(undefined1 *)(param_1 + 0x2a98));
  }
  if (DAT_00805b38 != -1) {
    FUN_0068e900(DAT_00805b38);
  }
  if (DAT_00805b34 != -1) {
    FUN_0068e900(DAT_00805b34);
  }
  if (DAT_00805b3c != -1) {
    FUN_0068e900(DAT_00805b3c);
  }
  FUN_00684580();
  return;
}

