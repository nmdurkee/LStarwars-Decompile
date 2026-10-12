/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49ad40; label: FUN_0049ad40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ad40(int param_1)

{
  *(undefined1 *)(param_1 + 0x7b5) = 0x2a;
  *(undefined2 *)(param_1 + 0x7aa) = 1;
  *(undefined4 *)(param_1 + 0x784) = _DAT_007fc040;
  *(undefined4 *)(param_1 + 0x77c) = _DAT_007fc040;
  *(undefined4 *)(param_1 + 0x780) = *(undefined4 *)(param_1 + 0x77c);
  FUN_00681f40("XWing_LoopDeLoop",param_1 + 0x80);
  return;
}

