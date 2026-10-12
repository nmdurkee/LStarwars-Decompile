/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x629ed0; label: FUN_00629ed0
 */

void FUN_00629ed0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  FUN_00618c30();
  DAT_02910c94 = (undefined4 *)FUN_00619250(0x5a,0x5a,0xb4,0x32,param_1,0,"SubMenu1");
  if (DAT_02910c94 != (undefined4 *)0x0) {
    DAT_02900c84 = (undefined4 *)FUN_00627a80(0,&local_10,0,1,&LAB_0061f180,"Sub Sel 0");
    puVar2 = DAT_02910c94;
    if ((undefined4 *)DAT_02910c94[1] == (undefined4 *)0x0) {
      *DAT_02910c94 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02910c94[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    DAT_02900c84 = (undefined4 *)FUN_00627a80(1,&local_10,0,1,&LAB_0061f180,"Sub Sel 1");
    puVar2 = DAT_02910c94;
    if ((undefined4 *)DAT_02910c94[1] == (undefined4 *)0x0) {
      *DAT_02910c94 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02910c94[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    DAT_02900c84 = (undefined4 *)FUN_00627a80(2,&local_10,0,1,&LAB_0061f180,"Sub Sel 2");
    puVar2 = DAT_02910c94;
    if ((undefined4 *)DAT_02910c94[1] == (undefined4 *)0x0) {
      *DAT_02910c94 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02910c94[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
  }
  DAT_02912134 = (undefined4 *)FUN_00619250(0x46,0x46,0xb4,0x32,param_1,0,"SubMenu0");
  if (DAT_02912134 != (undefined4 *)0x0) {
    DAT_02900c84 = (undefined4 *)FUN_00627a80(0,&local_10,0,1,&LAB_0061f180,"Sub Sel");
    puVar2 = DAT_02912134;
    if ((undefined4 *)DAT_02912134[1] == (undefined4 *)0x0) {
      *DAT_02912134 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912134[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    DAT_02900c84 = (undefined4 *)
                   FUN_00627a80(DAT_02910c94,&local_10,0,0,&LAB_00629440,"Sub Menu 1..");
    puVar2 = DAT_02912134;
    if ((undefined4 *)DAT_02912134[1] == (undefined4 *)0x0) {
      *DAT_02912134 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912134[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    DAT_02900c84 = (undefined4 *)FUN_00627a80(2,&local_10,0,1,&LAB_0061f180,"Sub Sel");
    puVar2 = DAT_02912134;
    if ((undefined4 *)DAT_02912134[1] == (undefined4 *)0x0) {
      *DAT_02912134 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912134[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
  }
  DAT_0291212c = (undefined4 *)FUN_00619250(0x32,0x32,0xb4,0x32,param_1,0,"Main Menu");
  if (DAT_0291212c != (undefined4 *)0x0) {
    DAT_02900c84 = (undefined4 *)
                   FUN_00627a80(DAT_02912134,&local_10,0,0,&LAB_00629440,"Sub Menu 0..");
    puVar2 = DAT_0291212c;
    if ((undefined4 *)DAT_0291212c[1] == (undefined4 *)0x0) {
      *DAT_0291212c = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_0291212c[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
    puVar2 = (undefined4 *)FUN_00629d00(1,&local_10,&DAT_0061f190,"GradPick");
    if (puVar2 != (undefined4 *)0x0) {
      FUN_0061a760(puVar2,0,0,0,0);
      FUN_0061a760(puVar2,0x3f800000,0,0,0x3f800000);
    }
    puVar1 = DAT_0291212c;
    if ((undefined4 *)DAT_0291212c[1] == (undefined4 *)0x0) {
      *DAT_0291212c = puVar2;
    }
    else {
      *(undefined4 *)DAT_0291212c[1] = puVar2;
    }
    puVar2[1] = puVar1[1];
    *puVar2 = 0;
    puVar1[1] = puVar2;
    puVar1[3] = *puVar1;
    DAT_02900c84 = puVar2;
    puVar1[4] = 0;
    puVar2 = (undefined4 *)FUN_00629d00(1,&local_10,&DAT_0061f190,"GreyGradPick");
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = 8;
      FUN_0061a760(puVar2,0,0,0,0);
      FUN_0061a760(puVar2,0x3f800000,0,0,0x3f800000);
    }
    puVar1 = DAT_0291212c;
    if ((undefined4 *)DAT_0291212c[1] == (undefined4 *)0x0) {
      *DAT_0291212c = puVar2;
    }
    else {
      *(undefined4 *)DAT_0291212c[1] = puVar2;
    }
    puVar2[1] = puVar1[1];
    *puVar2 = 0;
    puVar1[1] = puVar2;
    puVar1[3] = *puVar1;
    DAT_02900c84 = puVar2;
    puVar1[4] = 0;
    DAT_02900c84 = (undefined4 *)FUN_00627a80(2,&local_10,0,1,&LAB_0061f180,&DAT_0076b114);
    puVar2 = DAT_0291212c;
    if ((undefined4 *)DAT_0291212c[1] == (undefined4 *)0x0) {
      *DAT_0291212c = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_0291212c[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar2[1];
    *DAT_02900c84 = 0;
    puVar2[1] = DAT_02900c84;
    puVar2[3] = *puVar2;
    puVar2[4] = 0;
  }
  return;
}

