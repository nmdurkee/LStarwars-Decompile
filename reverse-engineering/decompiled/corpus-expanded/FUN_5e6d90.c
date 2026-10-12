/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e6d90; label: FUN_005e6d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e6d90(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0xff;
  puVar1 = (undefined4 *)(in_ECX + 0x24);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}

