/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x741370; label: FUN_00741370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00741370(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 1 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(s__shaders_0082aebf + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

