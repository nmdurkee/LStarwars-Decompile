/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x6946b0; label: FUN_006946b0
 */

uint FUN_006946b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(uint *)(in_ECX + 0x128);
  if (uVar2 < *(uint *)(in_ECX + 300)) {
    do {
      iVar1 = FUN_004f8b10(uVar2,param_1);
      if (iVar1 == 0) {
        return uVar2;
      }
      iVar1 = FUN_004f1ff0(uVar2);
      uVar2 = uVar2 + 1 + iVar1;
    } while (uVar2 < *(uint *)(in_ECX + 300));
  }
  return 0;
}

