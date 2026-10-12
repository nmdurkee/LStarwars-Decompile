/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f3d0; label: FUN_0061f3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f3d0(void)

{
  int *piVar1;
  int iVar2;
  int in_EDX;
  int unaff_ESI;
  
  if (0 < DAT_02910ca4) {
    piVar1 = &DAT_0291214c;
    iVar2 = DAT_02910ca4;
    do {
      if ((piVar1[-1] == unaff_ESI) && (*piVar1 == in_EDX)) {
        piVar1[-1] = 0;
        *piVar1 = 0;
      }
      piVar1 = piVar1 + 9;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

