/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465080; label: FUN_00465080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465080(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_50;
  int local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  int aiStack_28 [10];
  
  local_50 = 0.0;
  iVar8 = 0;
  iVar7 = 0;
  local_48 = 0;
  bVar2 = false;
  local_40 = DAT_0093b0cc;
  local_3c = DAT_0093b0d0;
  local_38 = DAT_0093b0d4;
  local_4c = 0;
  if (0 < param_4) {
    do {
      iVar4 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar8 * 4),"Character");
      if (iVar4 != 0) {
        iVar7 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar4 + 10);
      }
      iVar4 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar8 * 4),"range");
      if (iVar4 == 0) {
        iVar4 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar8 * 4),&DAT_0075772c);
        if (iVar4 == 0) {
          iVar4 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar8 * 4),"State");
          if (iVar4 != 0) {
            local_4c = iVar4 + 6;
          }
        }
        else if ((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) {
          cVar3 = (*DAT_00923884)(iVar4 + 5);
          if ((cVar3 != -1) && ((iVar4 = (*DAT_00923894)(cVar3), iVar4 != 0xff && (local_48 < 10))))
          {
            aiStack_28[local_48] = iVar4;
            local_48 = local_48 + 1;
          }
        }
      }
      else {
        fVar9 = (float10)FUN_004f28e0(iVar4 + 6);
        local_50 = (float)fVar9 * (float)fVar9;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_4);
    if ((local_4c == 0) || ((local_48 < 1 && (local_50 <= 0.0)))) {
      if (iVar7 != 0) {
        uVar6 = FUN_00512fc0(local_4c,*(undefined4 *)(iVar7 + 0x2cc));
        *(undefined4 *)(iVar7 + 0x2d8) = uVar6;
      }
    }
    else {
      if (iVar7 != 0) {
        local_40 = *(undefined4 *)(iVar7 + 0x80);
        local_3c = *(undefined4 *)(iVar7 + 0x84);
        local_38 = *(undefined4 *)(iVar7 + 0x88);
      }
      iVar7 = 0;
      if (0 < DAT_0093d500) {
        iVar8 = 0;
        do {
          iVar4 = iVar8 + DAT_0093d504;
          if ((((*(uint *)(iVar4 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0))
             && ((*(uint *)(iVar4 + 0x1f8) & 0x400) != 0)) {
            FUN_005b3800(&local_34,&local_40,iVar4 + 0x5c);
            fVar1 = local_2c * local_2c + local_34 * local_34 + local_30 * local_30;
            if (local_48 == 0) {
              if (fVar1 < local_50) {
                uVar6 = *(undefined4 *)(iVar4 + 0x2cc);
                goto LAB_004652e8;
              }
            }
            else {
              iVar5 = 0;
              if (0 < local_48) {
                do {
                  if ((int)*(short *)(iVar4 + 0x1064) == aiStack_28[iVar5]) {
                    bVar2 = true;
                  }
                  iVar5 = iVar5 + 1;
                } while (iVar5 < local_48);
              }
              if ((bVar2) && (fVar1 < local_50)) {
                uVar6 = *(undefined4 *)(*(int *)(iVar4 + 4) + 4);
LAB_004652e8:
                uVar6 = FUN_00512fc0(local_4c,uVar6);
                *(undefined4 *)(iVar4 + 0x2d8) = uVar6;
              }
            }
          }
          iVar7 = iVar7 + 1;
          iVar8 = iVar8 + 0x10d8;
          if (DAT_0093d500 <= iVar7) {
            return;
          }
        } while( true );
      }
    }
  }
  return;
}

