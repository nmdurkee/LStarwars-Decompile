/* Ghidra pseudocode, not original source.
 * ev_1a04cad52d858fc6066e427756d0dfdb4c6b3b835c22abe95c1d2aea9d549de8
 * Entry: 0x605110; label: FUN_00605110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00605110(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(in_ECX + 4);
  puVar2 = puVar1;
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (puVar2 <= param_1) {
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar1 = (undefined4 *)*puVar1;
    }
    if (param_1 < (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)puVar1)) {
      return CONCAT31((int3)((uint)puVar1 >> 8),1);
    }
  }
  return (uint)puVar1 & 0xffffff00;
}

