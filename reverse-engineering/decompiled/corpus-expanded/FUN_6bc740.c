/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc740; label: FUN_006bc740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006bc740(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x2a8)) {
    iVar2 = in_ECX + 0x2ac;
    do {
      iVar1 = FUN_004f8b10(param_1,iVar2);
      if (iVar1 == 0) {
        return *(undefined4 *)(iVar3 * 0xa8 + 0x34c + in_ECX);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xa8;
    } while (iVar3 < *(int *)(in_ECX + 0x2a8));
  }
  return 0;
}

