/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56cab0; label: FUN_0056cab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056cab0(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_18 [4];
  float local_8;
  float local_4;
  
  iVar5 = *(int *)(param_1[6] + 0x7c);
  iVar4 = (uint)*(byte *)(param_1[5] + 0x10) * 0x5c;
  iVar6 = (uint)*(byte *)(param_1[5] + 0x11) * 0x5c;
  if (*(float *)(iVar4 + 8 + iVar5) < *(float *)(iVar6 + 8 + iVar5)) {
    iVar6 = iVar4;
  }
  iVar6 = iVar6 + iVar5;
  iVar5 = 0;
  if (DAT_008030ec < 1) {
    return;
  }
  iVar4 = 0;
  while( true ) {
    local_18[0] = *(float *)(iVar6 + 0x10) + 0.5;
    local_18[1] = 0.0;
    local_18[2] = 0.0;
    FUN_005b3620(local_18,local_18,(int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2);
    local_18[3] = *(float *)(iVar6 + 4);
    local_8 = (*(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x18)) * 0.5;
    local_4 = *(float *)(iVar6 + 0xc);
    iVar3 = FUN_0067b430(local_18 + 3,local_18,0,0x3f800000,0,DAT_0095100c | DAT_008034c4 | 0x5f);
    if ((iVar3 != 0) &&
       (cVar2 = FUN_0067b210(), (*(uint *)(&DAT_008034cc + cVar2 * 0xc) & 0x10000) != 0)) break;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x10000;
    if (DAT_008030ec <= iVar5) {
      return;
    }
  }
  param_1[7] = param_1[7] | 1;
  *param_1 = DAT_0292fdb8;
  param_1[1] = DAT_0292fdbc;
  uVar1 = DAT_0292fdc0;
  param_1[3] = local_18[3] + local_18[0];
  param_1[2] = uVar1;
  param_1[4] = local_4 + local_18[2];
  return;
}

