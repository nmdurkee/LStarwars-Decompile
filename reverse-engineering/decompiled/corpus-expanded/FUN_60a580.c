/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a580; label: FUN_0060a580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060a580(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 4;
  piVar2 = (int *)(in_ECX + 0x8c);
  do {
    piVar3 = piVar2 + -7;
    if ((piVar2[-7] != 0) && (*(int *)(piVar2[-7] + 0x28) != 0)) {
      piVar2[-5] = 0;
    }
    piVar1 = (int *)piVar2[-5];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      piVar2[-5] = 0;
    }
    if ((*piVar3 != 0) && ((char)piVar2[-6] != '\0')) {
      FUN_005f7b40(*piVar3);
    }
    iVar4 = iVar4 + -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar2 + -6) = 0;
    *(undefined2 *)(piVar2 + -4) = 0;
    piVar2[-3] = 0;
    *(undefined2 *)(piVar2 + -2) = 0;
    *(undefined2 *)((int)piVar2 + -6) = 0;
    (&DAT_00986a88)[(short)piVar2[-1]] = 0;
    piVar2 = piVar3;
  } while (-1 < iVar4);
  return;
}

