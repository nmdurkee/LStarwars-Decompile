/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65ea20; label: FUN_0065ea20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ea20(undefined4 param_1,int param_2)

{
  if (DAT_02921884 != -1) {
    *(uint *)(DAT_02921884 * 0x50 + 0x1c + DAT_02962a14) = *(byte *)(param_2 + 0x11) & 1;
  }
  return;
}

