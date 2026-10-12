/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639b10; label: FUN_00639b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639b10(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(param_1 + 0xd0);
    iVar2 = 0x20;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 9;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined4 *)(param_1 + 0x550) = 0;
    *(undefined4 *)(param_1 + 0x554) = 0xffffffff;
  }
  return;
}

