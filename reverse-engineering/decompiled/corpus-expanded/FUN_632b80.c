/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x632b80; label: FUN_00632b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00632b80(undefined4 *param_1,float param_2,float param_3,float param_4,float param_5,
                 undefined4 param_6)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  uint local_c;
  
  puVar3 = param_1;
  FUN_006326b0(param_6);
  fVar1 = (float)(int)param_1[0x11];
  puVar5 = (undefined4 *)param_1[0x12];
  if ((int)param_1[0x11] < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  local_c = 0;
  fVar2 = fVar1 * param_4;
  if (param_1[0xc] != 0) {
    do {
      uVar4 = 0;
      param_1 = (undefined4 *)param_2;
      if (puVar3[0xb] != 0) {
        do {
          (**(code **)(*(int *)*puVar3 + 0x104))((int *)*puVar3,0,*puVar5);
          puVar5 = puVar5 + 1;
          FUN_006323a0(param_1,param_3,param_4,param_5,puVar3[0x11],puVar3[0x11],param_6);
          uVar4 = uVar4 + 1;
          param_1 = (undefined4 *)((float)param_1 + fVar2);
        } while (uVar4 < (uint)puVar3[0xb]);
      }
      if (puVar3[0xd] != 0) {
        (**(code **)(*(int *)*puVar3 + 0x104))((int *)*puVar3,0,*puVar5);
        puVar5 = puVar5 + 1;
        FUN_006323a0(param_1,param_3,param_4,param_5,puVar3[0xd],puVar3[0x11],param_6);
      }
      param_3 = param_3 + fVar1 * param_5;
      local_c = local_c + 1;
    } while (local_c < (uint)puVar3[0xc]);
  }
  if (puVar3[0xe] != 0) {
    uVar4 = 0;
    param_1 = (undefined4 *)param_2;
    if (puVar3[0xb] != 0) {
      do {
        (**(code **)(*(int *)*puVar3 + 0x104))((int *)*puVar3,0,*puVar5);
        puVar5 = puVar5 + 1;
        FUN_006323a0(param_1,param_3,param_4,param_5,puVar3[0x11],puVar3[0xe],param_6);
        uVar4 = uVar4 + 1;
        param_1 = (undefined4 *)((float)param_1 + fVar2);
      } while (uVar4 < (uint)puVar3[0xb]);
    }
    if (puVar3[0xd] != 0) {
      (**(code **)(*(int *)*puVar3 + 0x104))((int *)*puVar3,0,*puVar5);
      FUN_006323a0(fVar2,unaff_retaddr,param_1,param_2,puVar3[0xd],puVar3[0xe],param_3);
    }
  }
  return;
}

