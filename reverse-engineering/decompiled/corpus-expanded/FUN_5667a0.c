/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x5667a0; label: FUN_005667a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005667a0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50e8) = 0;
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0x7fU & 0xffffff80;
  iVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,0x8000);
  *(int *)(param_1 + 0x50e8) = iVar1;
  return iVar1 != 0;
}

