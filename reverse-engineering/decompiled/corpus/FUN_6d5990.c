/* Ghidra analysis pseudocode, not original source.
 * ev_374b9498cac1f2764533d2b2425c9906eb7f8dc5d78a775ccd4080d89a8f30aa
 * Entry: 0x6d5990; label: FUN_006d5990
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_006d5990(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  bVar2 = DAT_029755a8 & 2;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if ((bVar2 != 0) || (piVar1 = *(int **)(in_ECX + 0x24), piVar1 == (int *)0x0)) {
LAB_006d5ae1:
    iVar3 = (int)(char)DAT_029755a1;
    _memset(&DAT_029751a0 + iVar3 * 0x100,0,DAT_029765ac);
    return &DAT_029751a0 + iVar3 * 0x100;
  }
  *(undefined4 *)(in_ECX + 0x28) = 1;
  iVar3 = (**(code **)(*piVar1 + 100))(piVar1);
  if (iVar3 < 0) {
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x1c))(*(int **)(in_ECX + 0x24));
    if (iVar3 < 0) goto LAB_006d5ae1;
    (**(code **)(**(int **)(in_ECX + 0x24) + 100))(*(int **)(in_ECX + 0x24));
  }
  DAT_029755a1 = DAT_029755a1 ^ 1;
  iVar4 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x24))
                    (*(int **)(in_ECX + 0x24),0x100,&DAT_029751a0 + (char)DAT_029755a1 * 0x100);
  iVar3 = DAT_029755ac;
  bVar2 = DAT_029755a1;
  if (iVar4 != 0) goto LAB_006d5ae1;
  _DAT_029755e0 = DAT_029755ac;
  iVar4 = 0;
  if (0 < (int)DAT_029765ac) {
    iVar5 = 0;
    do {
      if (((&DAT_029751a0)[iVar5 + (char)DAT_029755a1 * 0x100] != '\0') &&
         (iVar4 = iVar5, DAT_029755ac != iVar5)) break;
      iVar5 = iVar5 + 1;
      iVar4 = 0;
    } while (iVar5 < (int)DAT_029765ac);
  }
  if (DAT_029755b0 == 0) {
    iVar5 = iVar4;
    if (iVar4 == 0) goto LAB_006d5a91;
LAB_006d5abd:
    DAT_029755ac = iVar5;
    if (iVar4 != 0) goto LAB_006d5acb;
  }
  else {
    DAT_029755b0 = DAT_029755b0 + -1;
    if (iVar4 != 0) {
      DAT_029755b0 = 6;
    }
    _memset(&DAT_029751a0 + (char)DAT_029755a1 * 0x100,0,DAT_029765ac);
LAB_006d5a91:
    if (iVar3 != 0) {
      iVar4 = iVar3;
      iVar5 = DAT_029755ac;
      if ((&DAT_029751a0)[iVar3 + (char)bVar2 * 0x100] != '\0') goto LAB_006d5abd;
      DAT_029755ac = 0;
    }
  }
  _DAT_029755e4 = 0;
LAB_006d5acb:
  return &DAT_029751a0 + (char)bVar2 * 0x100;
}

