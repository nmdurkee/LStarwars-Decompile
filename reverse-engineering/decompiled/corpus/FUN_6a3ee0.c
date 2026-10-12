/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3ee0; label: FUN_006a3ee0
 */

void FUN_006a3ee0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x210);
    _free(param_1);
  }
  return;
}

