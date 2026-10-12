/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53df20; label: FUN_0053df20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053df20(undefined4 *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  undefined *puVar3;
  short *psVar4;
  int iVar5;
  float *extraout_EDX;
  float *extraout_EDX_00;
  float *pfVar6;
  int iVar7;
  float fVar8;
  int *piVar9;
  float local_110;
  int local_10c;
  undefined4 *local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  local_108 = param_1;
  local_10c = param_2;
  if ((param_2 != 0) && (param_1 != (undefined4 *)0x0)) {
    piVar9 = (int *)*param_1;
    iVar7 = 0;
    do {
      if (*piVar9 == 0) {
        piVar9[0x1f] = 0x3f800000;
        piVar9[0x20] = 0x3f800000;
        piVar9[0x21] = 0x3f800000;
        piVar9[0x22] = 0x3f800000;
        piVar9[0x23] = 0x3f800000;
        piVar9[0x24] = 0x40a00000;
        piVar9[0x25] = 0x40a00000;
        _sprintf((char *)(piVar9 + 0x39),"%.2i",iVar7);
        puVar3 = PTR_s_sock_cam__00801e08;
        piVar9[0x3d] = 0x3f000000;
        _sprintf(local_104,"%s%.2i",puVar3,iVar7);
        psVar4 = (short *)FUN_005d0690(param_2,local_104);
        *piVar9 = (int)psVar4;
        puVar3 = PTR_s_sock_a__00801e0c;
        if (psVar4 == (short *)0x0) {
          FUN_0053db60(local_104);
        }
        else {
          fVar8 = (float)(int)*psVar4;
          local_110 = fVar8;
          if (1 < (int)fVar8) {
            *(short *)(piVar9 + 0xc) = *psVar4 + -1;
            _sprintf(local_104,"%s%.2i",puVar3,iVar7);
            psVar4 = (short *)FUN_005d0690(param_2,local_104);
            piVar9[1] = (int)psVar4;
            if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 == fVar8)) {
              _sprintf(local_104,"%s%.2i",PTR_s_sock_b__00801e10,iVar7);
              psVar4 = (short *)FUN_005d0690(param_2,local_104);
              piVar9[2] = (int)psVar4;
              if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 == fVar8)) {
                _sprintf(local_104,"%s%.2i",PTR_s_sock_c__00801e14,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[3] = (int)psVar4;
                if ((psVar4 == (short *)0x0) || ((float)(int)*psVar4 != fVar8)) {
                  *(ushort *)(piVar9 + 0x1a) = *(ushort *)(piVar9 + 0x1a) | 1;
                }
                if ((*(byte *)(piVar9 + 0x1a) & 1) == 0) {
                  _sprintf(local_104,"%s%.2i",PTR_s_sock_d__00801e18,iVar7);
                  psVar4 = (short *)FUN_005d0690(param_2,local_104);
                  piVar9[4] = (int)psVar4;
                  if ((psVar4 == (short *)0x0) || ((float)(int)*psVar4 != fVar8)) {
                    *(ushort *)(piVar9 + 0x1a) = *(ushort *)(piVar9 + 0x1a) | 1;
                  }
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_mid__00801e1c,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[5] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[5] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_left__00801e20,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[6] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[6] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_right__00801e24,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[7] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[7] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_look__00801e28,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[8] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[8] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_lateral__00801e2c,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[9] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[9] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_trackin__00801e30,iVar7);
                psVar4 = (short *)FUN_005d0690(param_2,local_104);
                piVar9[10] = (int)psVar4;
                if ((psVar4 != (short *)0x0) && ((float)(int)*psVar4 != fVar8)) {
                  piVar9[10] = 0;
                }
                _sprintf(local_104,"%s%.2i",PTR_s_sock_limit__00801e34,iVar7);
                iVar5 = FUN_005d0690(param_2,local_104);
                piVar9[0xb] = iVar5;
                pfVar6 = *(float **)(piVar9[1] + 8);
                pfVar1 = (float *)(piVar9 + 0x13);
                *pfVar1 = *pfVar6;
                piVar9[0x14] = (int)pfVar6[1];
                piVar9[0x15] = (int)pfVar6[2];
                pfVar6 = (float *)(piVar9 + 0x10);
                *pfVar6 = *pfVar1;
                piVar9[0x11] = piVar9[0x14];
                piVar9[0x12] = piVar9[0x15];
                if (0 < (int)local_110) {
                  do {
                    FUN_0053dc00();
                    FUN_0053dc00();
                    pfVar6 = extraout_EDX;
                    if ((*(byte *)(piVar9 + 0x1a) & 1) == 0) {
                      FUN_0053dc00();
                      FUN_0053dc00();
                      pfVar6 = extraout_EDX_00;
                    }
                    local_110 = (float)((int)local_110 + -1);
                    param_2 = local_10c;
                  } while (local_110 != 0.0);
                }
                fVar8 = (*pfVar1 + *pfVar6) * 0.5;
                piVar9[0x16] = (int)fVar8;
                piVar9[0x17] = (int)(((float)piVar9[0x14] + (float)piVar9[0x11]) * 0.5);
                fVar2 = ((float)piVar9[0x12] + (float)piVar9[0x15]) * 0.5;
                piVar9[0x18] = (int)fVar2;
                fVar8 = *pfVar1 - fVar8;
                piVar9[0x19] = (int)fVar8;
                local_110 = (float)piVar9[0x15] - fVar2;
                if (fVar8 <= local_110) {
                  *(undefined1 *)((int)piVar9 + 0x32) = 1;
                  local_108[1] = local_108[1] + 1;
                }
                else {
                  piVar9[0x19] = (int)local_110;
                  *(undefined1 *)((int)piVar9 + 0x32) = 1;
                  local_108[1] = local_108[1] + 1;
                }
              }
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
      piVar9 = piVar9 + 0x4f;
    } while (iVar7 < 0x40);
  }
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

