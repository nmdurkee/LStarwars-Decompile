/* Ghidra pseudocode, not original source.
 * ev_8db479debe006dcb1d0ae53ec943fbf75b60233db5d397d4c7fbd4646b77bfb6
 * Entry: 0x516980; label: FUN_00516980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516980(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,int param_5,int param_6)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  short local_4;
  
  uVar2 = 0xffff;
  local_4 = -1;
  if (param_3 == 0) {
    return 1;
  }
  if (*(int **)(param_3 + 0xd0) == (int *)0x0) {
    return 1;
  }
  if (**(int **)(param_3 + 0xd0) == 0) {
    return 1;
  }
  if (param_6 == 0) {
    return 1;
  }
  iVar4 = 0;
  sVar1 = -1;
  if (0 < param_5) {
    do {
      local_4 = sVar1;
      iVar3 = FUN_004f8b10(param_4[iVar4],"from=All");
      if (iVar3 == 0) {
        uVar2 = *(undefined2 *)(DAT_029130e4 + 8);
      }
      else {
        iVar3 = FUN_004f8a70(param_4[iVar4],"from=");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(param_4[iVar4],&DAT_00757c50);
          if (iVar3 == 0) {
            if (param_2 != 0) {
              fVar5 = (float10)FUN_00514920(param_3,param_2,*param_4);
              *(float *)(param_2 + 0x9c) = (float)fVar5;
            }
          }
          else {
            local_4 = FUN_0062e000(*(undefined4 *)(*(int *)(param_3 + 0xd0) + 0x54),iVar3 + 3);
          }
        }
        else {
          uVar2 = FUN_0062e000(*(undefined4 *)(*(int *)(param_3 + 0xd0) + 0x54),iVar3 + 5);
        }
      }
      iVar4 = iVar4 + 1;
      sVar1 = local_4;
    } while (iVar4 < param_5);
    if (local_4 != -1) goto LAB_00516a98;
  }
  uVar2 = 0xffff;
LAB_00516a98:
  *(undefined2 *)(param_3 + 0x126) = uVar2;
  *(short *)(param_3 + 0x128) = local_4;
  return 1;
}

