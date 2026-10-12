/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x52fda0; label: FUN_0052fda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052fda0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  float local_18 [4];
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)(param_1 + 0x144);
  if (*(byte *)(iVar2 + 6) <= *(byte *)(param_1 + 0x14a)) {
    return;
  }
  puVar1 = (undefined4 *)((uint)*(byte *)(param_1 + 0x14a) * 0x34 + 0x54 + iVar2);
  if ((*(byte *)(param_1 + 0x1eb) & 1) == 0) {
    local_18[0] = *(float *)(iVar2 + 0x128) * (float)((*(byte *)(param_1 + 0x149) + 1) / 2);
    if ((*(byte *)(param_1 + 0x149) & 1) == 0) goto LAB_0052fe23;
  }
  else {
    if ((*(byte *)(iVar2 + 8) & 1) != 0) {
      local_18[0] = 0.0;
      goto LAB_0052fe23;
    }
    local_18[0] = *(float *)(iVar2 + 0x128) * 0.5;
  }
  local_18[0] = -local_18[0];
LAB_0052fe23:
  if ((*(byte *)(iVar2 + 0x50) & 4) != 0) {
    local_18[0] = -local_18[0];
  }
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  FUN_005b3620(local_18,local_18,puVar1[9]);
  FUN_005b37d0(local_18 + 3,local_18,puVar1 + 6);
  *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) | 8;
  uVar4 = 5;
  if ((*(int *)(param_1 + 0x144) != 0) &&
     (uVar4 = 5, (*(byte *)(*(int *)(param_1 + 0x144) + 0x50) & 8) != 0)) {
    uVar4 = 1;
  }
  *(float *)(param_1 + 0x1b4) = local_18[3];
  *(undefined4 *)(param_1 + 0x1b8) = local_8;
  *(undefined4 *)(param_1 + 0x1bc) = local_4;
  *(undefined4 *)(param_1 + 0x1cc) = *puVar1;
  *(undefined4 *)(param_1 + 0x1d0) = puVar1[1];
  *(undefined4 *)(param_1 + 0x1d4) = puVar1[2];
  *(undefined4 *)(param_1 + 0x1d8) = puVar1[3];
  *(undefined4 *)(param_1 + 0x1dc) = puVar1[4];
  uVar3 = puVar1[5];
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = uVar3;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  iVar2 = param_1 + 0x78;
  *(undefined4 *)(param_1 + 0x80) = 0x42c80000;
  *(uint *)(param_1 + 0x1e8) = (*(uint *)(param_1 + 0x1e8) ^ uVar4) & 7 ^ *(uint *)(param_1 + 0x1e8)
  ;
  FUN_005b3620(iVar2,iVar2,puVar1[9]);
  FUN_005b37d0(iVar2,iVar2,puVar1 + 6);
  *(int *)(param_1 + 0x1e4) = iVar2;
  return;
}

