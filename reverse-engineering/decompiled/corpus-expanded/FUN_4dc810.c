/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dc810; label: FUN_004dc810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc810(int param_1)

{
  int iVar1;
  float10 fVar2;
  float local_110 [2];
  uint local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_110;
  FUN_004dc530();
  if (((DAT_0093b328 == 0) && (_DAT_00882a54 != 0.0)) && (0.0 < _DAT_0088249c)) {
    iVar1 = FUN_006e6b90();
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      iVar1 = 3;
    }
    _sprintf(local_104,"%i",iVar1);
    fVar2 = (float10)FUN_005b7d30(_DAT_0088249c,0x3f800000);
    if ((float)fVar2 < 0.7) {
      local_110[0] = 1.0;
    }
    else {
      local_110[0] = ((float)fVar2 - 0.7) / 0.3 + 1.0;
    }
    local_110[0] = _DAT_007ffd24 * local_110[0];
    local_108 = (uint)ROUND(_DAT_00882a54 * 128.0);
    FUN_0050c780(local_104,0,_DAT_007ffd20,0x3f800000,local_110[0],local_110[0],local_110[0],0,0,
                 0xff,0,local_108 & 0xff);
  }
  if ((0.0 < _DAT_00882a5c) &&
     (iVar1 = (DAT_008824a6 + 0x135) * 0x10 + *(int *)(param_1 + 0x2ac0),
     *(char *)(iVar1 + 0xe) != '\0')) {
    FUN_00552c10(0,_DAT_007fc3a0,0x3f800000,_DAT_007ffd1c,_DAT_007ffd1c,_DAT_007ffd1c,0,0,0,iVar1,0,
                 _DAT_00882a5c);
    __security_check_cookie(local_4 ^ (uint)local_110);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_110);
  return;
}

