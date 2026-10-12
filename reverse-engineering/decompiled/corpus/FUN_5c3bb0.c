/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c3bb0; label: FUN_005c3bb0
 */

void FUN_005c3bb0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005f7c60(param_1,param_2,&local_4,&local_8);
  FUN_00605b60(DAT_00973834,0,param_1,param_2);
  FUN_005f8bf0(DAT_00973834);
  FUN_005fa2f0(0,0,local_4,local_8);
  FUN_005c2760();
  FUN_005f7d00(param_3,2,2,1);
  FUN_005f7cc0(param_3,param_4,param_4);
  if (param_3 != 0) {
    piVar1 = (int *)FUN_005f8460(param_3);
    if ((DAT_0097f9b8 != *piVar1) || (DAT_0097f9bc != piVar1[1])) {
      uVar2 = FUN_005f8460(param_3);
      FUN_005fa540(0,uVar2);
    }
  }
  FUN_005f8550(param_3,0);
  if (param_6 != 0) {
    piVar1 = (int *)FUN_005f8460(param_6);
    if ((DAT_0097f9c0 != *piVar1) || (DAT_0097f9c4 != piVar1[1])) {
      uVar2 = FUN_005f8460(param_6);
      FUN_005fa540(1,uVar2);
    }
    FUN_005f8550(param_6,1);
  }
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005fb550();
  FUN_005f8ba0(0,1);
  return;
}

