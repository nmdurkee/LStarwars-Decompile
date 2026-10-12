/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5dd0; label: FUN_006d5dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d5dd0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f48e0(param_1);
  if ((iVar1 != 10) && (iVar1 != 0xc)) {
    return 0;
  }
  return 1;
}

