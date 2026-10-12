/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a2380; label: FUN_006a2380
 */

undefined4 FUN_006a2380(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_006a16b0(param_1,param_2,0);
  if (iVar1 != 0) {
    return 1;
  }
  FUN_006a2310(param_1);
  return 0;
}

