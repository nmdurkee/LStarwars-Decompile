/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4db280; label: FUN_004db280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004db280(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined1 **ppuVar10;
  float10 fVar11;
  float10 fVar12;
  float local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  float local_180;
  undefined4 local_17c;
  float local_178 [3];
  float local_16c [3];
  undefined1 local_160 [12];
  undefined1 local_154 [12];
  undefined1 local_148 [8];
  float local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined1 *local_110 [5];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined *local_ec;
  undefined4 local_e4;
  code *local_d0;
  float local_84;
  undefined1 local_48 [68];
  
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar6 = *piVar2;
    if (param_6 != 0) {
      FUN_005cf5b0(DAT_00924898,&DAT_00882a9c,&DAT_0075d4e4,1);
      *(uint *)(iVar6 + 0xeec) = *(uint *)(iVar6 + 0xeec) | 0x4000;
      *(undefined4 *)(iVar6 + 0xec8) = 0x3f800000;
      *(uint *)(iVar6 + 0xef4) = *(uint *)(iVar6 + 0xef4) | 0x200000;
      *(undefined1 *)(iVar6 + 0x408) = 1;
    }
    iVar9 = 0;
    if ((DAT_0093d810 != 0) &&
       ((DAT_0093d814 == 0 ||
        (fVar1 = *(float *)(iVar6 + 0x5c) - *(float *)(DAT_0093d810 + 0x5c),
        fVar3 = *(float *)(iVar6 + 100) - *(float *)(DAT_0093d810 + 100),
        fVar4 = *(float *)(iVar6 + 0x5c) - *(float *)(DAT_0093d814 + 0x5c),
        fVar5 = *(float *)(iVar6 + 100) - *(float *)(DAT_0093d814 + 100), iVar9 = DAT_0093d814,
        fVar1 * fVar1 + fVar3 * fVar3 < fVar4 * fVar4 + fVar5 * fVar5)))) {
      iVar9 = DAT_0093d810;
    }
    iVar7 = iVar6 + 0x670;
    FUN_0053f0e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar7,_DAT_007ffcc4,local_148);
    if (iVar9 == 0) {
      *(undefined4 *)(iVar6 + 0xec8) = 0x3f800000;
      local_190 = local_140;
      local_18c = local_13c;
      local_188 = local_138;
    }
    else {
      fVar11 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar9 + 0x670);
      fVar12 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar7);
      fVar1 = _DAT_007ffe30 + (float)((float10)(double)fVar11 - fVar12);
      FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar7);
      FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar9 + 0x670);
      fVar11 = (float10)FUN_0054fad0(*(undefined4 *)(iVar6 + 0xec8),
                                     (fVar1 / _DAT_007ffd48 + 1.0) * _DAT_0087b888,_DAT_007ffd4c);
      fVar1 = (float)fVar11;
      *(float *)(iVar6 + 0xec8) = fVar1;
      if (fVar1 <= _DAT_007ffd50) {
        if (fVar1 < _DAT_007ffd54) {
          *(float *)(iVar6 + 0xec8) = _DAT_007ffd54;
        }
      }
      else {
        *(float *)(iVar6 + 0xec8) = _DAT_007ffd50;
      }
      FUN_005b3800(local_178,iVar9 + 0x5c,iVar9 + 0x678);
      FUN_005b3620(local_178,local_178,-(uint)*(ushort *)(iVar9 + 0x696));
      FUN_005b3800(local_16c,iVar6 + 0x5c,iVar6 + 0x678);
      FUN_005b3620(local_16c,local_16c,-(uint)*(ushort *)(iVar6 + 0x696));
      local_188 = 0;
      local_18c = 0;
      local_190 = (1.0 - _DAT_007ffd44) * local_178[0] + local_16c[0] * _DAT_007ffd44;
      FUN_005b37d0(&local_190,&local_190,&local_140);
      fVar1 = *(float *)(param_2 + 0x9c) + _DAT_00925018;
      *(float *)(param_2 + 0x9c) = fVar1;
      if (_DAT_007ffe2c < fVar1) {
        if (DAT_00882a7c == 0) {
          iVar7 = FUN_005cfac0(&DAT_00882a9c);
          if (iVar7 != 0) {
            local_184 = *(undefined4 *)(iVar6 + 0x5c);
            local_180 = *(float *)(iVar6 + 0x60) + 1.0;
            local_17c = *(undefined4 *)(iVar6 + 100);
            FUN_005b3800(local_154,iVar9 + 0x68,iVar6 + 0x68);
            FUN_0049f630(local_160,&local_184,iVar9 + 0x80,local_154,_DAT_007ffd10,_DAT_007ffd14);
            FUN_005b37d0(local_160,local_160,iVar6 + 0x68);
            FUN_005b4500(local_48,&local_184);
            puVar8 = &DAT_00810210;
            ppuVar10 = local_110;
            for (iVar6 = 0x32; iVar6 != 0; iVar6 = iVar6 + -1) {
              *ppuVar10 = (undefined1 *)*puVar8;
              puVar8 = puVar8 + 1;
              ppuVar10 = ppuVar10 + 1;
            }
            local_fc = 0x3dcccccd;
            local_f8 = 0x3dcccccd;
            local_f4 = _DAT_007ffd14;
            local_84 = _DAT_00925018;
            local_110[0] = local_48;
            local_110[2] = local_160;
            local_ec = &DAT_00882a9c;
            local_e4 = 0x29b;
            local_d0 = FUN_0042cf20;
            FUN_0064d270(local_110);
            *(undefined4 *)(param_2 + 0x9c) = 0;
          }
        }
        else {
          iVar6 = FUN_004d8af0();
          if (iVar6 != 0) {
            *(undefined4 *)(param_2 + 0x9c) = 0;
          }
        }
      }
    }
    FUN_0052fcb0(param_3,&local_190,0,0,1,0);
    return 0;
  }
  return 1;
}

