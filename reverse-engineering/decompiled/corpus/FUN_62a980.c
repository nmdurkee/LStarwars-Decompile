/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a980; label: FUN_0062a980
 */

void FUN_0062a980(int *param_1)

{
  if (param_1 != (int *)0x0) {
    _memset((void *)param_1[1],0,*param_1 << 6);
  }
  return;
}

