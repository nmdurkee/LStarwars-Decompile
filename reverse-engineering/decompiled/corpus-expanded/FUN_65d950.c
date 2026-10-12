/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d950; label: FUN_0065d950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065d950(int param_1)

{
  FUN_00543fd0((&DAT_02947d98)[param_1 * 0x11]);
  DAT_02962974 = DAT_02962974 + -1;
  (&DAT_02947d98)[param_1 * 0x11] = 0xffffffff;
  (&DAT_02947db4)[param_1 * 0x44] = 0xff;
  return;
}

