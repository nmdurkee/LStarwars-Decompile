/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0670; label: FUN_006c0670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c0670(undefined4 param_1,int param_2)

{
  DAT_0081fe04 = DAT_0081fe04 ^ 1;
  *(byte *)(param_2 + 0x11) =
       *(byte *)(param_2 + 0x11) ^ (*(byte *)(param_2 + 0x11) ^ (byte)DAT_0081fe04) & 1;
  return;
}

