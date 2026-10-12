/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54c9a0; label: FUN_0054c9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c9a0(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_810;
  uint local_80c;
  float local_808;
  char local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_810;
  *(undefined4 *)(param_1 + 0x90) = 0x40000000;
  iVar4 = DAT_00926c38;
  local_808 = (float)-(int)*(short *)(param_1 + 10);
  iVar6 = 0;
  *(float *)(param_1 + 0xa4) = _DAT_00800994 + _DAT_00800994;
  *(undefined4 *)(param_1 + 0x94) = 0xbf400000;
  *(float *)(param_1 + 0x98) = (float)(int)local_808 * *(float *)(param_1 + 0xa4);
  if (0 < iVar4) {
    do {
      _DAT_008009a4 = 0x3f19999a;
      _DAT_008009a8 = *(undefined4 *)(param_1 + 0x90);
      DAT_00921db4 = 0;
      FUN_00574de0(param_1,&DAT_007596f8);
      local_808 = *(float *)(param_1 + 0x98) - *(float *)(param_1 + 0xa4);
      if (((DAT_00921d24 == 0) && (-1.25 <= local_808)) && (local_808 < 1.25)) {
        if ((*(uint *)(DAT_00926c3c + ((int)(iVar6 + (iVar6 >> 0x1f & 0x1fU)) >> 5) * 4) &
            1 << ((byte)iVar6 & 0x1f)) == 0) {
          uVar5 = 0xff;
          if (iVar6 == *(int *)(param_1 + 0x34)) {
            if (DAT_009213e4 == 0) {
              local_810 = 0xbf;
              local_80c = 0;
            }
            else {
              local_80c = 0xff;
              local_810 = 0xff;
            }
          }
          else {
            local_80c = 0;
            local_810 = 0;
          }
        }
        else if (iVar6 == *(int *)(param_1 + 0x34)) {
          bVar1 = DAT_008009a1;
          bVar2 = DAT_008009a2;
          bVar3 = DAT_00921dae;
          if (DAT_009213e4 != 0) {
            bVar1 = DAT_00921dad;
            bVar2 = DAT_008009a0;
            bVar3 = DAT_0080099f;
          }
          local_810 = (uint)bVar3;
          local_80c = (uint)bVar2;
          uVar5 = (uint)bVar1;
          if (0.0 < _DAT_00921d70) {
            local_810 = (uint)DAT_008009a1;
            uVar5 = FUN_006e6b90();
            local_810 = (uint)DAT_00921dae;
            local_810 = FUN_006e6b90();
            local_80c = (uint)DAT_008009a2;
            local_80c = FUN_006e6b90();
          }
        }
        else {
          local_810 = (uint)DAT_0080099a;
          local_80c = (uint)DAT_0080099b;
          uVar5 = (uint)DAT_00921da9;
        }
        DAT_009213e1 = (undefined1)uVar5;
        DAT_009213e2 = (undefined1)local_810;
        DAT_009213e0 = (undefined1)local_80c;
        DAT_00921db0 = 1;
        _sprintf(local_804,"%i",iVar6);
        FUN_0050d910(local_804,0xbf428f5c,local_808,0x3f800000,_DAT_0080098c,_DAT_0080098c,
                     _DAT_0080098c,8,uVar5,local_810,local_80c,0x3db851f0,1,0,0,_DAT_00921d60);
        if (*(int *)(DAT_00926c20 + iVar6 * 4) != 0) {
          DAT_00921db0 = 1;
          FUN_0054bd50(*(undefined4 *)(DAT_00926c20 + iVar6 * 4),local_804);
          FUN_0050d910(local_804,0xbf3d70a4,local_808,0x3f800000,_DAT_0080098c,_DAT_0080098c,
                       _DAT_0080098c,2,uVar5,local_810,local_80c,0x3fcb851f,2,0,0,_DAT_00921d60);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_00926c38);
  }
  __security_check_cookie(local_4 ^ (uint)&local_810);
  return;
}

