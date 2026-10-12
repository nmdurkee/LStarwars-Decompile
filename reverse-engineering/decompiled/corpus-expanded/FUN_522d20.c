/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522d20; label: FUN_00522d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00522d20(void)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  int unaff_ESI;
  
  if ((in_EDX != 0) && (unaff_ESI != 0)) {
    iVar1 = 0;
    piVar2 = (int *)(in_EDX + 0x30);
    do {
      if (*piVar2 == unaff_ESI) {
        return in_EDX + (iVar1 * 3 + 0xc) * 4;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 3;
    } while (iVar1 < 8);
  }
  return 0;
}

