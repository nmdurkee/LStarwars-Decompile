/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575f10; label: FUN_00575f10
 */

void FUN_00575f10(int param_1)

{
  if ((param_1 != 0) && (param_1 != DAT_0095142c)) {
    FUN_004f1f10(&DAT_009513b8,param_1);
    FUN_00575820();
    DAT_0095142c = param_1;
    DAT_009513b0 = param_1;
  }
  return;
}

