/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x481db0; label: FUN_00481db0
 */

void FUN_00481db0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (iVar3 = *(int *)(param_1 + 0x50a8), iVar3 != 0)) &&
     (iVar4 = 0, 0 < *(int *)(param_1 + 0x50ac))) {
    do {
      FUN_00481c10();
      if ((param_3 != 0) && (iVar4 < 0x80)) {
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        *(byte *)(iVar3 + 0x17) =
             *(byte *)(iVar3 + 0x17) ^
             (((*(uint *)(param_3 + 0x10 + iVar1 * 4) & uVar2) != 0) * '\x02' ^
             *(byte *)(iVar3 + 0x17)) & 2;
        *(byte *)(iVar3 + 0x17) =
             ((*(uint *)(param_3 + iVar1 * 4) & uVar2) != 0 ^ *(byte *)(iVar3 + 0x17)) & 1 ^
             *(byte *)(iVar3 + 0x17);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar4 < *(int *)(param_1 + 0x50ac));
  }
  return;
}

