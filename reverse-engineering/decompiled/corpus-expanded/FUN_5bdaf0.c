/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bdaf0; label: FUN_005bdaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bdaf0(undefined1 *param_1,int param_2)

{
  int local_15c;
  undefined1 local_158 [56];
  undefined1 local_120;
  undefined1 local_11f;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_15c;
  local_15c = 0;
  if (param_2 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_15c);
    return;
  }
  FUN_004fb550(param_2,&local_15c,4);
  if (local_15c < 2) {
    FUN_004fb550(param_2,local_158,0x154);
    *(undefined4 *)(param_1 + 0x4c) = local_14;
    *(undefined4 *)(param_1 + 0x50) = local_10;
    param_1[1] = local_11f;
    *param_1 = local_120;
    *(undefined4 *)(param_1 + 0x54) = local_c;
    *(undefined4 *)(param_1 + 0x58) = local_8;
    *(undefined4 *)(param_1 + 0x44) = local_1c;
    *(undefined4 *)(param_1 + 0x48) = local_18;
    *(undefined4 *)(param_1 + 4) = local_11c;
    *(undefined4 *)(param_1 + 0x24) = local_9c;
    *(undefined4 *)(param_1 + 8) = local_118;
    *(undefined4 *)(param_1 + 0x28) = local_98;
    *(undefined4 *)(param_1 + 0xc) = local_114;
    *(undefined4 *)(param_1 + 0x2c) = local_94;
    *(undefined4 *)(param_1 + 0x10) = local_110;
    *(undefined4 *)(param_1 + 0x30) = local_90;
    *(undefined4 *)(param_1 + 0x14) = local_10c;
    *(undefined4 *)(param_1 + 0x34) = local_8c;
    *(undefined4 *)(param_1 + 0x18) = local_108;
    *(undefined4 *)(param_1 + 0x38) = local_88;
    *(undefined4 *)(param_1 + 0x1c) = local_104;
    *(undefined4 *)(param_1 + 0x3c) = local_84;
    *(undefined4 *)(param_1 + 0x20) = local_100;
    *(undefined4 *)(param_1 + 0x40) = local_80;
    __security_check_cookie(local_4 ^ (uint)&local_15c);
    return;
  }
  FUN_004fb550(param_2,param_1,0x5c);
  __security_check_cookie(local_4 ^ (uint)&local_15c);
  return;
}

