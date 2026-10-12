/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440940; label: FUN_00440940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440940(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014,0,1);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

