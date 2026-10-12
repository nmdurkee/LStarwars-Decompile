/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x628e70; label: FUN_00628e70
 */

void FUN_00628e70(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0x80404040;
  local_14 = 0x80404040;
  local_10 = 0x800000c0;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_20 = 0x8000c000;
  local_1c = 0x80ff0000;
  local_18 = 0x80808080;
  DAT_02900a54 = (undefined4 *)
                 FUN_00619250(0x46,0x46,300,0xfa,*(undefined4 *)(param_1 + 0x2c),&LAB_00626b30,
                              "Message");
  if (DAT_02900a54 != (undefined4 *)0x0) {
    if (param_2 != 0) {
      puVar2 = &local_20;
      if (param_5 == 0) {
        puVar2 = &local_10;
      }
      DAT_02900c84 = (undefined4 *)FUN_00627a80(1,puVar2,0,0,0,param_2);
      puVar1 = DAT_02900a54;
      puVar2 = DAT_02900a54 + 1;
      if ((undefined4 *)DAT_02900a54[1] == (undefined4 *)0x0) {
        *DAT_02900a54 = DAT_02900c84;
      }
      else {
        *(undefined4 *)DAT_02900a54[1] = DAT_02900c84;
      }
      DAT_02900c84[1] = *puVar2;
      *DAT_02900c84 = 0;
      *puVar2 = DAT_02900c84;
      puVar1[3] = *puVar1;
      puVar1[4] = 0;
    }
    if (param_3 != 0) {
      puVar2 = &local_20;
      if (param_6 == 0) {
        puVar2 = &local_10;
      }
      DAT_02900c84 = (undefined4 *)FUN_00627a80(1,puVar2,0,0,0,param_3);
      puVar1 = DAT_02900a54;
      puVar2 = DAT_02900a54 + 1;
      if ((undefined4 *)DAT_02900a54[1] == (undefined4 *)0x0) {
        *DAT_02900a54 = DAT_02900c84;
      }
      else {
        *(undefined4 *)DAT_02900a54[1] = DAT_02900c84;
      }
      DAT_02900c84[1] = *puVar2;
      *DAT_02900c84 = 0;
      *puVar2 = DAT_02900c84;
      puVar1[3] = *puVar1;
      puVar1[4] = 0;
    }
    if (param_4 != 0) {
      puVar2 = &local_20;
      if (param_7 == 0) {
        puVar2 = &local_10;
      }
      DAT_02900c84 = (undefined4 *)FUN_00627a80(1,puVar2,0,0,0,param_4);
      puVar1 = DAT_02900a54;
      puVar2 = DAT_02900a54 + 1;
      if ((undefined4 *)DAT_02900a54[1] == (undefined4 *)0x0) {
        *DAT_02900a54 = DAT_02900c84;
      }
      else {
        *(undefined4 *)DAT_02900a54[1] = DAT_02900c84;
      }
      DAT_02900c84[1] = *puVar2;
      *DAT_02900c84 = 0;
      *puVar2 = DAT_02900c84;
      puVar1[3] = *puVar1;
      puVar1[4] = 0;
    }
    FUN_006279b0(param_1,DAT_02900a54);
    DAT_02900a54[5] = *(int *)(param_1 + 0x14) + 10;
    DAT_02900a54[6] = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

