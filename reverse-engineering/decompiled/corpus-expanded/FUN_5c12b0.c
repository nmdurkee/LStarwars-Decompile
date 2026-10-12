/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c12b0; label: FUN_005c12b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c12b0(void)

{
  char *in_EAX;
  int iVar1;
  int in_EDX;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = in_EDX - (int)in_EAX;
  do {
    if (in_EAX[iVar2] != *in_EAX) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    in_EAX = in_EAX + 1;
  } while (iVar1 < 0x10);
  return 1;
}

