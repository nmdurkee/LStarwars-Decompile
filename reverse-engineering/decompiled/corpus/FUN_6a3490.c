/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3490; label: FUN_006a3490
 */

void FUN_006a3490(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  puVar1 = _malloc(0x100);
  param_1[2] = puVar1;
  param_1[3] = puVar1;
  *puVar1 = 0;
  param_1[4] = 0x100;
  return;
}

