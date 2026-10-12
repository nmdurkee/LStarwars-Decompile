/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566ba0; label: FUN_00566ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566ba0(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) & 0xfeff7ffe | 0x804000;
  *(undefined1 *)(unaff_ESI + 0x110) = *(undefined1 *)(unaff_ESI + 0x111);
  *(undefined1 *)(unaff_ESI + 0x10e) = *(undefined1 *)(unaff_ESI + 0x10f);
  iVar1 = FUN_005d0420(*(int *)(unaff_ESI + 0xa4) + 0x30);
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x50) & 1) != 0)) {
    *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x100000;
    if ((*(byte *)(iVar1 + 0x50) & 8) != 0) {
      *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x480000;
    }
  }
  *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x10000;
  return;
}

