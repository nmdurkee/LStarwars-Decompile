/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fad0; label: FUN_0046fad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0046fad0(int param_1,undefined4 param_2,float *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  int local_4;
  
  local_8 = 1e+09;
  iVar5 = 0;
  local_4 = 0;
  if ((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x5100), piVar2 != (int *)0x0)) {
    iVar3 = 0;
    if (0 < piVar2[1]) {
      do {
        bVar1 = *(byte *)(*piVar2 + 0x2b + iVar5);
        iVar4 = *piVar2 + iVar5;
        if (((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) {
          fVar6 = (float10)FUN_005b3c50(param_2,iVar4 + 0x10,0);
          if ((float)fVar6 < local_8) {
            local_8 = (float)fVar6;
            local_4 = iVar4;
          }
        }
        piVar2 = *(int **)(param_1 + 0x5100);
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 0x2c;
      } while (iVar3 < piVar2[1]);
    }
    if (param_3 != (float *)0x0) {
      *param_3 = local_8;
    }
    return local_4;
  }
  return 0;
}

