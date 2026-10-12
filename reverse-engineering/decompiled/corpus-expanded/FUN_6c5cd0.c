/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5cd0; label: FUN_006c5cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c5cd0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[3] != 0) {
      (**(code **)(*(int *)puVar1[3] + 8))(param_1);
    }
  }
  return 0;
}

