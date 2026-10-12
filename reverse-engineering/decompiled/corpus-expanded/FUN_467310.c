/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467310; label: FUN_00467310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00467310(void)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_4;
  
  local_4 = 0x3f800000;
  if (((unaff_EDI != 0) && (local_4 = 0x3f800000, unaff_ESI != 0)) &&
     ((iVar1 = FUN_0056e0f0(0x400000), iVar1 != 0 || (0.0 < *(float *)(unaff_ESI + 0xdec))))) {
    local_4 = 0x40400000;
  }
  FUN_0054fb40(*(undefined4 *)(unaff_EDI + 0x58),local_4,_DAT_007f8d60);
  return;
}

