/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4cf4c0; label: FUN_004cf4c0
 */

void FUN_004cf4c0(uint *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint local_128;
  undefined1 local_124 [32];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_128;
  local_128 = *param_1;
  FUN_0050c130(&LAB_004cf480);
  uVar1 = FUN_0054b5a0(DAT_0080235c);
  FUN_004f1f10(local_124,uVar1);
  FUN_004f1f10(local_104,"stuff\\text\\");
  FUN_004f1e80(local_104,local_124);
  FUN_004f1e80(local_104,&DAT_0075d39c);
  FUN_0054b7b0(local_104,&local_128,DAT_00926c20,0x70d);
  if (DAT_007f39e4 == 0) {
    FUN_004f1f10(local_104,"stuff\\text\\");
    FUN_004f1e80(local_104,local_124);
    FUN_004f1e80(local_104,"_api.txt");
    FUN_0054b7b0(local_104,&local_128,DAT_00926c20,0x70d);
  }
  else {
    FUN_0054bf00((int)DAT_00880f70);
  }
  *param_1 = local_128 + 3 & 0xfffffffc;
  if (*(int *)(DAT_00926c20 + DAT_00880874 * 4) != 0) {
    FUN_004f1f10(&DAT_0086e500,*(undefined4 *)(DAT_00926c20 + DAT_00880874 * 4));
  }
  if (*(int *)(DAT_00926c20 + DAT_00880878 * 4) != 0) {
    FUN_004f1f10(&DAT_0086e538,*(undefined4 *)(DAT_00926c20 + DAT_00880878 * 4));
  }
  FUN_00423900(0xffffffff);
  FUN_00423bc0(DAT_00856980);
  FUN_0050b4e0("stuff\\text\\trc.csv",local_124,param_1,*param_2);
  __security_check_cookie(local_4 ^ (uint)&local_128);
  return;
}

