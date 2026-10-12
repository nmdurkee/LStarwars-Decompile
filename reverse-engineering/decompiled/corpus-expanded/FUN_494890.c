/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x494890; label: FUN_00494890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494890(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  float local_150;
  uint local_14c;
  float local_148;
  char local_144 [64];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_150;
  iVar5 = 0;
  *(float *)(param_1 + 0x98) =
       (float)-(int)*(short *)(param_1 + 10) * _DAT_00800994 * *(float *)(param_1 + 0x90);
  do {
    iVar4 = (iVar5 + 0x2c) % 0x2d;
    if ((((iVar4 < 8) ||
         (((&DAT_0086e4c8)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5] & 1 << ((byte)iVar4 & 0x1f))
          != 0)) || ((&DAT_007f3da3)[iVar4 * 0x20] == -1)) ||
       ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[iVar4 * 0x20] * 0xc] != '\0')) {
      if (((&DAT_0086e4c8)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5] & 1 << ((byte)iVar4 & 0x1f))
          == 0) {
        local_150 = 0.5;
        FUN_004f1f10(local_144,*(undefined4 *)(DAT_00926c20 + DAT_00880744 * 4));
      }
      else {
        local_150 = 1.0;
        iVar2 = FUN_0056e160(iVar4);
        if (iVar2 == 0) {
          uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_0088085c * 4);
        }
        else {
          uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_00880858 * 4);
        }
        FUN_004f1f10(local_144,uVar3);
        if ((DAT_00951154 != 0) && (iVar2 = FUN_0056e100(iVar4,0x200000), iVar2 != 0)) {
          local_150 = 0.5;
        }
      }
      _sprintf(local_104,"%s: %s",
               *(undefined4 *)(DAT_00926c20 + *(short *)(&PTR_DAT_007f3d9c)[iVar4 * 8] * 4),
               local_144);
    }
    else {
      local_150 = 0.5;
      FUN_004f1f10(local_104,*(undefined4 *)(DAT_00926c20 + DAT_0088072c * 4));
      _sprintf(local_144," %i: ",iVar4 + -7);
      FUN_004f1e80(local_104,local_144);
      FUN_004f1e80(local_104,*(undefined4 *)(DAT_00926c20 + DAT_008806e8 * 4));
    }
    _DAT_008009a8 = *(undefined4 *)(param_1 + 0x90);
    if (7 < iVar4) {
      DAT_00921db0 = 1;
    }
    if (iVar4 == 0x2c) {
      DAT_009213e1 = 0xbf;
      DAT_009213e2 = 0;
      DAT_009213e0 = 0x7f;
    }
    else {
      DAT_009213e1 = 0xdf;
      DAT_009213e2 = 0x3f;
      DAT_009213e0 = 0;
    }
    local_148 = ABS(*(float *)(param_1 + 0x98));
    if (_DAT_007facd0 < local_148) {
      if (local_148 <= _DAT_007facd4) {
        local_150 = (1.0 - (local_148 - _DAT_007facd0) / (_DAT_007facd4 - _DAT_007facd0)) *
                    local_150;
      }
      else {
        local_150 = 0.0;
      }
    }
    if (DAT_0093b328 != 0) {
      DAT_00921db4 = DAT_00951378;
      *(undefined4 *)(param_1 + 0x94) = _DAT_0095137c;
    }
    fVar1 = (float)_DAT_00921d60 * local_150;
    local_150 = (float)CONCAT22(local_150._2_2_,in_FPUControlWord);
    local_14c = (uint)ROUND(fVar1);
    FUN_0050f740(param_1,local_104,local_14c & 0xff);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x2d);
  __security_check_cookie(local_4 ^ (uint)&local_150);
  return;
}

