/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x600d00; label: FUN_00600d00
 */

void FUN_00600d00(int param_1,int *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint local_4;
  
  if ((*(int *)(param_1 + 0x110) == 0) ||
     ((*(uint *)(*(int *)(param_1 + 0x110) + 0x74) & 0x4000) == 0)) {
    local_4 = 0;
    if ((short)param_2[3] != 0) {
      do {
        sVar1 = *(short *)(*param_2 + local_4 * 2);
        uVar2 = (uint)sVar1;
        uVar6 = uVar2 >> 3;
        bVar4 = (&DAT_0280a2f0)[uVar6];
        bVar5 = (byte)sVar1 & 7;
        if ((bVar4 >> bVar5 & 1) == 0) {
          if ((*(byte *)(uVar6 + *(int *)(*(int *)(param_1 + 0x110) + 0x88)) >> bVar5 & 1) == 0) {
            if ((*(byte *)(uVar2 + *(int *)(*(int *)(param_1 + 0x110) + 0x48)) & 8) == 0) {
              iVar3 = FUN_005d94a0(uVar2 * 0x10 + *(int *)(param_1 + 0xf8),param_3);
              if (iVar3 == 1) {
                (&DAT_0280a2f0)[uVar6] = (&DAT_0280a2f0)[uVar6] | '\x01' << bVar5;
              }
              else if ((iVar3 == 2) &&
                      (iVar3 = uVar2 * 0x20 + *(int *)(param_1 + 0xfc),
                      iVar3 = FUN_005d9580(iVar3,iVar3 + 0x10,*(undefined4 *)(param_3 + 0x80),
                                           (int)*(short *)(param_3 + 0x9c)), iVar3 != 0)) {
                (&DAT_0280a2f0)[uVar6] = (&DAT_0280a2f0)[uVar6] | '\x01' << bVar5;
              }
            }
            else {
              (&DAT_0280a2f0)[uVar6] = '\x01' << bVar5 | bVar4;
            }
          }
          else {
            (&DAT_0280a2f0)[uVar6] = '\x01' << bVar5 | bVar4;
          }
        }
        local_4 = local_4 + 1;
      } while (local_4 < (uint)(int)(short)param_2[3]);
    }
  }
  else {
    uVar6 = 0;
    if ((short)param_2[3] != 0) {
      do {
        sVar1 = *(short *)(*param_2 + uVar6 * 2);
        uVar2 = (uint)sVar1;
        uVar7 = uVar2 >> 3;
        bVar4 = (byte)sVar1 & 7;
        if (((byte)(&DAT_0280a2f0)[uVar7] >> bVar4 & 1) == 0) {
          if ((*(byte *)(uVar7 + *(int *)(*(int *)(param_1 + 0x110) + 0x88)) >> bVar4 & 1) == 0) {
            bVar5 = *(byte *)(uVar2 + *(int *)(*(int *)(param_1 + 0x110) + 0x48));
            if ((bVar5 & 1) != 0) {
              if ((bVar5 & 8) == 0) {
                iVar3 = uVar2 * 0x20 + *(int *)(param_1 + 0xfc);
                iVar3 = FUN_005d9770(iVar3,iVar3 + 0x10,param_3);
                if (iVar3 != 0) {
                  (&DAT_0280a2f0)[uVar7] = (&DAT_0280a2f0)[uVar7] | '\x01' << bVar4;
                }
              }
              else {
                (&DAT_0280a2f0)[uVar7] = '\x01' << bVar4 | (&DAT_0280a2f0)[uVar7];
              }
            }
          }
          else {
            (&DAT_0280a2f0)[uVar7] = '\x01' << bVar4 | (&DAT_0280a2f0)[uVar7];
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(int)(short)param_2[3]);
      return;
    }
  }
  return;
}

