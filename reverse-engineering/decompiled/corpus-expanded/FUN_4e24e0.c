/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e24e0; label: thunk_FUN_005aa7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_005aa7f0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  int aiStack_30 [12];
  
  if (DAT_0095df30 != 0) {
    aiStack_30[9] = *(int *)(param_1 + 0x5044);
    aiStack_30[0xb] = (uint)*(byte *)(*(int *)(param_1 + 0x5040) + 0x1c) * DAT_0095df38 * 0x40;
    iVar4 = aiStack_30[9] + aiStack_30[0xb];
    aiStack_30[0xb] = aiStack_30[0xb] + iVar4;
    aiStack_30[5] = 0;
    aiStack_30[4] = 0;
    aiStack_30[3] = 0;
    aiStack_30[0] = aiStack_30[9];
    aiStack_30[1] = iVar4;
    aiStack_30[2] = aiStack_30[0xb];
    aiStack_30[6] = 0;
    aiStack_30[7] = 0;
    aiStack_30[8] = 0;
    iStack_4c = 0;
    if (0 < DAT_0095df38) {
      iStack_50 = 0;
      iVar5 = DAT_0095df38;
      do {
        iVar7 = *(int *)(param_1 + 0x5040) + iStack_50;
        if (((*(uint *)(iVar7 + 0x20) & 4) != 0) && ((*(uint *)(iVar7 + 0x20) & 1) != 0)) {
          *(undefined4 *)(iVar7 + 8) = 0;
          iStack_54 = 0;
          if (*(char *)(iVar7 + 0x1c) != '\0') {
            pfVar6 = (float *)(*(int *)(iVar7 + 0x40) + 0x18);
            do {
              fStack_3c = pfVar6[-1];
              fStack_34 = pfVar6[1];
              if ((_DAT_00805d38 & DAT_00925068 + iStack_54) == 0) {
                if (*(float *)(iVar7 + 0x30) == 2e+06) {
                  fStack_38 = 10.0;
                  fVar8 = (float10)FUN_005506f0(0,&fStack_3c,0x40a00000,0xffffffff);
                  fStack_38 = (float)fVar8;
                  *pfVar6 = fStack_38;
                }
                else {
                  fStack_38 = *(float *)(iVar7 + 0x30);
                  *pfVar6 = fStack_38;
                }
              }
              else {
                fStack_38 = *pfVar6;
              }
              *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) + *pfVar6;
              iVar5 = *(int *)(&DAT_00805c94 + (*(byte *)((int)pfVar6 + -0x17) >> 2 & 3) * 4);
              iVar1 = aiStack_30[iVar5];
              FUN_005a87d0();
              iVar3 = FUN_006e6b90();
              fStack_38 = ABS((float)(&DAT_029899a0)
                                     [(uint)(int)ROUND((float10)(ushort)((ushort)(*(byte *)((int)
                                                  pfVar6 + -0x17) >> 2 & 3) << 0xe) +
                                                  extraout_ST0 *
                                                  (extraout_ST1 -
                                                  ((float10)(float)(&DAT_029899a0)
                                                                   [iVar3 >> 1 & 0x7fff] +
                                                  extraout_ST1) * (float10)0.5)) >> 1 & 0x7fff]) *
                          _DAT_00805d34 + fStack_38;
              FUN_005b4900(iVar1,&fStack_3c);
              aiStack_30[iVar5 + 3] = aiStack_30[iVar5 + 3] + 1;
              uVar2 = *(uint *)(iVar7 + 0x18);
              aiStack_30[iVar5] = iVar1 + 0x40;
              if ((uVar2 & 0x2000000) == 0) {
                aiStack_30[iVar5 + 6] = aiStack_30[iVar5 + 6] + 1;
              }
              iStack_54 = iStack_54 + 1;
              pfVar6 = pfVar6 + 8;
              iVar5 = DAT_0095df38;
            } while (iStack_54 < (int)(uint)*(byte *)(iVar7 + 0x1c));
          }
          *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) / (float)*(byte *)(iVar7 + 0x1c);
        }
        iStack_50 = iStack_50 + 0x54;
        iStack_4c = iStack_4c + 1;
      } while (iStack_4c < iVar5);
    }
    iVar5 = 0;
    aiStack_30[0] = aiStack_30[9];
    aiStack_30[1] = iVar4;
    aiStack_30[2] = aiStack_30[0xb];
    iVar4 = 0;
    do {
      iVar7 = *(int *)((int)aiStack_30 + iVar4);
      iVar1 = *(int *)((int)aiStack_30 + iVar4 + 0x18);
      FUN_005ea510(iVar5 + DAT_0095df30,iVar1,iVar7,1);
      *(int *)((int)aiStack_30 + iVar4 + 0x24) = iVar1 * 0x40 + iVar7;
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 0x24);
    iVar5 = 0x24;
    iVar4 = 0;
    do {
      FUN_005ea510(iVar5 + DAT_0095df30,
                   *(int *)((int)aiStack_30 + iVar4 + 0xc) -
                   *(int *)((int)aiStack_30 + iVar4 + 0x18),
                   *(undefined4 *)((int)aiStack_30 + iVar4 + 0x24),1);
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 0x48);
  }
  return;
}

