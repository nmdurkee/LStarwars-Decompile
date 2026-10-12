/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x4746d0; label: FUN_004746d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004746d0(int *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) &&
     (*(byte *)(iVar1 + 99) =
           *(byte *)(iVar1 + 99) ^ ((param_2 != 0) * '\b' ^ *(byte *)(iVar1 + 99)) & 8, param_2 != 0
     )) {
    FUN_00472b80();
  }
  return;
}

