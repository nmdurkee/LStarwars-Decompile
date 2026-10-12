/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x6297f0; label: FUN_006297f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006297f0(void)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x800000ff;
  local_8 = 0x80808080;
  local_4 = 0x80f0f0f0;
  if (DAT_029130dc == 0) {
    DAT_029130dc = 1;
    DAT_02900a50 = (undefined4 *)FUN_00619250(200,0x46,0xb4,0xfa,0,FUN_006294d0,"Pick Colour");
    if (DAT_02900a50 != (undefined4 *)0x0) {
      DAT_029110ac = (undefined4 *)FUN_00624e20(0,&local_10,FUN_006294f0,&DAT_007516c0);
      puVar1 = DAT_02900a50;
      if ((undefined4 *)DAT_02900a50[1] == (undefined4 *)0x0) {
        *DAT_02900a50 = DAT_029110ac;
      }
      else {
        *(undefined4 *)DAT_02900a50[1] = DAT_029110ac;
      }
      DAT_029110ac[1] = puVar1[1];
      *DAT_029110ac = 0;
      puVar1[3] = *puVar1;
      puVar1[1] = DAT_029110ac;
      DAT_02900c84 = DAT_029110ac;
      puVar1[4] = 0;
      DAT_02900a58 = DAT_029110ac[0xf];
      DAT_029110ac[0xf] = FUN_00623a20;
      DAT_02900c84 = (undefined4 *)FUN_00627a80(1,&local_10,0,0,FUN_00623ca0,"R:?? G:?? B:??");
      puVar1 = DAT_02900a50;
      if ((undefined4 *)DAT_02900a50[1] == (undefined4 *)0x0) {
        *DAT_02900a50 = DAT_02900c84;
      }
      else {
        *(undefined4 *)DAT_02900a50[1] = DAT_02900c84;
      }
      DAT_02900c84[1] = puVar1[1];
      *DAT_02900c84 = 0;
      puVar1[1] = DAT_02900c84;
      puVar1[3] = *puVar1;
      DAT_02910c90 = DAT_02900c84;
      puVar1[4] = 0;
      DAT_02900c84 = (undefined4 *)FUN_00627a80(1,&local_10,0,0,FUN_00623ae0,"Copy To Clipboard");
      puVar1 = DAT_02900a50;
      if ((undefined4 *)DAT_02900a50[1] == (undefined4 *)0x0) {
        *DAT_02900a50 = DAT_02900c84;
      }
      else {
        *(undefined4 *)DAT_02900a50[1] = DAT_02900c84;
      }
      DAT_02900c84[1] = puVar1[1];
      *DAT_02900c84 = 0;
      puVar1[1] = DAT_02900c84;
      puVar1[3] = *puVar1;
      _DAT_02912128 = DAT_02900c84;
      puVar1[4] = 0;
      DAT_029110b4 = (undefined4 *)FUN_00627a80(1,&local_10,0,0,FUN_00623b70,"Paste From Clipboard")
      ;
      puVar1 = DAT_02900a50;
      if ((undefined4 *)DAT_02900a50[1] == (undefined4 *)0x0) {
        *DAT_02900a50 = DAT_029110b4;
      }
      else {
        *(undefined4 *)DAT_02900a50[1] = DAT_029110b4;
      }
      DAT_029110b4[1] = puVar1[1];
      *DAT_029110b4 = 0;
      puVar1[1] = DAT_029110b4;
      puVar1[3] = *puVar1;
      DAT_02900c84 = DAT_029110b4;
      puVar1[4] = 0;
    }
  }
  return;
}

