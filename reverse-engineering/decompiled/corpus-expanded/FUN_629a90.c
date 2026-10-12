/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629a90; label: FUN_00629a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00629a90(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  FUN_005d0a40(1);
  FUN_005d0fe0(DAT_009738b8,_DAT_0080f510,_DAT_0080f510);
  DAT_02912e70 = (undefined4 *)
                 FUN_00619250(0xdc,0x32,0xb4,0x140,DAT_02912e80,FUN_00629a80,"Editor Config");
  if (DAT_02912e70 != (undefined4 *)0x0) {
    DAT_02900c84 = (undefined4 *)
                   FUN_00625150(0,&DAT_0080f514,0,&LAB_006240d0,0x3f800000,0x41a00000,_DAT_0080f534,
                                "Camera Speed");
    puVar1 = DAT_02912e70;
    if ((undefined4 *)DAT_02912e70[1] == (undefined4 *)0x0) {
      *DAT_02912e70 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912e70[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar1[1];
    *DAT_02900c84 = 0;
    puVar1[1] = DAT_02900c84;
    puVar1[3] = *puVar1;
    puVar1[4] = 0;
    DAT_02900c84 = (undefined4 *)
                   FUN_00627a80(0,&DAT_0080f514,DAT_0080f538,1,FUN_00624110,
                                "Proportional Cursor Speed");
    if (DAT_02900c84 != (undefined4 *)0x0) {
      DAT_02900c84[2] = 3;
      DAT_02900c84[0xf] = FUN_00624590;
      DAT_02900c84[0x10] = FUN_00619a40;
    }
    puVar1 = DAT_02912e70;
    if ((undefined4 *)DAT_02912e70[1] == (undefined4 *)0x0) {
      *DAT_02912e70 = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912e70[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar1[1];
    *DAT_02900c84 = 0;
    puVar1[1] = DAT_02900c84;
    puVar1[3] = *puVar1;
    puVar1[4] = 0;
    FUN_006242b0(puVar1,8);
  }
  DAT_02912e6c = (undefined4 *)
                 FUN_00619250(DAT_0080f524,DAT_0080f528,DAT_0080f52c,DAT_0080f530,DAT_02912e80,
                              FUN_00617f40,"Editor Options");
  puVar1 = DAT_02912e60;
  if (DAT_02912e6c != (undefined4 *)0x0) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      puVar3 = (undefined4 *)FUN_00627a80(puVar1,&DAT_0080f514,0,1,&LAB_00617f10,puVar1[2]);
      puVar2 = DAT_02912e6c;
      if ((undefined4 *)DAT_02912e6c[1] == (undefined4 *)0x0) {
        *DAT_02912e6c = puVar3;
      }
      else {
        *(undefined4 *)DAT_02912e6c[1] = puVar3;
      }
      bVar4 = puVar1 == DAT_02912e64;
      puVar3[1] = puVar2[1];
      *puVar3 = 0;
      puVar2[1] = puVar3;
      puVar2[3] = *puVar2;
      DAT_02900c84 = puVar3;
      puVar2[4] = 0;
      if (bVar4) {
        FUN_006193e0(puVar2,puVar3);
      }
    }
    DAT_02900c84 = (undefined4 *)FUN_00627a80(0,&DAT_0080f514,0,0,FUN_00629a30,"Editor Config");
    puVar1 = DAT_02912e6c;
    if ((undefined4 *)DAT_02912e6c[1] == (undefined4 *)0x0) {
      *DAT_02912e6c = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912e6c[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar1[1];
    *DAT_02900c84 = 0;
    puVar1[1] = DAT_02900c84;
    puVar1[3] = *puVar1;
    puVar1[4] = 0;
    DAT_02900c84 = (undefined4 *)FUN_00627a80(0,&DAT_0080f514,0,0,FUN_00617f50,"Return To App");
    puVar1 = DAT_02912e6c;
    if ((undefined4 *)DAT_02912e6c[1] == (undefined4 *)0x0) {
      *DAT_02912e6c = DAT_02900c84;
    }
    else {
      *(undefined4 *)DAT_02912e6c[1] = DAT_02900c84;
    }
    DAT_02900c84[1] = puVar1[1];
    *DAT_02900c84 = 0;
    puVar1[1] = DAT_02900c84;
    puVar1[3] = *puVar1;
    puVar1[4] = 0;
    FUN_006242b0(puVar1,8);
  }
  FUN_005d0a70();
  return;
}

