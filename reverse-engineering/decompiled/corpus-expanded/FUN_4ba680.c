/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4ba680; label: FUN_004ba680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba680(int param_1,int param_2,int param_3,char param_4,int param_5)

{
  float fVar1;
  undefined1 uVar2;
  short sVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float10 extraout_ST0;
  float10 fVar11;
  int iVar12;
  float local_20;
  char local_4 [4];
  
  if (param_3 - 1U < 4) {
    if (param_4 == '\0') {
      if (_DAT_00950780 == 0.0) {
        iVar8 = 0;
        fVar4 = _DAT_007fc3a8 * _DAT_007fc3a4;
        fVar7 = _DAT_007fc3b0 * _DAT_007fc3a8 + _DAT_007fc3b0 * _DAT_007fc3a8;
        fVar5 = _DAT_007fc3b4 * _DAT_007fc3a8;
        local_20 = -((float)(int)(param_3 - 1U) * fVar7 * 0.5);
        fVar6 = 0.55 - _DAT_007fc3b4 * 0.6 * _DAT_007fc3a8;
        if (0 < param_3) {
          do {
            _sprintf(local_4,"%i",(int)(char)(&DAT_0087b97c)[iVar8]);
            if (((uint)*(byte *)(param_2 + iVar8) != (int)(char)(&DAT_0087b97c)[iVar8]) &&
               ((float)(&DAT_0087b960)[iVar8] == 0.0)) {
              (&DAT_0087b960)[iVar8] = 0x3c23d70a;
            }
            if ((float)(&DAT_0087b960)[iVar8] == 0.0) {
              uVar9 = 0;
              uVar10 = 0xff;
            }
            else {
              fVar1 = (float)(&DAT_0087b960)[iVar8] + _DAT_00925018;
              (&DAT_0087b960)[iVar8] = fVar1;
              if (0.375 <= fVar1) {
                if (fVar1 < 0.625) {
                  uVar9 = 0xff;
                  uVar10 = 0;
                  (&DAT_0087b97c)[iVar8] = *(undefined1 *)(param_2 + iVar8);
                  goto LAB_004ba961;
                }
                if (1.0 <= fVar1) {
                  uVar9 = 0;
                  (&DAT_0087b960)[iVar8] = 0;
                  uVar10 = 0xff;
                }
                else {
                  uVar9 = FUN_006e6b90();
                  uVar10 = FUN_006e6b90();
                }
                fVar11 = (float10)0.5;
              }
              else {
                uVar9 = FUN_006e6b90();
                uVar10 = FUN_006e6b90();
                fVar11 = extraout_ST0;
              }
              fVar11 = (float10)FUN_0054fad0((&DAT_0087b984)[iVar8],(float)fVar11,0x3dcccccd);
              (&DAT_0087b984)[iVar8] = (float)fVar11;
            }
LAB_004ba961:
            if ('\0' < (char)(&DAT_0087b97c)[iVar8]) {
              FUN_00511500(local_4,local_20,fVar6 + fVar5 * 1.01,0,(&DAT_0087b984)[iVar8],
                           (&DAT_0087b984)[iVar8],(&DAT_0087b984)[iVar8],0,uVar10,uVar9,0);
            }
            fVar11 = (float10)FUN_0054fad0((&DAT_0087b950)[iVar8],
                                           (float)(int)(char)(&DAT_0087b97c)[iVar8] /
                                           (float)(int)(char)(&DAT_0087b930)[iVar8] +
                                           (float)(int)(char)(&DAT_0087b97c)[iVar8] /
                                           (float)(int)(char)(&DAT_0087b930)[iVar8],0x3ba3d70a);
            fVar1 = (float)fVar11;
            (&DAT_0087b950)[iVar8] = fVar1;
            if (param_5 == 0) {
              sVar3 = *(short *)(param_1 + iVar8 * 2);
              iVar12 = 0;
            }
            else {
              sVar3 = *(short *)(param_1 + iVar8 * 2);
              iVar12 = param_5;
            }
            FUN_0055b830((int)sVar3,local_20,fVar6,0,fVar4,0xa7,fVar1,fVar1,1,iVar12);
            local_20 = local_20 + fVar7;
            iVar8 = iVar8 + 1;
          } while (iVar8 < param_3);
        }
      }
    }
    else {
      iVar8 = 0;
      _DAT_0087b97c = 0;
      DAT_0087b960 = 0;
      _DAT_0087b964 = 0;
      _DAT_0087b968 = 0;
      _DAT_0087b96c = 0;
      DAT_0087b984 = 0;
      DAT_0087b988 = 0;
      _DAT_0087b98c = 0;
      _DAT_0087b990 = 0;
      DAT_0087b950 = 0;
      DAT_0087b954 = 0;
      _DAT_0087b958 = 0;
      _DAT_0087b95c = 0;
      _DAT_0087b930 = 0;
      if (0 < param_3) {
        do {
          uVar2 = *(undefined1 *)(param_2 + iVar8);
          (&DAT_0087b984)[iVar8] = 0x3f000000;
          (&DAT_0087b97c)[iVar8] = uVar2;
          (&DAT_0087b930)[iVar8] = uVar2;
          (&DAT_0087b950)[iVar8] = 0x3f800000;
          iVar8 = iVar8 + 1;
        } while (iVar8 < param_3);
        return;
      }
    }
  }
  return;
}

