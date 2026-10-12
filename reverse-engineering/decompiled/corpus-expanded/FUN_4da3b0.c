/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4da3b0; label: FUN_004da3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004da3b0(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float local_110 [2];
  uint local_108;
  char local_104 [256];
  uint local_4;
  
  fVar1 = _DAT_00882a5c;
  local_4 = DAT_00829570 ^ (uint)local_110;
  if (DAT_00951b50 == 0) {
    *(float *)(DAT_008827e0 + 0xc) = _DAT_00882a5c;
  }
  else {
    _DAT_00882a5c = *(float *)(DAT_008827e0 + 0xc);
    fVar1 = _DAT_00882a5c;
  }
  if ((0.0 < fVar1) &&
     (iVar2 = (DAT_00882a70 + 0x135) * 0x10 + *(int *)(param_1 + 0x2ac0),
     *(char *)(iVar2 + 0xe) != '\0')) {
    FUN_00552c10(0,_DAT_007fc3a0,0x3f800000,_DAT_007ffd1c,_DAT_007ffd1c,_DAT_007ffd1c,0,0,0,iVar2,0,
                 fVar1);
  }
  if ((0.0 < _DAT_00882a50) && (0.0 < *(float *)(DAT_00882a6c + 0xb008))) {
    iVar2 = FUN_006e6b90();
    _sprintf(local_104,"%i",iVar2 + 1);
    fVar3 = (float10)FUN_005b7d30(*(undefined4 *)(DAT_00882a6c + 0xb008),0x3f800000);
    if ((float)fVar3 < 0.7) {
      local_110[0] = 1.0;
    }
    else {
      local_110[0] = ((float)fVar3 - 0.7) / 0.3 + 1.0;
    }
    local_110[0] = _DAT_007ffd24 * local_110[0];
    local_108 = (uint)ROUND(_DAT_00882a50 * 128.0);
    FUN_0050c780(local_104,0,_DAT_007ffd20,0x3f800000,local_110[0],local_110[0],local_110[0],0,0xff,
                 0x3f,0,local_108 & 0xff);
  }
  if ((_DAT_00882a54 != 0.0) && (0.0 < *(float *)(DAT_00882a6c + 0xb000))) {
    iVar2 = FUN_006e6b90();
    _sprintf(local_104,"%i",iVar2 + 1);
    fVar3 = (float10)FUN_005b7d30(*(undefined4 *)(DAT_00882a6c + 0xb000),0x3f800000);
    if ((float)fVar3 < 0.7) {
      local_110[0] = 1.0;
    }
    else {
      local_110[0] = ((float)fVar3 - 0.7) / 0.3 + 1.0;
    }
    local_110[0] = _DAT_007ffd24 * local_110[0];
    local_108 = (uint)ROUND(_DAT_00882a54 * 128.0);
    FUN_0050c780(local_104,0,_DAT_007ffd20,0x3f800000,local_110[0],local_110[0],local_110[0],0,0,
                 0xff,0,local_108 & 0xff);
    __security_check_cookie(local_4 ^ (uint)local_110);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_110);
  return;
}

