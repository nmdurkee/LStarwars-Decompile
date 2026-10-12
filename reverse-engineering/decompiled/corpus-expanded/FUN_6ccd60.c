/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ccd60; label: FUN_006ccd60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ccd60(int *param_1,undefined4 param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int in_ECX;
  
  FUN_006c5f80(param_2);
  switch(*(undefined4 *)(in_ECX + 0x14)) {
  case 0x80000001:
    *(short *)((int)param_1 + 6) = (short)*param_3;
    return;
  case 0x80000002:
    param_1[2] = *param_3;
    return;
  case 0x80000003:
    iVar2 = FUN_004f1ff0(param_3);
    if (0 < iVar2) {
      (**(code **)(*param_1 + 0x10))(param_3);
      return;
    }
    (**(code **)(*param_1 + 0x10))(0);
    return;
  case 0x80000005:
    iVar2 = FUN_004f1ff0(param_3);
    if (0 < iVar2) {
      FUN_006bd520(param_3);
      return;
    }
    pcVar1 = (char *)param_1[4];
    if (pcVar1 != (char *)0x0) {
      FUN_006334d0(pcVar1,(int)*pcVar1);
      param_1[4] = 0;
      return;
    }
    break;
  case 0x80000006:
    (**(code **)(*param_1 + 0x1c))(param_3);
    (**(code **)(*param_1 + 0x24))(param_3);
  }
  return;
}

