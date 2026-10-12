/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d2830; label: FUN_006d2830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d2830(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int aiStack_80 [32];
  
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006d1e10,&DAT_00770208);
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006c2c30,"Tools");
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006c2cb0,&DAT_0076ec34);
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006c9ee0,&DAT_007701f8);
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,&LAB_006c2e70,"Show/Hide");
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00626290(0,&DAT_0081f9a0);
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006cf6f0,"Select");
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00626290(0,&DAT_0081f9a0);
  FUN_00618e10(param_1,uVar2);
  if (*(int *)(in_ECX + 0x2c) == 0) {
    uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006d2750,&PTR_s___00776531_0x1d_007701e8);
    FUN_00618e10(param_1,uVar2);
    return;
  }
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006d2750,"New/Copy");
  FUN_00618e10(param_1,uVar2);
  uVar2 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006ca0a0,"Delete");
  FUN_00618e10(param_1,uVar2);
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  iVar4 = 0;
  do {
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = 0;
      if (0 < iVar4) {
        do {
          (**(code **)(**(int **)(aiStack_80[iVar3] + 0x14) + 0x70))(param_1);
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      return;
    }
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        if (aiStack_80[iVar3] == puVar1[2]) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    if (iVar3 == iVar4) {
      aiStack_80[iVar4] = puVar1[2];
      iVar4 = iVar4 + 1;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

