/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59f460; label: FUN_0059f460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059f460(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  puVar4 = param_1;
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = param_1 + 1;
    piVar2 = param_1 + 2;
    param_1 = (undefined4 *)0x0;
    if (0 < *piVar1) {
      puVar5 = (undefined4 *)(*piVar2 + 0xc);
      do {
        if (((*(char *)((int)puVar5 + -9) == '\0') &&
            (piVar1 = (int *)*puVar5, piVar1 != (int *)0x0)) && (iVar6 = 0, 0 < *piVar1)) {
          do {
            piVar2 = *(int **)(piVar1[2] + iVar6 * 4);
            if ((piVar2 != (int *)0x0) && (iVar3 = *piVar2, iVar3 != 0)) {
              FUN_0055a2b0(*puVar4,iVar3,1,1);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *piVar1);
        }
        param_1 = (undefined4 *)((int)param_1 + 1);
        puVar5 = puVar5 + 8;
      } while ((int)param_1 < (int)puVar4[1]);
    }
  }
  return;
}

