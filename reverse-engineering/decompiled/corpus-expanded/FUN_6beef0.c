/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6beef0; label: FUN_006beef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006beef0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00626290(0,&DAT_0081f9a0);
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627b80(0,&DAT_0081f9a0,*(undefined4 *)(in_ECX + 0xa4),0,FUN_006bee90,
                       "Show Hidden Solid");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627b80(0,&DAT_0081f9a0,*(undefined4 *)(in_ECX + 0xa8),0,&LAB_006beeb0,
                       "Show Hidden Wire");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627b80(0,&DAT_0081f9a0,*(undefined4 *)(in_ECX + 0xac),0,&LAB_006beed0,
                       "Show Owned Obj");
  FUN_00618e10(param_1,uVar1);
  return;
}

