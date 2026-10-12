/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x489b60; label: FUN_00489b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00489b60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  FUN_0042abf0();
  FUN_00489aa0();
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,local_44,1);
  _DAT_0087aa50 = 0x3f800000;
  iVar1 = FUN_005cfac0(&DAT_0087aad8);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_005d0330(&DAT_0087aad8);
    puVar3 = &DAT_0087aef8;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005cfc00(&DAT_0087aad8,0);
    _DAT_0087a944 = _DAT_0087af28;
    _DAT_0087a948 = 0;
    _DAT_0087a94c = _DAT_0087af30 - 0.5;
  }
  _DAT_0087aa58 = 0x3f800000;
  if (DAT_0093b338 != 0) {
    DAT_0093b338 = 1;
  }
  FUN_004f4c10(0);
  if (DAT_0093b338 == 0) {
    DAT_00802bd8 = (int)DAT_007f1808;
    DAT_00802bdc = (int)DAT_007f180a;
  }
  FUN_00575450();
  _DAT_0087b6d4 = 0x3f800000;
  if (DAT_0093b338 == 0) {
    DAT_0093d526 = 0;
    DAT_0093d516 = 0;
    DAT_0087b5a0 = 0;
    _DAT_0087b734 = 0;
  }
  FUN_00564780();
  FUN_004898a0();
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

