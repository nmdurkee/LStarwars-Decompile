/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x743bf0; label: FUN_00743bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00743bf0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  short *in_ECX;
  
  iVar1 = (int)(char)in_ECX[2] + param_1 * -4;
  if (param_2 * 4 < iVar1) {
    iVar1 = param_2 * 4;
  }
  if ((*(uint *)(in_ECX + 2) & 0xf0000000) == 0x10000000) {
    FUN_006e5750((int)*in_ECX + param_1 * 4);
    return;
  }
  FUN_006e52e0((int)*in_ECX + param_1 * 4,param_3,iVar1);
  return;
}

