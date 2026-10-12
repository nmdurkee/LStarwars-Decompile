/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x632db0; label: FUN_00632db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00632db0(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = (int)param_1;
  fVar1 = (float)*(int *)((int)param_1 + 0x44);
  if (*(int *)((int)param_1 + 0x44) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  uVar3 = 0;
  if (*(int *)((int)param_1 + 0x30) != 0) {
    do {
      uVar4 = 0;
      param_1 = param_2;
      if (*(int *)(iVar2 + 0x2c) != 0) {
        do {
          FUN_006324e0(param_1,param_3,param_4,param_5,*(undefined4 *)(iVar2 + 0x44),
                       *(undefined4 *)(iVar2 + 0x44));
          uVar4 = uVar4 + 1;
          param_1 = param_1 + fVar1 * param_4;
        } while (uVar4 < *(uint *)(iVar2 + 0x2c));
      }
      if (*(int *)(iVar2 + 0x34) != 0) {
        FUN_006324e0(param_1,param_3,param_4,param_5,*(int *)(iVar2 + 0x34),
                     *(undefined4 *)(iVar2 + 0x44));
      }
      uVar3 = uVar3 + 1;
      param_3 = param_3 + fVar1 * param_5;
    } while (uVar3 < *(uint *)(iVar2 + 0x30));
  }
  if (*(int *)(iVar2 + 0x38) != 0) {
    param_1 = param_2;
    if (*(int *)(iVar2 + 0x2c) != 0) {
      uVar3 = 0;
      do {
        FUN_006324e0(param_1,param_3,param_4,param_5,*(undefined4 *)(iVar2 + 0x44),
                     *(undefined4 *)(iVar2 + 0x38));
        uVar3 = uVar3 + 1;
        param_1 = param_1 + fVar1 * param_4;
      } while (uVar3 < *(uint *)(iVar2 + 0x2c));
    }
    if (*(int *)(iVar2 + 0x34) != 0) {
      FUN_006324e0(param_1,param_3,param_4,param_5,*(int *)(iVar2 + 0x34),
                   *(undefined4 *)(iVar2 + 0x38));
    }
  }
  return;
}

