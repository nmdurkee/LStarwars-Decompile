/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5ddd10; label: FUN_005ddd10
 */

void FUN_005ddd10(int param_1)

{
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  
  if ((param_1 != 0) || ((*(byte *)(unaff_ESI + 0x74) & 6) != 0)) {
    if (*(int *)(unaff_ESI + 0x4c) != 0) {
      FUN_004ef6e0(*(undefined4 *)(unaff_ESI + 0x58 + (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4),
                   0,((int)(*(int *)(unaff_ESI + 0x4c) + 7U >> 3) >> 4) + 1);
    }
    if (*(int *)(unaff_ESI + 0x10) != 0) {
      iVar1 = *(int *)(unaff_ESI + 0x10) + 7;
      iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) * 2;
      iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 0xfU)) >> 4) + 1;
      FUN_004ef6e0(*(undefined4 *)(unaff_ESI + 0x30 + (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4),
                   0,iVar1);
      if (param_1 != 0) {
        FUN_004ef6e0(*(undefined4 *)
                      (unaff_ESI + 0x30 + (~(*(uint *)(unaff_ESI + 0x74) >> 0xf) & 1) * 4),0xff,
                     iVar1);
      }
    }
    uVar2 = 0;
    if (*(int *)(unaff_ESI + 0x4c) != 0) {
      do {
        iVar1 = *(int *)(*(int *)(unaff_ESI + 0x54) + uVar2 * 4);
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
        if (param_1 == 0) {
          *(uint *)(iVar1 + 0x34) = (uint)(*(int *)(iVar1 + 0x34) == 0);
        }
        else {
          *(undefined4 *)(iVar1 + 0x34) = 0;
        }
        *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0x28 + *(int *)(iVar1 + 0x34) * 4);
        FUN_005fca40(*(undefined4 *)(iVar1 + 8));
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(unaff_ESI + 0x4c));
    }
    *(uint *)(unaff_ESI + 0x74) = *(uint *)(unaff_ESI + 0x74) & 0xfffffff1;
  }
  return;
}

