/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc7e0; label: FUN_006bc7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bc7e0(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x2a8)) {
    piVar2 = (int *)(in_ECX + 0x34c);
    do {
      if (param_1 == *piVar2) {
        return (*(int *)(iVar1 * 0xa8 + 0x350 + in_ECX) << 0x1f) >> 0x1f;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x2a;
    } while (iVar1 < *(int *)(in_ECX + 0x2a8));
  }
  return 0;
}

