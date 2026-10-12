/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e20f0; label: FUN_006e20f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e20f0(void)

{
  int in_ECX;
  
  *(bool *)(in_ECX + 0x65c) = *(int *)(in_ECX + 0x158) == 1;
  *(undefined4 *)(in_ECX + 0x660) = *(undefined4 *)(in_ECX + 0x620);
  *(undefined1 *)(in_ECX + 0x664) = *(undefined1 *)(in_ECX + 0x634);
  *(undefined4 *)(in_ECX + 0x668) = *(undefined4 *)(in_ECX + 0x638);
  return;
}

