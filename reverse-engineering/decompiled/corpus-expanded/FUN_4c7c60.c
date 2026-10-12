/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7c60; label: FUN_004c7c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c7c60(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (((param_1 != 0) && (iVar4 = *(int *)(param_1 + 0x5060), iVar4 != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x5064))) {
    do {
      FUN_004c7b20();
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        iVar5 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        if (*(char *)(param_3 + iVar3) != '\0') {
          uVar1 = FUN_004cc950(*(char *)(param_3 + iVar3));
          *(undefined4 *)(iVar4 + 0x80) = uVar1;
        }
        FUN_004c7a90((*(uint *)(param_3 + 0x24 + iVar5 * 4) & uVar2) != 0);
        *(byte *)(iVar4 + 0x6a) =
             *(byte *)(iVar4 + 0x6a) ^
             (((*(uint *)(param_3 + 0x20 + iVar5 * 4) & uVar2) != 0) * '\x02' ^
             *(byte *)(iVar4 + 0x6a)) & 2;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x94;
    } while (iVar3 < *(int *)(param_1 + 0x5064));
  }
  return;
}

