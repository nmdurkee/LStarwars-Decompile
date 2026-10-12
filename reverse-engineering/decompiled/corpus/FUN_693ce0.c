/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693ce0; label: FUN_00693ce0
 */

int FUN_00693ce0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  piVar3 = (int *)(in_ECX + 0x144);
  while ((iVar1 = *(int *)(in_ECX + 0x134 + (*piVar3 + iVar2) * 4), iVar1 == 0 ||
         (*(int *)(iVar1 + 0x14) != param_1))) {
    iVar2 = iVar2 + 0xd;
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 0xd;
    if (0x19 < iVar2) {
      return 0;
    }
  }
  return iVar4 * 0x34 + 0x130 + in_ECX;
}

