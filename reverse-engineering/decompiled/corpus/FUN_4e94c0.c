/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e94c0; label: FUN_004e94c0
 */

undefined4 FUN_004e94c0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float *pfVar9;
  float local_c [3];
  
  iVar2 = param_1;
  fVar1 = *(float *)((short)(&DAT_0088a30c)[param_1 * 0x14] * 0x4c + 0x30 +
                    *(int *)(DAT_029130e4 + 0x20));
  iVar7 = 0;
  if ((&DAT_0088a322)[param_1 * 0x28] != '\0') {
    do {
      if ((&DAT_0088a30c)[param_1 * 0x14] != DAT_007f1914) {
        iVar3 = iVar7 + param_1 * 10;
        iVar6 = (&DAT_0088a310)[iVar3];
        if ((iVar6 != 0) && (5.0 < *(float *)(iVar6 + 0xf10))) {
          FUN_004364e0(iVar6,4,0);
          (&DAT_0088a310)[iVar3] = 0;
          (&DAT_0088a322)[param_1 * 0x28] = (&DAT_0088a322)[param_1 * 0x28] + -1;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)(uint)(byte)(&DAT_0088a322)[param_1 * 0x28]);
  }
  if ((byte)(&DAT_0088a322)[param_1 * 0x28] < (byte)(&DAT_0088a320)[param_1 * 0x28]) {
    do {
      if (3 < (byte)(&DAT_0088a322)[iVar2 * 0x28]) {
        return 1;
      }
      iVar7 = -1;
      iVar6 = 0;
      iVar5 = 0x32;
      param_1 = -1;
      iVar3 = 0;
      do {
        if (iVar7 != -1) goto LAB_004e95d1;
        if ((&DAT_0088a310)[iVar3 + iVar2 * 10] == 0) {
          iVar7 = iVar3;
          param_1 = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      if (iVar7 == -1) {
        return 0;
      }
LAB_004e95d1:
      if ((&DAT_0088a30c)[iVar2 * 0x14] != DAT_007f1914) goto LAB_004e9648;
      if ((&DAT_0088a322)[iVar2 * 0x28] == 0) {
        iVar3 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"ATAT_EDIT");
        iVar7 = iVar7 + iVar2 * 10;
        (&DAT_0088a310)[iVar7] = iVar3;
        if (((iVar3 == 0) || (*(char *)(iVar3 + 0x28b) != '\0')) ||
           ((*(uint *)(iVar3 + 0x1fc) & 0x1000) == 0)) {
          (&DAT_0088a310)[iVar7] = 0;
          goto LAB_004e9646;
        }
        (&DAT_0088a322)[iVar2 * 0x28] = (&DAT_0088a322)[iVar2 * 0x28] + '\x01';
      }
      else {
LAB_004e9646:
        do {
          iVar6 = 0;
LAB_004e9648:
          do {
            if (iVar5 < 1) {
              if (iVar6 == 0) {
                return 0;
              }
              goto LAB_004e9712;
            }
            iVar5 = iVar5 + -1;
            iVar6 = FUN_004e9000(0x40a00000,"spawn");
          } while (iVar6 == 0);
          iVar7 = iVar6 + 0x10;
          iVar3 = FUN_0054fd90(iVar7,&DAT_009250e8,&DAT_009250f4,0,0x3f000000,0);
        } while (((iVar3 != 0) &&
                 (iVar3 = FUN_0054fd90(iVar7,&DAT_00925100,&DAT_0092510c,0,0x3f000000,0), iVar3 != 0
                 )) || ((iVar3 = FUN_0054fd90(iVar7,&DAT_009250e8,&DAT_009250f4,0,0x40200000,0),
                        iVar3 == 0 &&
                        (iVar7 = FUN_0054fd90(iVar7,&DAT_00925100,&DAT_0092510c,0,0x40200000,0),
                        iVar7 == 0))));
LAB_004e9712:
        local_c[2] = 0.0;
        local_c[1] = 0.0;
        fVar8 = (float10)FUN_005b9ef0(&DAT_00802538);
        local_c[0] = (float)((fVar8 + (float10)1.0) * (float10)fVar1 * (float10)8.0);
        uVar4 = FUN_0054fa60();
        FUN_005b3620(local_c,local_c,uVar4);
        pfVar9 = (float *)(iVar6 + 0x10);
        FUN_005b37d0(local_c,local_c,pfVar9);
        if ((&DAT_0088a30c)[iVar2 * 0x14] != DAT_007f1914) {
          pfVar9 = local_c;
        }
        iVar7 = FUN_0043d890((int)(short)(&DAT_0088a30c)[iVar2 * 0x14],pfVar9,
                             *(undefined4 *)(iVar6 + 0x1c),&DAT_0088a323 + iVar2 * 0x28,iVar6 + 0x20
                             ,0,1,0,0,0,0);
        if (iVar7 == 0) {
          return 0;
        }
        (&DAT_0088a310)[param_1 + iVar2 * 10] = iVar7;
        (&DAT_0088a322)[iVar2 * 0x28] = (&DAT_0088a322)[iVar2 * 0x28] + '\x01';
        *(int *)(iVar7 + 0x36c) = iVar6;
      }
    } while ((byte)(&DAT_0088a322)[iVar2 * 0x28] < (byte)(&DAT_0088a320)[iVar2 * 0x28]);
  }
  return 1;
}

