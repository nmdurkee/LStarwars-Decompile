/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x6947c0; label: FUN_006947c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006947c0(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (param_3 == 0) {
    return -1;
  }
  iVar4 = 0;
  puVar3 = param_1;
  if (0 < *param_2) {
    do {
      iVar2 = FUN_004f8b10(*puVar3,param_3);
      if (iVar2 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 7;
    } while (iVar4 < *param_2);
  }
  piVar1 = param_1 + iVar4 * 7;
  *piVar1 = param_3;
  piVar1[1] = param_5;
  piVar1[3] = iVar4;
  piVar1[4] = 0;
  piVar1[2] = (uint)(param_4 == 0);
  *param_2 = *param_2 + 1;
  return iVar4;
}

