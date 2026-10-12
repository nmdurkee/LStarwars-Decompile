/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a580; label: FUN_0060a580
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

