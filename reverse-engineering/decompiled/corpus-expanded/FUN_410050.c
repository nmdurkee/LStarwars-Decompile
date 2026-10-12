/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x410050; label: FUN_00410050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00410050(void)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  
  iVar1 = 0;
  piVar2 = (int *)(in_EDX + 0x565e0);
  do {
    if (*piVar2 == 0) {
      return iVar1 * 0x130 + 0x564d0 + in_EDX;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x4c;
  } while (iVar1 < 0x60);
  return 0;
}

