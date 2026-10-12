/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652b60; label: FUN_00652b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652b60(undefined4 param_1,int param_2)

{
  DAT_008104b0 = param_1;
  if (((DAT_00810490 == 0xb) || (DAT_00810490 == 0xc)) || (DAT_00810490 == 0xd)) {
    DAT_00810490 = (ushort)(param_2 == 0xd) * 2 + 0xb;
  }
  return;
}

