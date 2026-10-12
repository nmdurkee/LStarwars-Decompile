/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e720; label: FUN_0059e720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e720(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00956430 < 0x20) {
    iVar1 = FUN_004f9e70(param_1);
    if (iVar1 < 0) {
      FUN_0059e450();
      return;
    }
    (&DAT_00956350)[DAT_00956430] = iVar1;
    DAT_00956430 = DAT_00956430 + 1;
  }
  return;
}

