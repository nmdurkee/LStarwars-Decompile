/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1500; label: FUN_005b1500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1500(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar2 = *piVar1;
  if ((*(byte *)(piVar1 + 4) & 1) == 0) {
    piVar1[1] = 0x3f800000;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0x40000000;
    FUN_00565be0(1);
    DAT_0095e410 = DAT_00806294;
  }
  else {
    piVar1[1] = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0;
  }
  do {
    iVar3 = FUN_0054fa60();
    **(int **)(in_ECX + 4) = 1 << ((byte)((int)(iVar3 + (iVar3 >> 0x1f & 0x3fffU)) >> 0xe) & 0x1f);
  } while (**(int **)(in_ECX + 4) == iVar2);
  return;
}

