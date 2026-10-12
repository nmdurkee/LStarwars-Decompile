/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x6057c0; label: FUN_006057c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006057c0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_005e5310(param_1);
  if (0xf < (uint)((iVar1 + -0x2855050) / 0x30)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0x28);
}

