/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6af1b0; label: FUN_006af1b0
 */

void FUN_006af1b0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 1) {
    FUN_006ac310(iVar1,param_1[1],param_1[1] + iVar1 * 4);
  }
  return;
}

