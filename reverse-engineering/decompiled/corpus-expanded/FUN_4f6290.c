/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f6290; label: FUN_004f6290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6290(int param_1)

{
  int iVar1;
  
  if (param_1 < DAT_00915fa8) {
    iVar1 = DAT_0091ef38;
    if (0xf < DAT_0091ef38) {
      iVar1 = 0x10;
    }
    *(short *)(&DAT_00916fdc + iVar1 * 2) = *(short *)(&DAT_00916fdc + iVar1 * 2) + 1;
    return;
  }
  DAT_0091ef38 = DAT_0091ef38 + 1;
  FUN_004f6290(*(undefined2 *)(&DAT_02982740 + param_1 * 2));
  FUN_004f6290(*(undefined2 *)(&DAT_02982f40 + param_1 * 2));
  DAT_0091ef38 = DAT_0091ef38 + -1;
  return;
}

