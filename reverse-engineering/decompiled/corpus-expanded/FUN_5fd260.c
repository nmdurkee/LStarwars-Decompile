/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd260; label: FUN_005fd260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd260(undefined4 *param_1,float param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)((int)param_2 + 0x30) != 0) {
    param_2 = (float)*(int *)((int)param_2 + 0x30);
  }
  if ((*(char *)((int)param_2 + 0x99) != -0x7f) && (*(char *)((int)param_2 + 0x99) != -0x7b)) {
    puVar2 = &DAT_0280d340;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
  if (*(float *)((int)param_2 + 0x60) == 0.0) {
    param_2 = 1.0;
  }
  else {
    param_2 = *(float *)((int)param_2 + 0x60);
  }
  if (_DAT_0080e190 != param_2) {
    _DAT_0080e190 = param_2;
    puVar2 = &DAT_0280d340;
    puVar3 = &DAT_0097baf0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    if (param_2 != 1.0) {
      local_4 = param_2;
      local_8 = param_2;
      local_c = param_2;
      FUN_005b4c30(&DAT_0097baf0,&local_c);
    }
  }
  puVar2 = &DAT_0097baf0;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

