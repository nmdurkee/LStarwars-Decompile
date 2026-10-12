/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x745170; label: FUN_00745170
 */

void FUN_00745170(char *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = (in_ECX + 0x104) - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

