/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402c30; label: FUN_00402c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00402c30(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (((param_1 != 0) && (iVar4 = *(int *)(param_1 + 0x5098), iVar4 != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x509c))) {
    do {
      FUN_00402b80();
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        *(undefined1 *)(iVar4 + 0x5f) = *(undefined1 *)(iVar3 + param_3);
        uVar5 = 1 << ((byte)iVar3 & 0x1f);
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        *(byte *)(iVar4 + 0x62) =
             *(byte *)(iVar4 + 0x62) ^
             (((*(uint *)(param_3 + 0x20 + iVar1 * 4) & uVar5) != 0) * '\x02' ^
             *(byte *)(iVar4 + 0x62)) & 2;
        bVar2 = ((*(uint *)(param_3 + 0x24 + iVar1 * 4) & uVar5) != 0 ^ *(byte *)(iVar4 + 0x62)) & 1
                ^ *(byte *)(iVar4 + 0x62);
        *(byte *)(iVar4 + 0x62) = bVar2;
        *(byte *)(iVar4 + 0x62) =
             (((*(uint *)(param_3 + 0x28 + iVar1 * 4) & uVar5) != 0) * '\x04' ^ bVar2) & 4 ^ bVar2;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x74;
    } while (iVar3 < *(int *)(param_1 + 0x509c));
  }
  return;
}

