/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693c90; label: FUN_00693c90
 */

int FUN_00693c90(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0x144);
    do {
      if (*(int *)(in_ECX + 0x134 + (*piVar2 + iVar1) * 4) == param_1) {
        return iVar3 * 0x34 + 0x130 + in_ECX;
      }
      iVar1 = iVar1 + 0xd;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0xd;
    } while (iVar1 < 0x1a);
  }
  return 0;
}

