/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e5d20; label: FUN_005e5d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5d20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 0x58) = uVar1;
  *(undefined2 *)(in_ECX + 0x88) = 0;
  *(undefined1 *)(in_ECX + 0x8a) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  return;
}

