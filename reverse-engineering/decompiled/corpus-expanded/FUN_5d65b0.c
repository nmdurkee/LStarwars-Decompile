/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d65b0; label: FUN_005d65b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d65b0(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [16];
  
  uVar2 = param_3 * 0x10 + param_2;
  if (param_4 == 0) {
    puVar3 = &DAT_0080b908;
    puVar4 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    FUN_005c0500(local_40,param_4,&DAT_0080b908);
  }
  for (; param_2 < uVar2; param_2 = param_2 + 0x10) {
    thunk_FUN_005c03e0(param_1,param_2,local_40);
    param_1 = param_1 + 0x10;
  }
  return;
}

