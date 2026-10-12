/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x743da0; label: FUN_00743da0
 */

void FUN_00743da0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int *param_7,int *param_8)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EBX;
  undefined4 uVar4;
  int *local_14;
  int *local_10;
  undefined4 local_c;
  int *local_8;
  undefined4 local_4;
  
  iVar2 = (int)param_8;
  FUN_007422a0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  local_14 = (int *)0x0;
  local_10 = (int *)0x0;
  param_8 = (int *)0x0;
  local_c = 0;
  local_4 = 0;
  if (iVar2 == 1) {
    pcVar1 = "vs_1_1";
    local_8 = (int *)0x7e8b40;
  }
  else if (iVar2 == 2) {
    pcVar1 = "vs_2_0";
    local_8 = (int *)0x7e8b50;
  }
  else if (iVar2 == 3) {
    pcVar1 = "vs_2_a";
    local_8 = (int *)0x7e8b60;
  }
  else {
    pcVar1 = "vs_3_0";
    local_8 = (int *)0x7e8b70;
  }
  uVar4 = 0x200;
  if (iVar2 < 2) {
    uVar4 = 0x10200;
  }
  iVar2 = D3DXCompileShader(param_4,param_5,0,0,"vertexProgram",pcVar1,uVar4,&local_14,&param_8,
                            &local_c);
  if (iVar2 == 0) {
    if ((param_6 == 0) ||
       (iVar2 = D3DXCompileShader(param_6,param_7,0,0,"fragmentProgram",local_8,uVar4,&local_10,
                                  &param_8,&local_4), iVar2 == 0)) {
      uVar4 = (**(code **)(*local_14 + 0xc))(local_14,param_1 + 0x4cc);
      FUN_006e4870(uVar4);
      if (param_6 != 0) {
        iVar2 = FUN_004ff0a0();
        if ((iVar2 != 0) && (iVar2 = FUN_006df330(), iVar2 != 0)) {
          Sleep(10);
        }
        uVar4 = (**(code **)(*local_14 + 0xc))(local_14,param_1 + 0x4d0);
        FUN_006e4770(uVar4);
      }
      FUN_00742410(param_1,local_10,local_8);
      if (unaff_EBX != (int *)0x0) {
        (**(code **)(*unaff_EBX + 8))(unaff_EBX);
      }
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
        local_14 = (int *)0x0;
      }
      if (param_7 != (int *)0x0) {
        (**(code **)(*param_7 + 8))(param_7);
      }
      piVar3 = local_8;
      if (local_10 != (int *)0x0) {
        (**(code **)(*local_10 + 8))(local_10);
        local_10 = (int *)0x0;
        piVar3 = local_8;
      }
    }
    else {
      (**(code **)(*param_8 + 0xc))(param_8);
      if (unaff_EBX != (int *)0x0) {
        (**(code **)(*unaff_EBX + 8))(unaff_EBX);
      }
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
        local_14 = (int *)0x0;
      }
      piVar3 = local_8;
      if (param_7 != (int *)0x0) {
        (**(code **)(*param_7 + 8))(param_7);
        piVar3 = local_8;
      }
    }
  }
  else {
    (**(code **)(*param_8 + 0xc))(param_8);
    if (unaff_EBX != (int *)0x0) {
      (**(code **)(*unaff_EBX + 8))(unaff_EBX);
    }
    piVar3 = local_10;
    if (param_7 != (int *)0x0) {
      (**(code **)(*param_7 + 8))(param_7);
      piVar3 = local_10;
    }
  }
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  return;
}

