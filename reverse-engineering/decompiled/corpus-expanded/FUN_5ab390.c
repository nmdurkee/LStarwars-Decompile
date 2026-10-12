/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab390; label: FUN_005ab390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab390(int param_1,byte param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 0) && (2 < param_2)) {
    puVar2 = *(undefined4 **)(param_1 + 0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = &param_1;
    }
    if (4 < DAT_00805e28) {
      uVar1 = FUN_006218c0();
      *(undefined1 *)puVar2 = uVar1;
      uVar1 = FUN_006218c0();
      *(undefined1 *)((int)puVar2 + 1) = uVar1;
      return;
    }
    uVar1 = FUN_00621860();
    *(undefined1 *)puVar2 = uVar1;
  }
  return;
}

