/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f073e; label: FUN_006f073e
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006f073e(DWORD param_1)

{
  uint uVar1;
  
  Sleep(param_1);
  uVar1 = param_1 + 1000;
  if (DAT_0297c548 < uVar1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

