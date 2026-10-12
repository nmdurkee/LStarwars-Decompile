/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bd190; label: FUN_004bd190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004bd190(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (((param_1 != 0) && (iVar4 = *(int *)(param_1 + 0x50b0), iVar4 != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x50b4))) {
    do {
      FUN_004bd090();
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = 1 << ((byte)iVar3 & 0x1f);
        *(byte *)(iVar4 + 0xa2) =
             *(byte *)(iVar4 + 0xa2) ^
             (((*(uint *)(param_3 + iVar1 * 4) & uVar5) != 0) * '\x02' ^ *(byte *)(iVar4 + 0xa2)) &
             2;
        bVar2 = ((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar5) != 0 ^ *(byte *)(iVar4 + 0xa2)) & 1 ^
                *(byte *)(iVar4 + 0xa2);
        *(byte *)(iVar4 + 0xa2) = bVar2;
        bVar2 = (((*(uint *)(param_3 + 8 + iVar1 * 4) & uVar5) != 0) * '\x04' ^ bVar2) & 4 ^ bVar2;
        *(byte *)(iVar4 + 0xa2) = bVar2;
        if ((bVar2 & 4) != 0) {
          *(undefined4 *)(iVar4 + 0xb4) = 0x3f800000;
          *(undefined1 *)(iVar4 + 0xa3) = 2;
          FUN_004bce60(0x4000);
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xc0;
    } while (iVar3 < *(int *)(param_1 + 0x50b4));
  }
  return;
}

