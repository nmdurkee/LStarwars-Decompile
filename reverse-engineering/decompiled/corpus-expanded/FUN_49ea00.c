/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49ea00; label: FUN_0049ea00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ea00(int param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (*(short *)(param_1 + 0x1064) == DAT_007f17d4) {
    iVar1 = FUN_0062df80((int)DAT_007f17c4);
    if ((iVar1 != 0) && (*(int *)(*(int *)(iVar1 + 0xc) + 0xb8) != 0)) {
      *unaff_EDI = 0x3f19999a;
      *unaff_ESI = 0x3f19999a;
      return;
    }
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f17c0) {
    *unaff_EDI = 0x3f800000;
    *unaff_ESI = 0x3f800000;
    return;
  }
  *unaff_EDI = _DAT_00804dc4;
  *unaff_ESI = _DAT_00804dc8;
  return;
}

