/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566730; label: FUN_00566730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00566730(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50c8) = 0;
  *(undefined4 *)(param_1 + 0x50c0) = 0;
  if (*(short *)(*(int *)(param_1 + 0x128) + 0xda) == 0) {
    return false;
  }
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
  iVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,
                       (uint)*(ushort *)(*(int *)(param_1 + 0x128) + 0xda) * 0x114);
  *(int *)(param_1 + 0x50c8) = iVar1;
  return iVar1 != 0;
}

