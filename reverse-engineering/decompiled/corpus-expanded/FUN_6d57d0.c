/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d57d0; label: FUN_006d57d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_006d57d0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if ((((DAT_029755a8 & 1) == 0) && (piVar1 = *(int **)(in_ECX + 0x20), piVar1 != (int *)0x0)) &&
     (*(char *)(in_ECX + 0x40) != '\0')) {
    iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
    if (-1 < iVar2) {
      DAT_029758f8 = DAT_029758f8 ^ 1;
      (**(code **)(**(int **)(in_ECX + 0x20) + 0x24))
                (*(int **)(in_ECX + 0x20),0x14,&DAT_02975174 + (char)DAT_029758f8 * 0x14);
      return &DAT_02975174 + (char)DAT_029758f8 * 0x14;
    }
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x1c))(*(int **)(in_ECX + 0x20));
    iVar2 = *(int *)(in_ECX + 0x3c);
    *(uint *)(in_ECX + 0x3c) = (uint)(iVar2 == 0);
    FUN_006d5760(iVar2);
  }
  return (undefined *)0x0;
}

