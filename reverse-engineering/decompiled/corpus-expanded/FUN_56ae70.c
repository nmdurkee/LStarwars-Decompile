/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56ae70; label: FUN_0056ae70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056ae70(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x50c8);
    if ((iVar4 != 0) && (local_4 = 0, 0 < *(int *)(param_1 + 0x50c0))) {
      do {
        FUN_00566ba0();
        if ((param_3 != 0) && (local_4 < 0x200)) {
          iVar5 = (int)(local_4 + (local_4 >> 0x1f & 0x1fU)) >> 5;
          uVar3 = 1 << ((byte)local_4 & 0x1f);
          *(uint *)(iVar4 + 0x94) =
               *(uint *)(iVar4 + 0x94) ^
               ((uint)((*(uint *)(param_3 + iVar5 * 4) & uVar3) != 0) ^ *(uint *)(iVar4 + 0x94)) & 1
          ;
          uVar1 = *(uint *)(iVar4 + 0x94);
          uVar2 = ((uint)((*(uint *)(param_3 + 0x80 + iVar5 * 4) & uVar3) != 0) * 0x4000 ^ uVar1) &
                  0x4000 ^ uVar1;
          *(uint *)(iVar4 + 0x94) = uVar2;
          if ((uVar1 >> 0xe & 1) == 0) {
            if ((uVar2 & 0x4000) != 0) {
              FUN_00568580(iVar4);
            }
          }
          else if ((uVar2 & 0x4000) == 0) {
            FUN_00568710(iVar4);
          }
          *(uint *)(iVar4 + 0x94) =
               *(uint *)(iVar4 + 0x94) ^
               ((uint)((*(uint *)(param_3 + 0x40 + iVar5 * 4) & uVar3) != 0) * 0x800000 ^
               *(uint *)(iVar4 + 0x94)) & 0x800000;
          *(uint *)(iVar4 + 0x94) =
               ((uint)((*(uint *)(param_3 + 0xc0 + iVar5 * 4) & uVar3) != 0) * 0x10000000 ^
               *(uint *)(iVar4 + 0x94)) & 0x10000000 ^ *(uint *)(iVar4 + 0x94);
        }
        if ((*(byte *)(iVar4 + 0x94) & 1) != 0) {
          *(undefined4 *)(iVar4 + 0xbc) = 0;
        }
        local_4 = local_4 + 1;
        iVar4 = iVar4 + 0x114;
      } while (local_4 < *(int *)(param_1 + 0x50c0));
    }
    FUN_00568760();
    FUN_005686a0();
    return;
  }
  return;
}

