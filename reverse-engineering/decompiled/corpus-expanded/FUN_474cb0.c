/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474cb0; label: FUN_00474cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00474cb0(void)

{
  int *in_EAX;
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *in_EAX;
  while (iVar1 != 0) {
    iVar1 = FUN_0055a020(*(undefined4 *)(unaff_EDI + 0x2ac8),0xffffffff,in_EAX[1]);
    in_EAX[9] = iVar1;
    iVar1 = FUN_0055a020(*(undefined4 *)(unaff_EDI + 0x2ac8),0xffffffff,in_EAX[3]);
    in_EAX[0xd] = iVar1;
    iVar1 = FUN_0055a020(*(undefined4 *)(unaff_EDI + 0x2ac8),0xffffffff,in_EAX[4]);
    in_EAX[0xe] = iVar1;
    iVar1 = FUN_00573430(*in_EAX,0);
    in_EAX[8] = iVar1;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x13c),in_EAX + 10,in_EAX[2],1);
    in_EAX = in_EAX + 0xf;
    iVar1 = *in_EAX;
  }
  return;
}

