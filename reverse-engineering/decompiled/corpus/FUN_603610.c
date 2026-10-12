/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603610; label: FUN_00603610
 */

undefined4 * FUN_00603610(int *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = (undefined4 *)(*param_1 + 3U & 0xfffffffc);
  *param_1 = (int)puVar2;
  puVar3 = param_2;
  puVar4 = puVar2;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  fVar5 = (float10)FUN_005b3b00(*param_1 + 0x10);
  fVar6 = (float10)FUN_005b3b00(*param_1);
  fVar7 = (float10)FUN_005b3b00(*param_1 + 0x20);
  fVar5 = (float10)FUN_005c0240((float)((fVar7 + (float10)(double)(fVar6 + (float10)(double)fVar5))
                                       * (float10)0.3333333432674408));
  *param_1 = *param_1 + 0x40;
  *(float *)*param_1 = (float)fVar5;
  *param_1 = *param_1 + 4;
  iVar1 = *param_1;
  if (*param_4 == 0) {
    local_4 = 0;
    local_8 = 0;
    local_c = 0;
    *param_1 = iVar1 + 0x40;
    FUN_005edbb0(iVar1,&local_c);
    return puVar2;
  }
  local_c = param_2[4];
  local_8 = param_2[5];
  local_4 = param_2[6];
  *param_1 = iVar1 + 0x40;
  FUN_005edd10(iVar1,&local_c);
  return puVar2;
}

