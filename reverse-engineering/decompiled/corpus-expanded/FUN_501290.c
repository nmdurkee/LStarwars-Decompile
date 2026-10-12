/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501290; label: FUN_00501290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00501290(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar2 = *(int **)(param_1 + 0xc);
    do {
      iVar1 = iVar1 + 1;
      if (*(byte *)(*piVar2 + 0x9a) == param_2) {
        return iVar1;
      }
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return 0;
}

