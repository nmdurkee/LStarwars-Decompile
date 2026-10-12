/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x4668b0; label: FUN_004668b0
 */

void FUN_004668b0(int param_1)

{
  int iVar1;
  
  DAT_00877ad8 = 0;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    DAT_00877ad8 = FUN_00466840(*(undefined4 *)(param_1 + 0x510));
  }
  return;
}

