/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a2380; label: FUN_006a2380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

