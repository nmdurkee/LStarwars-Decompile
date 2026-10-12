/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8e20; label: FUN_005d8e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d8e20(int param_1)

{
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  char cVar4;
  int iVar5;
  ushort *puVar6;
  int in_ECX;
  byte *pbVar7;
  int *local_198;
  float local_194;
  int local_190 [100];
  
  local_194 = *(float *)(*(int *)(param_1 + 0x24) + in_ECX * 4);
  local_198 = local_190 + 1;
  local_190[0] = *(int *)(param_1 + 0x14) +
                 (uint)*(ushort *)(*(int *)(param_1 + 0x20) + in_ECX * 2) * 0xc;
  if (local_194 == 0.0) {
    local_194 = DAT_00973734;
  }
  do {
    puVar3 = (ushort *)local_198[-1];
    local_198 = local_198 + -1;
    iVar5 = (uint)*puVar3 * 0x20 + *(int *)(param_1 + 0x18);
    iVar5 = FUN_005d8b60(iVar5,iVar5 + 0x10,local_194,0);
    if (iVar5 != 0) {
      if (iVar5 == 1) {
        puVar6 = (ushort *)(*(int *)(param_1 + 8) + (uint)puVar3[5] * 2);
        puVar3 = puVar6 + puVar3[1];
        for (; puVar6 != puVar3; puVar6 = puVar6 + 1) {
          pbVar7 = (byte *)(*(int *)(DAT_00973988 + 0x20) + (uint)(*puVar6 >> 2));
          *pbVar7 = *pbVar7 | '\x01' << ((byte)*puVar6 & 3) * '\x02';
        }
      }
      else {
        if (puVar3[2] != 0) {
          iVar5 = *(int *)(param_1 + 0x14) + (uint)puVar3[3] * 0xc;
          iVar1 = iVar5 + (uint)puVar3[2] * 0xc;
          for (; iVar5 != iVar1; iVar5 = iVar5 + 0xc) {
            *local_198 = iVar5;
            local_198 = local_198 + 1;
          }
        }
        if (puVar3[4] != 0) {
          puVar6 = (ushort *)(*(int *)(param_1 + 8) + (uint)puVar3[5] * 2);
          iVar5 = (uint)puVar3[5] * 0x20 + *(int *)(param_1 + 0xc);
          puVar3 = puVar6 + puVar3[4];
          for (; puVar6 != puVar3; puVar6 = puVar6 + 1) {
            uVar2 = *puVar6;
            cVar4 = FUN_005d8b60(iVar5,iVar5 + 0x10,local_194,1);
            pbVar7 = (byte *)((uint)(uVar2 >> 2) + *(int *)(DAT_00973988 + 0x20));
            *pbVar7 = *pbVar7 | cVar4 << ((byte)uVar2 & 3) * '\x02';
            iVar5 = iVar5 + 0x20;
          }
        }
      }
    }
  } while (local_198 != local_190);
  return;
}

