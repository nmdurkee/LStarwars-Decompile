/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x5667f0; label: FUN_005667f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005667f0(int param_1)

{
  undefined4 uVar1;
  
  FUN_005666d0(param_1);
  FUN_00566730(param_1);
  *(undefined4 *)(param_1 + 0x50e8) = 0;
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0x7fU & 0xffffff80;
  uVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,0x8000);
  *(undefined4 *)(param_1 + 0x50e8) = uVar1;
  return *(undefined4 *)(param_1 + 0x50c8);
}

