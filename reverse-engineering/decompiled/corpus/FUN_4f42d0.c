/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f42d0; label: FUN_004f42d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f42d0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (&DAT_0297e044)[param_1 * 3];
  if (-1 < iVar1) {
    if (param_2 == 0) {
      (&DAT_0297e048)[param_1 * 3] = 0;
      (&DAT_00917004)[iVar1 * 0x21] = 0xffffffff;
      return;
    }
    (&DAT_00917004)[iVar1 * 0x21] = param_1;
  }
  if (param_2 == 1) {
    if (DAT_0091ef30 == 0) {
      _DAT_00800518 = iVar1;
    }
    DAT_0091ef30 = 1;
  }
  (&DAT_0297e048)[param_1 * 3] = param_2;
  return;
}

