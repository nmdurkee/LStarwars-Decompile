/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c5920; label: FUN_006c5920
 */

void FUN_006c5920(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  for (puVar1 = *(undefined4 **)(param_2 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    if ((puVar1[7] & 0x80000000) == 0) {
      if (puVar1[8] != 0) {
        puVar2 = (undefined4 *)param_1[1];
        (**(code **)(*(int *)puVar1[8] + 0x10))(param_1,puVar1,param_3);
        if (param_4 != 0) {
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = (undefined4 *)*param_1;
          }
          else {
            puVar2 = (undefined4 *)*puVar2;
          }
          while (puVar2 != (undefined4 *)0x0) {
            puVar3 = (undefined4 *)*puVar2;
            FUN_00619130(param_1,puVar2);
            FUN_0061ee00(param_4,puVar2);
            puVar2 = puVar3;
          }
        }
      }
    }
    else {
      uVar4 = FUN_006267f0(0,&DAT_0081f9a0,0,puVar1[4]);
      if (param_4 == 0) {
        FUN_00618e10(param_1,uVar4);
      }
      else {
        FUN_0061ee00(param_4);
      }
      iVar6 = puVar1[3];
      if ((iVar6 < 0) || (DAT_02973bac <= iVar6)) {
        iVar6 = 0;
      }
      else {
        iVar6 = DAT_02973b90 + iVar6 * 0x18;
      }
      uVar5 = (**(code **)*puVar1)(param_3);
      FUN_006c5920(param_1,iVar6,uVar5,uVar4);
    }
  }
  return;
}

