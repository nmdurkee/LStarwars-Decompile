/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46f4d0; label: FUN_0046f4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f4d0(int param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float10 fVar4;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  iVar1 = param_1 + 100;
  *(undefined4 *)(param_1 + 0x6c) = 0x3ecccccd;
  FUN_005b3620(iVar1,iVar1,*(ushort *)(param_1 + 0x5c) + 0x8000);
  pfVar2 = (float *)(param_1 + 0x50);
  FUN_005b37d0(iVar1,iVar1,pfVar2);
  local_18 = *(float *)(param_1 + 0x70);
  local_14 = *(undefined4 *)(param_1 + 0x74);
  local_10 = *(float *)(param_1 + 0x78);
  FUN_005b3620(&local_18,&local_18,*(undefined2 *)(param_1 + 0x5c));
  local_18 = *pfVar2 + local_18;
  local_10 = *(float *)(param_1 + 0x58) + local_10;
  local_8 = *(undefined4 *)(param_1 + 0x54);
  local_c = local_18;
  local_4 = local_10;
  fVar4 = (float10)FUN_005506f0(0,iVar1,0x3e4ccccd,0xffffffff);
  *(float *)(param_1 + 0x68) = (float)fVar4;
  fVar4 = (float10)FUN_005506f0(0,&local_c,0x3e4ccccd,0xffffffff);
  fVar3 = (float)fVar4;
  *(float *)(param_1 + 0x74) = fVar3;
  if (fVar3 != 2e+06) {
    *(float *)(param_1 + 0x74) = fVar3 + _DAT_007f90cc;
    FUN_0054fec0(&DAT_0292fdb8,param_1 + 0x82,param_1 + 0x84);
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(byte *)(param_1 + 0x62) = *(byte *)(param_1 + 0x62) & 0xfc | 0xc;
  *(undefined2 *)(param_1 + 0x80) = 0;
  FUN_005b4670(param_1,*(undefined2 *)(param_1 + 0x5c));
  FUN_005b4900(param_1,pfVar2);
  return;
}

