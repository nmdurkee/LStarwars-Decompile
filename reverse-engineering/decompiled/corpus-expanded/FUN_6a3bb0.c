/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3bb0; label: FUN_006a3bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a3bb0(int *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = param_1[1];
  uVar4 = param_2 + iVar3;
  if ((*param_1 + 4 < param_1[4]) ||
     (uVar5 = 0xffffffff, (int)(uVar4 + *param_1 * 8) <= param_1[4] * 8)) {
    pbVar1 = (byte *)param_1[3];
    bVar2 = (byte)iVar3;
    uVar5 = (uint)(*pbVar1 >> (bVar2 & 0x1f));
    if (((8 < (int)uVar4) &&
        (((uVar5 = uVar5 | (uint)pbVar1[1] << (8 - bVar2 & 0x1f), 0x10 < (int)uVar4 &&
          (uVar5 = uVar5 | (uint)pbVar1[2] << (0x10 - bVar2 & 0x1f), 0x18 < (int)uVar4)) &&
         (uVar5 = uVar5 | (uint)pbVar1[3] << (0x18 - bVar2 & 0x1f), 0x20 < (int)uVar4)))) &&
       (iVar3 != 0)) {
      uVar5 = uVar5 | (uint)pbVar1[4] << (0x20 - bVar2 & 0x1f);
    }
    uVar5 = uVar5 & *(uint *)(&DAT_0076f4e8 + param_2 * 4);
  }
  iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 7U)) >> 3;
  param_1[3] = param_1[3] + iVar3;
  *param_1 = iVar3 + *param_1;
  param_1[1] = uVar4 & 7;
  return uVar5;
}

