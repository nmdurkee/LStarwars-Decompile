/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40e9a0; label: FUN_0040e9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0040e9a0(undefined4 param_1,float param_2)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int in_EDX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [19];
  
  iVar3 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + in_EDX * 2);
  if (iVar3 == -1) {
    return 0;
  }
  if (param_2 != 1.0) {
    puVar4 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar4 = puVar4 + 1;
    }
    in_EAX = local_50;
    FUN_005c07c0(in_EAX,param_2);
  }
  uVar1 = FUN_0041cb50(iVar3 * 0x54 + *(int *)(DAT_029130e4 + 0x18),0,in_EAX,0,0,0,0,param_1);
  return uVar1;
}

