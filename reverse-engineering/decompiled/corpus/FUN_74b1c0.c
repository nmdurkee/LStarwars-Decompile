/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74b1c0; label: FUN_0074b1c0
 */

void FUN_0074b1c0(char *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = in_ECX - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

