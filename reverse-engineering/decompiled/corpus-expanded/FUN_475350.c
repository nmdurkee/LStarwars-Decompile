/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475350; label: FUN_00475350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00475350(void)

{
  int iVar1;
  undefined4 *in_EDX;
  
  iVar1 = *(int *)(&PTR_DAT_007fa100)[DAT_007fa188];
  if ((iVar1 == 0) || ((&DAT_0086e0f4)[(uint)*(byte *)(iVar1 + 0x7c) * 0xc] == '\0')) {
    if (in_EDX != (undefined4 *)0x0) {
      *in_EDX = 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

