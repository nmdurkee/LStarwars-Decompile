/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603d20; label: FUN_00603d20
 */

void FUN_00603d20(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_78 [16];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_10;
  
  puVar2 = local_78;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_38 = param_2;
  local_34 = param_3;
  local_30 = param_4;
  local_2c = param_5;
  local_10 = param_6;
  FUN_005ed540(local_78,0);
  FUN_005db100(&DAT_0080b788);
  FUN_005c1240(&DAT_0080b888,&DAT_0080b808,&DAT_0080b788);
  puVar2 = &DAT_0080b888;
  puVar3 = &DAT_0080b848;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_006e56a0(2,&DAT_0080b708);
  FUN_006e56a0(3,&DAT_0080b748);
  return;
}

