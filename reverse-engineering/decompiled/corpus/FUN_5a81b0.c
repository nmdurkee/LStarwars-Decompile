/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a81b0; label: FUN_005a81b0
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

