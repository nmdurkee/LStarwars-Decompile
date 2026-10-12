/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614120; label: FUN_00614120
 */

void FUN_00614120(int *param_1,int param_2)

{
  int *piVar1;
  ushort *puVar2;
  int in_ECX;
  
  piVar1 = param_1;
  if (param_1[1] != 0) {
    FUN_004ef660(&param_1,param_1[2] + param_1[1],2);
    if (*piVar1 != 0) {
      FUN_00621180(&param_1);
    }
    piVar1 = piVar1 + 2;
    *piVar1 = *piVar1 + 2;
  }
  puVar2 = (ushort *)(in_ECX + ((short)param_1 + 2) * 0x18);
  *puVar2 = *puVar2 & 0xffdf;
  if (*(int *)(in_ECX + 0x38 + (short)param_1 * 0x18) != param_2) {
    *(int *)(in_ECX + 0x38 + (short)param_1 * 0x18) = param_2;
    FUN_0060e4c0(in_ECX + ((short)param_1 + 2) * 0x18,param_2);
  }
  return;
}

