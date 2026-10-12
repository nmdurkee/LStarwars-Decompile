/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50ed50; label: FUN_0050ed50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ed50(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  local_44[0x20] = '\0';
  local_44[0x21] = '\0';
  local_44[0x22] = '\0';
  local_44[0x23] = '\0';
  local_44[0x24] = '\0';
  local_44[0x25] = '\0';
  local_44[0x26] = '\0';
  local_44[0x27] = '\0';
  local_44[0x28] = '\0';
  local_44[0x29] = '\0';
  local_44[0x2a] = '\0';
  local_44[0x2b] = '\0';
  local_44[0x2c] = '\0';
  local_44[0x2d] = '\0';
  local_44[0x2e] = '\0';
  local_44[0x2f] = '\0';
  local_44[0x30] = '\0';
  local_44[0x31] = '\0';
  local_44[0x32] = '\0';
  local_44[0x33] = '\0';
  local_44[0x34] = '\0';
  local_44[0x35] = '\0';
  local_44[0x36] = '\0';
  local_44[0x37] = '\0';
  local_44[0x38] = '\0';
  local_44[0x39] = '\0';
  local_44[0x3a] = '\0';
  local_44[0x3b] = '\0';
  local_44[0x3c] = '\0';
  local_44[0x3d] = '\0';
  local_44[0x3e] = '\0';
  local_44[0x3f] = 0;
  local_44[0] = '\0';
  local_44[1] = '\0';
  local_44[2] = '\0';
  local_44[3] = '\0';
  local_44[4] = '\0';
  local_44[5] = '\0';
  local_44[6] = '\0';
  local_44[7] = '\0';
  local_44[8] = '\0';
  local_44[9] = '\0';
  local_44[10] = '\0';
  local_44[0xb] = '\0';
  local_44[0xc] = '\0';
  local_44[0xd] = '\0';
  local_44[0xe] = '\0';
  local_44[0xf] = '\0';
  local_44[0x10] = '\0';
  local_44[0x11] = '\0';
  local_44[0x12] = '\0';
  local_44[0x13] = '\0';
  local_44[0x14] = '\0';
  local_44[0x15] = '\0';
  local_44[0x16] = '\0';
  local_44[0x17] = '\0';
  local_44[0x18] = '\0';
  local_44[0x19] = '\0';
  local_44[0x1a] = '\0';
  local_44[0x1b] = '\0';
  local_44[0x1c] = '\0';
  local_44[0x1d] = '\0';
  local_44[0x1e] = '\0';
  local_44[0x1f] = 0;
  iVar1 = FUN_004f48e0(0);
  iVar2 = FUN_004f48e0(1);
  if ((param_2 != 0) && (-1 < iVar1)) {
    uVar3 = FUN_006da3d0(iVar1,param_1,0,0);
    FUN_004f1f10(local_44 + 0x20,uVar3);
  }
  if ((param_3 != 0) && (-1 < iVar2)) {
    uVar3 = FUN_006da3d0(iVar2,param_1,0,0);
    FUN_004f1f10(local_44,uVar3);
  }
  if ((local_44[0x20] == '\0') || (local_44[0] == '\0')) {
    pcVar4 = "~0%s%s~~";
  }
  else {
    pcVar4 = "~0%s~~ \\ ~0%s~~";
  }
  FUN_004f2740(&DAT_008016a8,pcVar4,local_44 + 0x20,local_44);
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

