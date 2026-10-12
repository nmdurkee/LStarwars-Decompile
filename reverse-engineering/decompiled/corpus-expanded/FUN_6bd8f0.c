/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd8f0; label: FUN_006bd8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bd8f0(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *in_ECX) {
    do {
      iVar1 = FUN_006bd6a0(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *in_ECX);
  }
  return 0;
}

