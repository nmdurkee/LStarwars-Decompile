/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x599a40; label: FUN_00599a40
 */

void FUN_00599a40(undefined4 *param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0xff;
  *(short *)((int)param_1 + 10) = (short)param_2;
  if (param_2 != -1) {
    FUN_004f1f10(local_104,"chars\\minikits\\");
    FUN_004f1e80(local_104,*(undefined4 *)(param_2 * 0x4c + 0xc + DAT_0093b274));
    FUN_004f1e80(local_104,&DAT_0075a204);
    FUN_004f1e80(local_104,*(undefined4 *)(param_2 * 0x4c + 0xc + DAT_0093b274));
    FUN_004f1e80(local_104,&DAT_0075a1fc);
    *param_3 = *param_3 + 3 & 0xfffffffc;
    uVar1 = FUN_005ef7f0(param_3,*param_4,local_104);
    *param_1 = uVar1;
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

