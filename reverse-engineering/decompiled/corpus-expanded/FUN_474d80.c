/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474d80; label: FUN_00474d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00474d80(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = 0;
  bVar3 = 0;
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar1 = 0;
    do {
      if (*(undefined4 **)((int)&DAT_007f939c + iVar1) != (undefined4 *)0x0) {
        if ((DAT_0086e4e4 & (byte)(1 << (bVar3 & 0x1f))) != 0) {
          FUN_00590da0(**(undefined4 **)((int)&DAT_007f939c + iVar1));
        }
        bVar3 = bVar3 + 1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar2 * 0xf] != (undefined *)0x0);
  }
  if (((DAT_0086e4e4 & 0x80) != 0) && (DAT_0087a96c != (undefined4 *)0x0)) {
    FUN_00590da0(*DAT_0087a96c);
  }
  return;
}

