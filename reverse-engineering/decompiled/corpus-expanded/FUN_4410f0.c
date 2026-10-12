/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x4410f0; label: FUN_004410f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004410f0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((((param_5 != 0) && (param_3 != 0)) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (((iVar3 = **(int **)(param_3 + 0xd0), *(char *)(iVar3 + 0x281) != '\0' ||
       (*(char *)(iVar3 + 0x282) != '\0')) &&
      ((sVar2 = *(short *)(iVar3 + 0x27e), sVar2 != -1 &&
       (fVar1 = *(float *)(*(int *)(sVar2 * 0x6c + 0x40 + *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
       fVar1 < *(float *)(iVar3 + 0x60) != (fVar1 == *(float *)(iVar3 + 0x60)))))))) {
    for (puVar4 = *(undefined4 **)(*(int *)(param_5 + 0x28) + 0x18); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      if (sVar2 == *(short *)(puVar4[9] + 2)) {
        return (float10)1;
      }
    }
  }
  return (float10)0;
}

