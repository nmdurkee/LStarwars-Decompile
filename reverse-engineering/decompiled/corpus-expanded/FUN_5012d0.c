/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x5012d0; label: FUN_005012d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005012d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    piVar2 = (int *)(*(int *)(param_1 + 100) + 0x10);
    do {
      iVar1 = iVar1 + 1;
      if (*piVar2 == param_2) {
        return iVar1;
      }
      piVar2 = piVar2 + 8;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  return 0;
}

