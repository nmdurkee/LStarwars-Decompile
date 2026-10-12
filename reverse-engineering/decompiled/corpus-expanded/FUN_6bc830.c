/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc830; label: FUN_006bc830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006bc830(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  if ((param_1 != 0xffffffff) &&
     ((9 < param_1 ||
      ((uVar1 = *(uint *)(param_1 * 0xa8 + 0x350 + in_ECX), (uVar1 & 2) == 0 && ((uVar1 & 1) != 0)))
      ))) {
    return 0;
  }
  return 1;
}

