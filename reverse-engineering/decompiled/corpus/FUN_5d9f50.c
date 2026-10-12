/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5d9f50; label: FUN_005d9f50
 */

void FUN_005d9f50(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_c [12];
  
  puVar1 = param_3;
  puVar3 = &DAT_0080b888;
  puVar4 = &DAT_0097ad90;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005b5e90(&DAT_0097ad50,&DAT_0097ad90);
  FUN_005b3110(param_2,*(undefined4 *)(param_1 + 0x10),&DAT_0097ad90);
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  iVar2 = 1;
  param_3[2] = param_2[2];
  if (1 < *(short *)(param_1 + 0x14)) {
    param_3 = (undefined4 *)0xc;
    do {
      FUN_005b3110(local_c,*(int *)(param_1 + 0x10) + (int)param_3,&DAT_0097ad90);
      FUN_005b3a40(param_2,param_2,local_c);
      FUN_005b3aa0(puVar1,puVar1,local_c);
      param_3 = (undefined4 *)((int)param_3 + 0xc);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)(param_1 + 0x14));
  }
  FUN_005b3aa0(param_2,param_2,&DAT_00806570);
  FUN_005b3a40(param_2,param_2,&DAT_0080657c);
  FUN_005b3aa0(puVar1,puVar1,&DAT_00806570);
  FUN_005b3a40(puVar1,puVar1,&DAT_0080657c);
  return;
}

