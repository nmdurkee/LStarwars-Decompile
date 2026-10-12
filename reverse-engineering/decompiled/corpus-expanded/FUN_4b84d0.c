/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b84d0; label: FUN_004b84d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b84d0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  float local_8c;
  float local_88;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_8c;
  if ((_DAT_00950780 == 0.0) && ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0)) {
    local_8c = _DAT_0087b970;
    if (in_ECX == 2) {
      local_8c = _DAT_0087b928;
    }
    iVar1 = FUN_006e6b90();
    uVar6 = 0xff;
    uVar4 = 0;
    uVar2 = 0xbf;
    _DAT_007fc380 =
         (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] +
         _DAT_007fc314 + _DAT_007fc370;
    uVar3 = uVar2;
    local_8c = _DAT_007fc380;
    if (in_ECX == 1) {
      FUN_004b8320(-_DAT_007fc380,_DAT_0092506c,*(undefined4 *)(&DAT_0086e454 + DAT_00802af4 * 0xc),
                   0);
      uVar5 = DAT_0093b298;
      uVar3 = 0xbf;
      if (*(int *)(&DAT_0086e458 + DAT_00802af4 * 0xc) != 0) {
        if (param_1 == 0) {
          FUN_0054bb30(*(int *)(&DAT_0086e458 + DAT_00802af4 * 0xc),local_44);
          FUN_004f1f10(local_84,&DAT_00755d74);
          FUN_004f1e80(local_84,local_44);
          FUN_004f1e80(local_84,&DAT_00755d70);
          local_88 = _DAT_007fc37c + local_8c;
          FUN_0050c780(local_84,0,local_88,0x3f800000,0x3eb33333,0x3eb33333,0x3eb33333,0,0xff,0xff,
                       0xff,0x30);
        }
        uVar3 = uVar2;
        if (*(uint *)(&DAT_0086e458 + DAT_00802af4 * 0xc) < DAT_0093b298) {
          uVar6 = 0x3f;
          uVar4 = 0x1f;
          uVar3 = 0xff;
        }
      }
    }
    else {
      uVar5 = DAT_0085ea74;
      if (in_ECX != 2) {
        uVar5 = DAT_0086e4dc;
      }
    }
    FUN_004b80e0(uVar5,local_8c,_DAT_0087b93c,1,0x3f800000,uVar6,uVar3,uVar4);
  }
  __security_check_cookie(local_4 ^ (uint)&local_8c);
  return;
}

