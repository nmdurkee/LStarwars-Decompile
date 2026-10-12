/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fa2c0; label: FUN_004fa2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fa2c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 < 0x400) || (0x7ff < iVar1)) {
    if ((*(char *)(param_1 + 8) == '\0') || (iVar1 == 0)) {
      iVar1 = FUN_004ef790();
    }
    FUN_004f99e0(iVar1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

