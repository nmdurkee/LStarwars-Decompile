/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54bf20; label: FUN_0054bf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054bf20(float param_1)

{
  undefined1 auStack_110 [4];
  longlong local_10c;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_110;
  if (DAT_00802368 != -1) {
    FUN_0050e6a0();
    FUN_005d0910(DAT_00921e8c,0x41000000);
    FUN_0050c100(*(undefined4 *)(DAT_00926c20 + DAT_00802368 * 4),local_104);
    FUN_005d0ee0(0x3f800000,0x3f800000);
    local_10c = (longlong)ROUND(param_1 * 128.0);
    FUN_005f69c0(DAT_00921e8c,local_104,0xbf59999a,_DAT_00802370,0x3f800000,_DAT_0080236c,
                 _DAT_0080236c,0x3fd9999a,0x3f800000,(int)local_10c << 0x18 | 0x7f5f00,0);
  }
  __security_check_cookie(local_4 ^ (uint)auStack_110);
  return;
}

