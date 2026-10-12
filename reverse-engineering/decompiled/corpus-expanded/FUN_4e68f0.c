/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e68f0; label: FUN_004e68f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e68f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_604;
  undefined4 local_600 [384];
  
  _memset(&DAT_00889640,0,0xc00);
  DAT_0088a284 = 0;
  local_604 = FUN_005cf8a0(*(undefined4 *)(param_1 + 0x13c),local_600,"asteroid",0x80,0);
  if (local_604 != 0) {
    if (0 < local_604) {
      puVar6 = local_600;
      do {
        iVar7 = 0;
        if (0 < *(int *)(param_1 + 0x50bc)) {
          iVar9 = 0;
          do {
            FUN_005d0450(*(int *)(param_1 + 0x50c4) + 0x30 + iVar9,puVar6);
            iVar7 = iVar7 + 1;
            iVar9 = iVar9 + 0x100;
          } while (iVar7 < *(int *)(param_1 + 0x50bc));
        }
        iVar9 = FUN_005cfd60(puVar6);
        iVar7 = DAT_0088a284;
        if (iVar9 != 0) {
          uVar1 = puVar6[1];
          uVar2 = puVar6[2];
          iVar9 = DAT_0088a284 * 6;
          (&DAT_00889640)[iVar9] = *puVar6;
          (&DAT_00889644)[iVar7 * 6] = uVar1;
          (&DAT_00889648)[iVar7 * 6] = uVar2;
          iVar9 = FUN_005cfa50(&DAT_00889640 + iVar9);
          iVar5 = 0;
          if ((iVar9 != 0) && (iVar4 = FUN_004f8a70(iVar9,"asteroid_a"), iVar4 == 0)) {
            iVar4 = FUN_004f8a70(iVar9,"asteroid_pop");
            if (iVar4 == 0) {
              iVar4 = FUN_004f8a70(iVar9,"asteroid_b");
              if (iVar4 == 0) {
                iVar9 = FUN_004f8a70(iVar9,"asteroid_c");
                if (iVar9 != 0) {
                  iVar5 = 2;
                }
              }
              else {
                iVar5 = 1;
              }
            }
            else {
              iVar5 = 0;
            }
          }
          iVar5 = (&DAT_00800290)[iVar5];
          iVar9 = (int)(0xffff / (longlong)(iVar5 * 2)) + 1;
          iVar4 = FUN_0054fa60();
          sVar3 = (short)iVar5;
          (&DAT_00889650)[iVar7 * 0xc] = sVar3 - (short)(iVar4 / iVar9);
          iVar5 = FUN_0054fa60();
          DAT_0088a284 = DAT_0088a284 + 1;
          (&DAT_00889652)[iVar7 * 0xc] = sVar3 - (short)(iVar5 / iVar9);
        }
        puVar6 = puVar6 + 3;
        local_604 = local_604 + -1;
      } while (local_604 != 0);
    }
    iVar7 = 0;
    local_604 = 0;
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        iVar5 = DAT_0088a284;
        iVar8 = *(int *)(param_1 + 0x50c8) + iVar7;
        iVar9 = iVar8 + 0xf2;
        iVar4 = 0;
        if (iVar9 == 0) {
LAB_004e6aea:
          (&DAT_0088964c)[iVar5 * 6] = iVar8;
          iVar4 = (&DAT_00800290)[iVar4];
          iVar9 = (int)(0xffff / (longlong)(iVar4 * 2)) + 1;
          iVar8 = FUN_0054fa60();
          sVar3 = (short)iVar4;
          (&DAT_00889650)[iVar5 * 0xc] = sVar3 - (short)(iVar8 / iVar9);
          iVar4 = FUN_0054fa60();
          (&DAT_00889652)[iVar5 * 0xc] = sVar3 - (short)(iVar4 / iVar9);
          iVar4 = FUN_0054fa60();
          DAT_0088a284 = DAT_0088a284 + 1;
          (&DAT_00889654)[iVar5 * 0xc] = sVar3 - (short)(iVar4 / iVar9);
        }
        else {
          iVar4 = FUN_004f8a70(iVar9,"asteroid_a");
          if (iVar4 != 0) {
            iVar4 = 0;
            goto LAB_004e6aea;
          }
          iVar4 = FUN_004f8a70(iVar9,"asteroid_pop");
          if (iVar4 != 0) {
            iVar4 = 0;
            goto LAB_004e6aea;
          }
          iVar9 = FUN_004f8a70(iVar9,"asteroid_mid");
          if (iVar9 != 0) {
            iVar4 = 1;
            goto LAB_004e6aea;
          }
        }
        local_604 = local_604 + 1;
        iVar7 = iVar7 + 0x114;
      } while (local_604 < *(int *)(param_1 + 0x50c0));
    }
  }
  return;
}

