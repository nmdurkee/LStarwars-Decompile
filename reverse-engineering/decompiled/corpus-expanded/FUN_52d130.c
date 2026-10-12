/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52d130; label: FUN_0052d130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0052d130(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack0000000c;
  
  if (((param_1 != 0) && (*(char **)(param_1 + 0x10) != (char *)0x0)) &&
     (**(char **)(param_1 + 0x10) != '\0')) {
    uStack0000000c = param_2;
    uVar1 = FUN_0051ad80();
    return uVar1;
  }
  return 0;
}

