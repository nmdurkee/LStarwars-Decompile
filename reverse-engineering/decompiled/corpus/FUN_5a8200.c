/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8200; label: FUN_005a8200
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

