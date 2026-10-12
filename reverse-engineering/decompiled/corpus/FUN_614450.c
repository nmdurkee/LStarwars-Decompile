/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614450; label: FUN_00614450
 */

void FUN_00614450(int *param_1)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int local_4;
  
  piVar2 = param_1;
  local_4 = in_ECX;
  if (param_1[1] != 0) {
    FUN_004ef660(&local_4,param_1[2] + param_1[1],2);
    if (*piVar2 != 0) {
      FUN_00621180(&local_4);
    }
    piVar2[2] = piVar2[2] + 2;
  }
  if (piVar2[1] != 0) {
    FUN_004ef660(&param_1,piVar2[2] + piVar2[1],2);
    if (*piVar2 != 0) {
      FUN_00621180(&param_1);
    }
    piVar2[2] = piVar2[2] + 2;
  }
  iVar3 = FUN_006be7f0((int)(short)param_1);
  puVar1 = (ushort *)(in_ECX + ((short)local_4 + 2) * 0x18);
  if (*(int *)(in_ECX + 0x10 + ((short)local_4 + 2) * 0x18) == iVar3) {
    *puVar1 = *puVar1 & 2;
  }
  return;
}

