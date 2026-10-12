/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x4204e0; label: FUN_004204e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004204e0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  
  bVar1 = false;
  if (param_2 == *(int *)(in_ECX + 0x3c + param_1 * 4)) {
    return 1;
  }
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    piVar3 = (int *)(in_ECX + 0x3c);
    do {
      if (iVar4 != param_1) {
        iVar2 = FUN_006d67a0(*piVar3);
        if (iVar2 != 0) {
          bVar1 = true;
        }
        if (param_2 == *piVar3) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < *(int *)(in_ECX + 4));
  }
  if (((param_3 == 0) && (bVar1)) && (iVar4 = FUN_006d67a0(param_2), iVar4 != 0)) {
    return 0;
  }
  return 1;
}

