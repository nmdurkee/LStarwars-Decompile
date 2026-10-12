/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ccc50; label: FUN_006ccc50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ccc50(int *param_1,undefined4 param_2,float *param_3,undefined4 param_4)

{
  float *pfVar1;
  int in_ECX;
  int iVar2;
  float10 fVar3;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000001:
    *(undefined2 *)param_3 = *(undefined2 *)((int)param_1 + 6);
    return;
  case 0x80000002:
    *param_3 = (float)param_1[2];
    return;
  case 0x80000003:
    iVar2 = (**(code **)(*param_1 + 0xc))();
    if (iVar2 != 0) {
      FUN_004f1f40(param_3,iVar2,param_4);
      return;
    }
    goto LAB_006cccbf;
  case 0x80000005:
    if (param_1[4] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_1[4] + 1;
    }
    if (*(int *)(in_ECX + 0x10) != 0) {
      FUN_004f1f40(param_3,iVar2,param_4);
      return;
    }
LAB_006cccbf:
    FUN_004f1f40(param_3,&DAT_007516c0,param_4);
    return;
  case 0x80000006:
    pfVar1 = (float *)(**(code **)(*param_1 + 0x20))();
    if (pfVar1 != (float *)0x0) {
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_3 = *pfVar1;
        pfVar1 = pfVar1 + 1;
        param_3 = param_3 + 1;
      }
      return;
    }
    break;
  case 0x80000007:
    fVar3 = (float10)(**(code **)(*param_1 + 0x14))();
    *param_3 = (float)fVar3;
  }
  return;
}

