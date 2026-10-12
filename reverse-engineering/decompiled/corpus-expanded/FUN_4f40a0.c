/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f40a0; label: FUN_004f40a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f40a0(int *param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *unaff_EDI;
  
  iVar1 = *unaff_EDI;
  iVar2 = 0x80 - in_ECX;
  if (iVar1 < in_ECX) {
    if (iVar1 < -in_ECX) {
      *unaff_EDI = ((iVar1 + in_ECX) * 0x7f) / iVar2;
    }
    else {
      *unaff_EDI = 0;
    }
  }
  else {
    *unaff_EDI = (((iVar1 - in_ECX) + 1) * 0x7f) / iVar2;
  }
  iVar1 = *param_1;
  if (in_ECX <= iVar1) {
    *param_1 = (((iVar1 - in_ECX) + 1) * 0x7f) / iVar2;
    return;
  }
  if (iVar1 < -in_ECX) {
    *param_1 = ((iVar1 + in_ECX) * 0x7f) / iVar2;
    return;
  }
  *param_1 = 0;
  return;
}

