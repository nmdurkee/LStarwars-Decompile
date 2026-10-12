/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693e50; label: FUN_00693e50
 */

int FUN_00693e50(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (param_1 == 1 << ((byte)iVar1 & 0x1f)) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return -1;
}

