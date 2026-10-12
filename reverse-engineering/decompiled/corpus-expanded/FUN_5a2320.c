/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2320; label: FUN_005a2320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a2320(void)

{
  undefined4 extraout_ECX;
  int *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = unaff_EDI * 0x80 + (*unaff_ESI + 0x7fU & 0xffffff80);
  FUN_005a2250();
  DAT_00956628 = *unaff_ESI + 3U & 0xfffffffc;
  *unaff_ESI = DAT_00956628 + unaff_EDI * 4;
  return extraout_ECX;
}

