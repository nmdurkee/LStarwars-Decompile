/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x491170; label: FUN_00491170
 */

void FUN_00491170(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (iVar4 = *(int *)(param_1 + 0x5068), iVar4 != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x506c))) {
    do {
      FUN_00491010();
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        if ((*(uint *)(param_3 + iVar1 * 4) & uVar2) != 0) {
          *(ushort *)(iVar4 + 0x94) = *(ushort *)(iVar4 + 0x94) | 2;
          *(undefined4 *)(iVar4 + 0x78) = 0x3f800000;
          *(undefined2 *)(iVar4 + 0x8e) = 0x8000;
        }
        *(ushort *)(iVar4 + 0x94) =
             *(ushort *)(iVar4 + 0x94) ^
             (byte)(((*(uint *)(param_3 + 8 + iVar1 * 4) & uVar2) != 0) * '\x10' ^
                   *(byte *)(iVar4 + 0x94)) & 0x10;
        *(ushort *)(iVar4 + 0x94) =
             (byte)(((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar2) != 0) * -0x80 ^
                   (byte)*(ushort *)(iVar4 + 0x94)) & 0x80 ^ *(ushort *)(iVar4 + 0x94);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xa0;
    } while (iVar3 < *(int *)(param_1 + 0x506c));
  }
  return;
}

