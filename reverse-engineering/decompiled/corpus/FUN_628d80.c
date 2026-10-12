/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x628d80; label: FUN_00628d80
 */

void FUN_00628d80(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x800000c0;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (param_3 == 1) {
    local_10 = 0x8000c000;
  }
  DAT_02900a54 = (undefined4 *)
                 FUN_00619250(0x46,0x46,0xb4,0xfa,*(undefined4 *)(param_1 + 0x2c),&LAB_00626b30,
                              "Message");
  if (DAT_02900a54 != (undefined4 *)0x0) {
    DAT_02900c84 = (undefined4 *)FUN_00627a80(1,&local_10,0,0,0,param_2);
    puVar2 = DAT_02900a54;
    puVar1 = DAT_02900a54 + 1;
    if ((undefined4 *)DAT_02900a54[1] == (undefined4 *)0x0) {
      *DAT_02900a54 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02900a54[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = *puVar1;
    *DAT_02900c84 = 0;
    *puVar1 = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    FUN_006279b0(param_1,DAT_02900a54);
    DAT_02900a54[5] = *(int *)(param_1 + 0x14) + 10;
    DAT_02900a54[6] = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

