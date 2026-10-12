/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614290; label: FUN_00614290
 */

void FUN_00614290(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int in_ECX;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004ef660(&param_1,*(int *)(param_1 + 8) + *(int *)(param_1 + 4),1);
    piVar1 = (int *)(iVar2 + 8);
    *piVar1 = *piVar1 + 1;
  }
  if ('\0' < (char)param_1) {
    cVar3 = (char)param_1 + -1;
    param_1 = CONCAT31(param_1._1_3_,cVar3);
    if (*(int *)(in_ECX + 0xd6b4 + cVar3 * 0xc) == 0) {
      (**(code **)(in_ECX + (cVar3 * 3 + 0x35af) * 4))(iVar2);
    }
  }
  return;
}

