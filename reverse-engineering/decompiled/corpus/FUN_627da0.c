/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627da0; label: FUN_00627da0
 */

undefined4 * FUN_00627da0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  DAT_029130cc = (undefined4 *)
                 FUN_00619250(*(int *)(param_2 + 0x1c) + 10,*(int *)(param_2 + 0x20) + 10,0xb4,0x32,
                              *(undefined4 *)(param_1 + 0x2c),0,"Enter Text");
  DAT_029130cc[0xe] = DAT_029130cc[0xe] | 2;
  puVar2 = (undefined4 *)FUN_00627c00(param_2,&DAT_0080f514,param_3,&DAT_007516c0);
  puVar1 = DAT_029130cc;
  if ((undefined4 *)DAT_029130cc[1] == (undefined4 *)0x0) {
    *DAT_029130cc = puVar2;
  }
  else {
    *(undefined4 *)DAT_029130cc[1] = puVar2;
  }
  puVar2[1] = puVar1[1];
  *puVar2 = 0;
  puVar1[1] = puVar2;
  puVar1[3] = *puVar1;
  DAT_02900c84 = puVar2;
  puVar1[4] = 0;
  FUN_006279b0(param_1,puVar1);
  *(undefined2 *)(puVar2 + 0x56) = 1;
  FUN_006242b0(puVar1,8);
  uVar3 = FUN_004f1ff0(puVar2 + 0x13);
  puVar2[0x55] = uVar3;
  return puVar2;
}

