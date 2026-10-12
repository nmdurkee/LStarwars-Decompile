/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547ba0; label: FUN_00547ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00547ba0(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)(param_1 + 0x471c);
  iVar2 = 0x40;
  do {
    *puVar1 = 0xffff;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x4b10) = 0;
  return;
}

