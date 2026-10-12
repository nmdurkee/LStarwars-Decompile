/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x6286e0; label: FUN_006286e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006286e0(undefined4 param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int local_8;
  int local_4;
  
  iVar4 = (int)param_2;
  iVar2 = *(int *)((int)param_2 + 0xc);
  piVar3 = *(int **)(iVar2 + 0x50);
  if (piVar3 == (int *)0x0) {
    param_2 = 0.0;
    local_4 = 0;
    local_8 = 0;
    iVar1 = 0x3f800000;
  }
  else {
    if (*piVar3 == 0) {
      param_2 = (float)piVar3[2] + 1.0;
    }
    else {
      param_2 = *(float *)(*piVar3 + 8) + (float)piVar3[2];
    }
    param_2 = param_2 * 0.5;
    local_4 = piVar3[4];
    local_8 = piVar3[5];
    iVar1 = piVar3[6];
  }
  uVar5 = FUN_0061a760(iVar2,param_2,local_4,local_8,iVar1);
  *(undefined4 *)(iVar2 + 0x50) = uVar5;
  if (*(code **)(iVar2 + 0x5c) != (code *)0x0) {
    (**(code **)(iVar2 + 0x5c))(param_1,iVar4,param_3);
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

