/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3db0; label: FUN_006a3db0
 */

int FUN_006a3db0(int *param_1)

{
  return ((int)(param_1[1] + 7 + (param_1[1] + 7 >> 0x1f & 7U)) >> 3) + *param_1;
}

