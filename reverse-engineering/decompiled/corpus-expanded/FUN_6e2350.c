/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2350; label: FUN_006e2350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2350(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x6b4);
  *(undefined4 *)(in_ECX + 0x6b4) = *(undefined4 *)(in_ECX + 0x6bc);
  *(undefined4 *)(in_ECX + 0x6bc) = uVar1;
  uVar1 = *(undefined4 *)(in_ECX + 0x6c4);
  *(undefined4 *)(in_ECX + 0x6c4) = *(undefined4 *)(in_ECX + 0x6cc);
  *(undefined4 *)(in_ECX + 0x6cc) = uVar1;
  return;
}

