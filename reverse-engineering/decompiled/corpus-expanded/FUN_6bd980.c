/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd980; label: FUN_006bd980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006bd980(int *param_1)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  
  if (param_1[1] != 0) {
    iVar1 = 0;
    if (0 < *in_ECX) {
      piVar2 = in_ECX + 3;
      do {
        if (*(int *)(*piVar2 + 4) == *param_1) {
          return 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar1 < *in_ECX);
    }
  }
  return 0;
}

