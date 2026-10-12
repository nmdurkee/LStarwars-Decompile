/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x4123b0; label: FUN_004123b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004123b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_c [12];
  
  _DAT_00855e00 = 0;
  _DAT_00855e04 = 0;
  _DAT_00855e08 = 0;
  _DAT_00855e0c = 0x3f800000;
  _DAT_00855df8 = 0x4105c28f;
  FUN_005cf4a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c));
  iVar1 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,"Centre",1);
  if (iVar1 != 0) {
    iVar1 = FUN_005cfac0(local_c);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)FUN_005cf9c0(local_c);
      _DAT_00855e00 = *puVar2;
      _DAT_00855e04 = puVar2[1];
      _DAT_00855e08 = puVar2[2];
    }
  }
  return;
}

