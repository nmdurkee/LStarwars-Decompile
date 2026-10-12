/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49d4d0; label: FUN_0049d4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049d4d0(int param_1,undefined1 param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x7b5) = 0x5d;
  *(undefined1 *)(param_1 + 0x7b3) = param_2;
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x2c4);
  *(undefined4 *)(param_1 + 0x778) = 0x4e6e6b28;
  *(ushort *)(param_1 + 0x7aa) = (-(ushort)(iVar1 != 0) & 0xb0) + 1;
  return;
}

