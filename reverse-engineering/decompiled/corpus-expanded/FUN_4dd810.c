/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd810; label: FUN_004dd810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004dd810(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 extraout_ST1;
  float10 fVar13;
  float local_5c;
  float local_58;
  uint local_50;
  float local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_5c = 0.0;
  iVar9 = 0;
  local_58 = 1.0;
  local_50 = 0xffffffff;
  bVar2 = false;
  bVar3 = false;
  uVar5 = 0xffff;
  if ((param_6 != 0) && (local_4c = 1.0, 0 < param_5)) {
    do {
      iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"spline_id=");
      if (iVar6 == 0) {
        iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"type=");
        if (iVar6 == 0) {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"spline_start=");
          if (iVar6 == 0) {
            iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"spline_end=");
            if (iVar6 == 0) {
              iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"time_factor=");
              if (iVar6 == 0) {
                iVar6 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"pacemaker");
                if (iVar6 == 0) {
                  bVar2 = true;
                }
                else {
                  iVar6 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"damaged");
                  if (iVar6 == 0) {
                    bVar3 = true;
                  }
                }
              }
              else {
                fVar12 = (float10)FUN_005147c0(param_3,iVar6 + 0xc);
                local_4c = (float)fVar12;
              }
            }
            else {
              fVar12 = (float10)FUN_005147c0(param_3,iVar6 + 0xb);
              local_58 = (float)fVar12;
            }
          }
          else {
            fVar12 = (float10)FUN_005147c0(param_3,iVar6 + 0xd);
            local_5c = (float)fVar12;
          }
        }
        else if ((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) {
          bVar4 = (*DAT_00923884)(iVar6 + 5);
          uVar5 = (ushort)bVar4;
          if (bVar4 != 0xff) {
            uVar5 = (*DAT_00923894)(uVar5);
          }
        }
      }
      else {
        FUN_005147c0(param_3,iVar6 + 10);
        local_50 = FUN_006e6b90();
      }
      iVar6 = DAT_00882a6c;
      iVar9 = iVar9 + 1;
    } while (iVar9 < param_5);
    if ((local_50 < 0x20) && (uVar5 != 0xffff)) {
      iVar7 = 0;
      iVar9 = DAT_00882a6c;
      do {
        iVar8 = iVar9;
        if (*(uint *)(iVar8 + 0x524) == local_50) {
          iVar8 = iVar7 * 0x530 + DAT_00882a6c;
          break;
        }
        iVar7 = iVar7 + 1;
        iVar9 = iVar8 + 0x530;
      } while (iVar7 < 0x20);
      fVar12 = (float10)0;
      fVar10 = (float10)local_5c;
      if (fVar12 <= fVar10) {
        if ((float10)1 < fVar10) {
          local_5c = (float)(float10)1;
          fVar10 = (float10)local_5c;
        }
      }
      else {
        local_5c = (float)fVar12;
        fVar10 = (float10)local_5c;
      }
      fVar13 = (float10)1;
      fVar11 = (float10)local_58;
      if (fVar12 <= fVar11) {
        if (fVar13 < fVar11) {
          fVar11 = (float10)(float)fVar13;
        }
      }
      else {
        fVar11 = (float10)(float)fVar12;
      }
      if ((((iVar8 != 0) && (*(int *)(iVar8 + 0x400) != 0)) && (fVar11 != fVar10)) &&
         (iVar9 = FUN_004d94b0(), iVar9 != 0)) {
        *(float *)(iVar9 + 0x84) = (float)extraout_ST1;
        *(ushort *)(iVar9 + 0x88) = uVar5;
        *(undefined4 *)(iVar9 + 0x94) = 1;
        *(int *)(iVar9 + 0x80) = iVar8;
        fVar12 = (float10)*(float *)(iVar6 + 0xb00c) * (float10)local_4c;
        if ((float10)0 < fVar12) {
          fVar13 = ((float10)(float)(extraout_ST0 - extraout_ST1) *
                   (float10)*(float *)(iVar8 + 0x410)) / fVar12;
        }
        *(float *)(iVar9 + 0x7c) = (float)fVar13;
        FUN_0040f450(iVar8,&local_40,(float)(extraout_ST1 * (float10)*(float *)(iVar8 + 0x410)));
        FUN_0040f450(iVar8,&local_30,(_DAT_007f15e0 + local_5c) * *(float *)(iVar8 + 0x410));
        FUN_004d8280();
        *(float *)(iVar9 + 0x30) = local_40;
        *(float *)(iVar9 + 0x34) = local_3c;
        *(float *)(iVar9 + 0x38) = local_38;
        *(undefined4 *)(iVar9 + 0x3c) = local_34;
        local_20 = local_30 - local_40;
        local_1c = local_2c - local_3c;
        local_18 = local_28 - local_38;
        FUN_004d94f0(&local_20,0x3f800000,0);
        *(undefined4 *)(iVar9 + 0x40) = 0;
        *(undefined4 *)(iVar9 + 0x44) = 0;
        *(undefined4 *)(iVar9 + 0x48) = 0;
        *(undefined4 *)(iVar9 + 0x4c) = 0x3f800000;
        *(float *)(iVar9 + 0x50) = local_40;
        *(float *)(iVar9 + 0x54) = local_3c;
        *(float *)(iVar9 + 0x58) = local_38;
        *(float *)(iVar9 + 0x8c) = local_5c;
        *(undefined4 *)(iVar9 + 0x5c) = local_34;
        iVar6 = FUN_0043d890((int)*(short *)(iVar9 + 0x88),iVar8,0,0,0,0,1,0,0,0,0);
        *(int *)(iVar9 + 0x90) = iVar6;
        if (iVar6 != 0) {
          *(uint *)(iVar6 + 0xef4) = *(uint *)(iVar6 + 0xef4) | 0x4000000;
          *(undefined1 *)(*(int *)(iVar9 + 0x90) + 0x107a) = 5;
          if (bVar2) {
            DAT_00882a68 = *(int *)(iVar9 + 0x90);
            *(uint *)(DAT_00882a68 + 0xef4) = *(uint *)(DAT_00882a68 + 0xef4) | 0x20;
          }
          if (bVar3) {
            puVar1 = (uint *)(*(int *)(iVar9 + 0x90) + 0xef4);
            *puVar1 = *puVar1 | 0x8000000;
            return 1;
          }
        }
      }
    }
  }
  return 1;
}

