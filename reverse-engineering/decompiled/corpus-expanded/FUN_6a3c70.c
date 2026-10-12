/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3c70; label: FUN_006a3c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006a3c70(int *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = param_1[1];
  uVar5 = param_2 + iVar3;
  if ((*param_1 + 4 < param_1[4]) ||
     (uVar4 = 0xffffffff, (int)(uVar5 + *param_1 * 8) <= param_1[4] * 8)) {
    pbVar1 = (byte *)param_1[3];
    bVar2 = (byte)iVar3;
    uVar4 = (uint)*pbVar1 << (bVar2 + 0x18 & 0x1f);
    if (((8 < (int)uVar5) &&
        (((uVar4 = uVar4 | (uint)pbVar1[1] << (bVar2 + 0x10 & 0x1f), 0x10 < (int)uVar5 &&
          (uVar4 = uVar4 | (uint)pbVar1[2] << (bVar2 + 8 & 0x1f), 0x18 < (int)uVar5)) &&
         (uVar4 = uVar4 | (uint)pbVar1[3] << (bVar2 & 0x1f), 0x20 < (int)uVar5)))) && (iVar3 != 0))
    {
      uVar4 = uVar4 | pbVar1[4] >> (8 - bVar2 & 0x1f);
    }
    uVar4 = (uVar4 >> ((byte)(-param_2 + 0x20 >> 1) & 0x1f)) >>
            ((byte)(-param_2 + 0x21 >> 1) & 0x1f);
  }
  iVar3 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3;
  param_1[3] = param_1[3] + iVar3;
  *param_1 = iVar3 + *param_1;
  param_1[1] = uVar5 & 7;
  return uVar4;
}

