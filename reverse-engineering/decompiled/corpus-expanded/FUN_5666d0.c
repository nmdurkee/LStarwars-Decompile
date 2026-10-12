/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x5666d0; label: FUN_005666d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005666d0(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x50c4) = 0;
  *(undefined4 *)(param_1 + 0x50bc) = 0;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x128) + 0xdc);
  if (uVar1 == 0) {
    return false;
  }
  iVar2 = FUN_00552670(param_1 + 0x104,param_1 + 0x108,(uint)uVar1 << 8);
  *(int *)(param_1 + 0x50c4) = iVar2;
  return iVar2 != 0;
}

