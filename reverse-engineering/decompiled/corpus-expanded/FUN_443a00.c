/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443a00; label: FUN_00443a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00443a00(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iStack0000000c;
  
  if (param_2 != 0) {
    iStack0000000c = param_2;
    param_1 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8);
    uVar1 = FUN_0055a020();
    return uVar1;
  }
  return 0;
}

