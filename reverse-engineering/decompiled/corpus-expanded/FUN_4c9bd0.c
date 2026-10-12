/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9bd0; label: FUN_004c9bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9bd0(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_c8;
  undefined1 local_c4 [128];
  undefined1 local_44 [64];
  uint local_4;
  
  iVar1 = DAT_009248ac;
  local_4 = DAT_00829570 ^ (uint)&local_c8;
  if ((DAT_00880570 == 0) && (DAT_00880574 == 0)) {
    local_c8 = DAT_009248ac + -0x400000;
    DAT_0080235c = FUN_004f5240();
    if (DAT_007f39e4 == 0) {
      FUN_004f1f10(local_c4,"stuff\\legal\\");
      FUN_004f1e80(local_c4,"pc\\pc_");
      FUN_004f1e80(local_c4,"legal");
      if ((DAT_009250b0 != 0) || ((DAT_0080235c != 1 && (DAT_0080235c != 0x12)))) {
        FUN_004f1e80(local_c4,&DAT_0075cff4);
        uVar2 = FUN_0054b5a0(DAT_0080235c);
        FUN_004f1e80(local_c4,uVar2);
      }
    }
    else {
      FUN_004f1f10(local_c4,"stuff\\legal\\");
      FUN_004c9b20();
      FUN_004f1e80(local_c4,local_44);
    }
    FUN_004f1e80(local_c4,&DAT_0075d014);
    DAT_00880570 = FUN_005f8d60(local_c4,&local_c8,iVar1);
    DAT_00880574 = 1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_c8);
  return;
}

