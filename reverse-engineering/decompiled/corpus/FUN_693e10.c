/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693e10; label: FUN_00693e10
 */

void FUN_00693e10(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0x1c) != 0) {
    iVar1 = (*(int *)(in_ECX + 0x20) + 1) % *(int *)(in_ECX + 0x1c);
    *(int *)(in_ECX + 0x20) = iVar1;
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar1 * 4);
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}

