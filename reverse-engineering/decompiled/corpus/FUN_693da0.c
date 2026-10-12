/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693da0; label: FUN_00693da0
 */

int FUN_00693da0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)(in_ECX + 0x148);
  iVar1 = 0;
  piVar3 = piVar2;
  do {
    if (*piVar3 == 1) goto LAB_00693dd6;
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 0xd;
  } while (iVar1 < 2);
  iVar1 = 0;
  while (*piVar2 != 3) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0xd;
    if (1 < iVar1) {
      return 0;
    }
  }
LAB_00693dd6:
  return iVar1 * 0x34 + 0x130 + in_ECX;
}

