/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d6430; label: FUN_005d6430
 */

void FUN_005d6430(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [16];
  
  uVar1 = param_2 + param_3 * 0xc;
  if (param_4 == 0) {
    puVar3 = &DAT_0080b888;
    puVar4 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    FUN_005c1240(local_40,param_4,&DAT_0080b888);
  }
  for (; param_2 < uVar1; param_2 = param_2 + 0xc) {
    FUN_005b3110(param_1,param_2,local_40);
    param_1 = param_1 + 0xc;
  }
  return;
}

