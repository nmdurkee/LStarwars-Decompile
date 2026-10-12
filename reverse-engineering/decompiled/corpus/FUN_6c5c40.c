/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5c40; label: FUN_006c5c40
 */

undefined4 FUN_006c5c40(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = FUN_0061f030();
    if (puVar2[2] != iVar1) {
      puVar2 = (undefined4 *)FUN_006c5c10(*puVar2);
    }
    if (puVar2 != (undefined4 *)0x0) {
      return *puVar2;
    }
  }
  return 0;
}

