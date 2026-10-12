/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5de100; label: FUN_005de100
 */

undefined1 * FUN_005de100(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = DAT_0080baa8;
  puVar1 = (undefined1 *)*param_3;
  *param_3 = puVar1 + 0x80;
  *puVar1 = 0x85;
  *(undefined1 **)(puVar1 + 4) = puVar1 + iVar2 * 0x10 + -0x10;
  puVar1[1] = 1;
  FUN_00603440(puVar1 + 0x10,(int)*(short *)(param_2 + 0x74));
  FUN_00603450(puVar1 + 0x20,(int)*(short *)(param_2 + 0x74));
  FUN_00603460(puVar1 + 0x30,param_2);
  FUN_00603480(puVar1 + 0x40,param_2);
  FUN_00603490(puVar1 + 0x50,param_2);
  *(undefined1 **)(puVar1 + 100) = puVar1 + DAT_0080baa8 * 0x10 + -0x10;
  puVar1[0x60] = 0x8b;
  puVar1[0x61] = 1;
  puVar1[0x70] = 0x84;
  *(undefined4 *)(puVar1 + 0x74) = 0;
  puVar1[0x71] = 4;
  return puVar1;
}

